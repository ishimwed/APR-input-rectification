open Cil
module E = Errormsg
module P = Printf
module L = List
module CM = Common


class repairVisitor (x:int) (y:int) (z:int) = object(self)
  inherit nopCilVisitor

  method private create_repair_stmts (f: fundec): stmt =
    let l = [0;1;2;3;4;5;6;7;8;9;10;11] in
    let coes = L.map (fun i ->
      var (CM.mkVi ~ftype:intType ("c_" ^ string_of_int i))) l in

    let x_new :varinfo = makeLocalVar f "x_new"  intType in
    let x_new_instr = Set(var x_new, BinOp (PlusA,
      BinOp (PlusA, BinOp (Mult, Lval (L.nth coes 0), integer x, intType),
      BinOp (Mult, Lval (L.nth coes 1), integer y, intType), intType),
      BinOp (PlusA, BinOp (Mult, Lval (L.nth coes 2), integer z, intType),
      Lval (L.nth coes 3), intType), intType), !currentLoc) in

    let y_new = makeLocalVar f "y_new"  intType in
    let y_new_instr = Set(var y_new, BinOp (PlusA,
      BinOp (PlusA, BinOp (Mult, Lval (L.nth coes 4), integer x, intType),
      BinOp (Mult, Lval (L.nth coes 5), integer y, intType), intType),
      BinOp (PlusA, BinOp (Mult, Lval (L.nth coes 6), integer z, intType),
      Lval (L.nth coes 7), intType), intType), !currentLoc) in

    let z_new = makeLocalVar f "z_new"  intType in
    let z_new_instr = Set(var z_new, BinOp (PlusA,
      BinOp (PlusA, BinOp (Mult, Lval (L.nth coes 8), integer x, intType),
      BinOp (Mult, Lval (L.nth coes 9), integer y, intType), intType),
      BinOp (PlusA, BinOp (Mult, Lval (L.nth coes 10), integer z, intType),
      Lval (L.nth coes 11), intType), intType), !currentLoc) in

    let tmp3 = makeLocalVar f "rb1"  intType in
    let args = [CM.exp_of_vi x_new; CM.exp_of_vi y_new; CM.exp_of_vi z_new] in
    let rb_new = CM.mkCall ~ftype:intType ~av:(Some (var tmp3)) "buggyQ" args in
    let tmp4 = makeLocalVar f "rc1"  intType in
    let rc_new = CM.mkCall ~ftype:intType ~av:(Some (var tmp4)) "correctQ" [integer x; integer y; integer z] in

    f.slocals <- [x_new; y_new; z_new; tmp3; tmp4];
    mkStmt (Instr [x_new_instr; y_new_instr; z_new_instr; rb_new; rc_new])

  method private create_if_block (f:fundec) : stmt =

    let tmp3 = makeLocalVar f "rb1"  intType in
    let tmp4 = makeLocalVar f "rc1"  intType in
    let pc: instr = CM.mkCall "$pathCondition" [] in
    let assertion: instr = CM.mkCall "$assert" [integer 0] in
    let true_block: block = mkBlock [mkStmt (Instr [pc; assertion])] in
    let pcBlock: stmtkind = If (BinOp (Eq, CM.exp_of_vi tmp3, CM.exp_of_vi tmp4, intType), true_block, mkBlock [], !currentLoc) in
    mkStmt pcBlock

    method vfunc (f: fundec) =
      (* let return = CM.mkCall "return" [0] in *)
      let action (f: fundec) : fundec =
        if f.svar.vname = "mainQ" then( f.sbody.bstmts <- [self#create_repair_stmts f; self#create_if_block f] );
        f in
        ChangeDoChildrenPost(f, action)

end



let mkMain mainFd mainQFd =


  let mainQTyp:typ = match mainQFd.svar.vtype with
    |TFun(t,_,_,_) -> t
    |_ -> E.s(E.error "%s is not fun typ %a\n"
		      mainQFd.svar.vname d_type mainQFd.svar.vtype)
  in

  (*mainQTyp temp;*)
  let tmp:lval = var(makeTempVar mainFd mainQTyp) in
  let icall = CM.mkCall ~ftype:mainQTyp ~av:(Some tmp) "mainQ" [] in
  let stmt2:stmtkind = Instr([icall]) in

  let stmts = [mkStmt stmt2] in
  mainFd.sbody.bstmts <- stmts

(* main *)
let () = begin
    initCIL();
    Cil.lineDirectiveStyle:= None; (*reduce code, remove all junk stuff*)
    Cprint.printLn := false;
    Cil.useLogicalOperators := true;

    let src:string = Sys.argv.(1) in
    let inst = (String.sub src 0 (String.index src '.')) ^ ".instr.c" in (*save to this file*)

    let x : int = int_of_string Sys.argv.(2) in
    let y : int = int_of_string Sys.argv.(2) in
    let z : int = int_of_string Sys.argv.(3) in


    let ast = Frontc.parse src () in

    ast.globals <- (GText "$input int c_0, c_1, c_2, c_3, c_4, c_5, c_6, c_7, c_8, c_9, c_10, c_11;") :: ast.globals;
    ast.globals <- (GText "#include <stdio.h>") :: ast.globals;
    ast.globals <- (GText "#include <civlc.cvh>") :: ast.globals;

    let mainFd = CM.findFun ast "main" in
    let mainQFd = CM.findFun ast "mainQ" in

    visitCilFileSameGlobals (new repairVisitor x y z) ast;
    (* transform *)
    mkMain mainFd mainQFd;
    setFormals mainQFd [];

    CM.writeSrc inst ast
end
