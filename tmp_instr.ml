
open Cil
module E = Errormsg
module H = Hashtbl
module P = Printf
module L = List
module CM = Common

class mainVisitor = object(self)
  inherit nopCilVisitor

  method private create_pc_stmt : stmt =
  let str = "$false" in
  let instr1 = CM.mkCall "$pathCondition" [] in
  let instr2 = CM.mkCall "$assert" [Const (CStr(str))] in
  mkStmt (Instr([instr1; instr2]))

  (*Delete the return stmt*)
  (*not necessary if i can insert the pc stmt before the return*)
  method vstmt (s:stmt) =
    match s.skind with
    | Return(lvopt,loc) -> ChangeTo(mkStmt (Instr []))
    |_ -> SkipChildren

  method vfunc f =
    let action (f: fundec) : fundec =
      if f.svar.vname = "main" then (
        let tmp = var (makeTempVar f intType) in
        let rc = var (CM.mkVi ~ftype:intType "rc") in
        let rb = var (CM.mkVi ~ftype:intType "rb") in
        let e = BinOp(Eq, Lval rc, Lval rb, intType) in
        let i = Set(tmp, e, !currentLoc) in
        let s = mkStmt (Instr ([i])) in
        let blck = mkBlock [self#create_pc_stmt] in
        let condi = mkStmt (If(Lval tmp, blck, mkBlock [], !currentLoc)) in
        f.sbody.bstmts <- f.sbody.bstmts @ [s; condi]
        );
        f
        in
        ChangeDoChildrenPost(f, action)

  end

let remove_xyz (g:global) =
  match g with
  | GVarDecl (v,loc) -> false
  | _ -> true

let () = begin
  initCIL();
  Cil.lineDirectiveStyle := None;
  Cprint.printLn := false;
  Cil.useLogicalOperators := true;

  let flSrc:string = Sys.argv.(1) in (*save ti this file*)
  let astFile:string = Sys.argv.(2) in (*read from this bin file*)
  let ast,_,_,_,_,_ = CM.read_file_bin astFile in

  (* ast.globals <- (GText "$input int e0, e1, e2, e3;") :: ast.globals;
  ast.globals <- (GText "$input int d0, d1, d2, d3;") :: ast.globals;
  ast.globals <- (GText "$input int c0, c1, c2, c3;") :: ast.globals; *)
  ast.globals <- (GText "$input int x, y, z;") :: ast.globals;
  ast.globals <- (GText "#include <civlc.cvh>") :: ast.globals;

  ast.globals <- L.filter remove_xyz ast.globals;
  visitCilFileSameGlobals (new mainVisitor) ast;

  CM.writeSrc flSrc ast;
end

class mainQVisitor = object (self)
  inherit nopCilVisitor

  method private create_if_block (mainQFd:fundec) : stmt =
    let coes = L.map (fun v -> CM.expOfVi v)
                (L.tl (L.tl (L.tl mainQFd.sformals))) in

    let str : string = "PASS with coeficients: %d %d %d %d %d %d %d %d %d %d %d %d\n" in
    let args = [Const (CStr(str))] @ coes in
    let prnt = CM.mkCall "printf" args in
    let true_block : block = mkBlock [mkStmt (Instr [prnt])] in

    (*change this to use sformals instead*)
    let x : exp = CM.exp_of_vi (makeVarinfo true "x" intType) in
    let y : exp = CM.exp_of_vi (makeVarinfo true "y" intType) in
    let z : exp = CM.exp_of_vi (makeVarinfo true "z" intType) in
    let str1 = "FAIL with input: x %d, y %d, z %d\n" in
    let prnt1 = CM.mkCall "printf" [Const (CStr(str1)); x; y; z] in
    let false_block : block = mkBlock [mkStmt (Instr [prnt1])] in

    let cond: varinfo = makeLocalVar mainQFd "cond" intType in
    let tmp : stmtkind = If (CM.expOfVi cond, true_block, false_block, !currentLoc) in
    mkStmt tmp

  method vfunc (f: fundec) =
    let action (f: fundec) : fundec =
      if f.svar.vname = "mainQ" then(
      let cond = makeVarinfo false "cond" intType in
      let condinstr: instr = Set(var cond, integer 1, !currentLoc) in
      let condstmt = mkStmt (Instr[condinstr]) in
      let insert_stmts (s:stmt) =
        match s.skind with
        |If(_,_,b,_) -> b.bstmts <- [condstmt; self#create_if_block f]
        | _ -> ()
        in L.hd (L.map insert_stmts f.sbody.bstmts)
        );
        f in
      ChangeDoChildrenPost(f, action)
end

let mkMainQ mainQFd =
  let l = [0;1;2;3;4;5;6;7;8;9;10;11] in
  let formals = L.map (fun i ->
    makeVarinfo true ("c_" ^ string_of_int i) intType) l in
    setFormals mainQFd (L.append mainQFd.sformals formals)


    let uks = L.mapi(fun i vi ->
        let v, i = CM.mkUk i vi.vtype (-1*maxV) maxV mainFd in
        CM.exp_of_vi v, i
        ) mainQFd.sformals in

    let l = [0;1;2;3;4;5;6;7;8;9;10;11] in
    let coes = L.mapi(fun i vi ->
        let c, i = CM.mkCoe i intType (-1*maxV) maxV mainFd in
        CM.exp_of_vi c, i
        ) l in
    let args1, instrs1 = L.split uks in
    let args2, instrs2 = L.split coes in
    let instrs1 = L.flatten instrs1 in
    let instrs2 = L.flatten instrs2 in
    let args = L.append args1 args2 in
    let instrs = L.append instrs1 instrs2 in
    let stmt1:stmtkind = Instr(instrs) in
