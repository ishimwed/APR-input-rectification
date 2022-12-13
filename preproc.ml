open Cil
module P = Printf
module L = List
module CM = Common

class mainQVisitor = object(self)
  inherit nopCilVisitor

  method private create_rb_rc (f:fundec) : stmt =

  let x = CM.exp_of_vi (makeVarinfo false "x" intType) in
  let y = CM.exp_of_vi (makeVarinfo false "y" intType) in
  let z = CM.exp_of_vi (makeVarinfo false "z" intType) in

  let tmp3 = makeLocalVar f "rb"  intType in
  let tmp4 = makeLocalVar f "rc"  intType in
  let rb = CM.mkCall ~ftype:intType ~av:(Some (var tmp3)) "buggyQ" [x; y; z] in
  let rc = CM.mkCall ~ftype:intType ~av:(Some (var tmp4)) "correctQ" [x; y; z] in
  mkStmt (Instr [rb; rc])

  method private create_if_block (f:fundec) : stmt =

    let tmp3 = makeVarinfo false "rb"  intType in
    let tmp4 = makeVarinfo false "rc"  intType in
    let pc: instr = CM.mkCall "$pathCondition" [] in
    let true_block: block = mkBlock [mkStmt (Instr [pc])] in
    let pcBlock: stmtkind = If (BinOp (Ne, CM.exp_of_vi tmp3, CM.exp_of_vi tmp4, intType), true_block, mkBlock [], !currentLoc) in
    mkStmt pcBlock

  method vfunc (f: fundec) =
    (* let return = CM.mkCall "return" [0] in *)
    let action (f: fundec) : fundec =
      if f.svar.vname = "mainQ" then( f.slocals <- [];
        f.sbody.bstmts <- [self#create_rb_rc f; self#create_if_block f]
         );
      f in
      ChangeDoChildrenPost(f, action)

  (* method vfunc (fd: fundec) =
    let action (fd: fundec) : fundec =
        if fd.svar.vname = "mainQ" then ( (*make this more robust: mainQ should be input*)
          let pcCall : instr = CM.mkCall "$pathCondition" [] in
          let pcStmt : stmt = mkStmt (Instr[pcCall]) in
          let continue : stmt = mkStmt (Continue !currentLoc) in
          let insert_stmt (s:stmt) =
            match s.skind with
            |If(_,b1,b2,_) -> (b1.bstmts <- [continue]; b2.bstmts <- [pcStmt])
            |_ -> ()
            in L.hd (L.map insert_stmt fd.sbody.bstmts)
            (* fd.sbody.bstmts <- fd.sbody.bstmts @ [continue] *)
        );
        fd in
        ChangeDoChildrenPost(fd, action) *)
end


let () = begin
  initCIL();
  Cil.lineDirectiveStyle := None;

  (*Get input from cmd line*)
  let src = Sys.argv.(1) in
  let preproc = (String.sub src 0 (String.index src '.')) ^ ".preproc.c" in (*save here*)

  (*Parse the source file*)
  let ast = Frontc.parse src () in

  let mainFd:fundec = CM.findFun ast "main" in

  let x : exp = CM.exp_of_vi (makeVarinfo false "x" intType) in
  let y : exp = CM.exp_of_vi (makeVarinfo false "y" intType) in
  let z : exp = CM.exp_of_vi (makeVarinfo false "z" intType) in
  let mainQCall : instr = CM.mkCall "mainQ" [x; y; z] in (*make this more robust: mainQ should be input*)
  mainFd.sbody.bstmts <- [mkStmt (Instr [mainQCall])];
  mainFd.slocals <- [];

  visitCilFileSameGlobals (new mainQVisitor) ast;

  ast.globals <- (GText "$input int x, y, z;") :: ast.globals;
  ast.globals <- (GText "#include <stdio.h>") :: ast.globals;
  ast.globals <- (GText "#include <civlc.cvh>") :: ast.globals;

  CM.writeSrc preproc ast;

end
