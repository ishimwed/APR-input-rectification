open Cil
module P = Printf
module L = List
module CM = Common

let mkBuggyQ (f:fundec) (pc:string) c_0 c_1 c_2 c_3 c_4 c_5 c_6 c_7 c_8 c_9 c_10 c_11 =
  let x = makeVarinfo false "x" intType in
  let y = makeVarinfo false "y" intType in
  let z = makeVarinfo false "z" intType in

  let x_new :varinfo = makeLocalVar f "x_new"  intType in
  let x_new_instr = Set(var x_new, BinOp (PlusA,
    BinOp (PlusA, BinOp (Mult, integer c_0, CM.exp_of_vi x, intType),
    BinOp (Mult, integer c_1, CM.exp_of_vi y, intType), intType),
    BinOp (PlusA, BinOp (Mult, integer c_2, CM.exp_of_vi z, intType),
    integer c_3, intType), intType), !currentLoc) in

  let y_new = makeLocalVar f "y_new"  intType in
  let y_new_instr = Set(var y_new, BinOp (PlusA,
    BinOp (PlusA, BinOp (Mult, integer c_4, CM.exp_of_vi x, intType),
    BinOp (Mult, integer c_5, CM.exp_of_vi y, intType), intType),
    BinOp (PlusA, BinOp (Mult, integer c_6, CM.exp_of_vi z, intType),
    integer c_7, intType), intType), !currentLoc) in

  let z_new = makeLocalVar f "z_new"  intType in
  let z_new_instr = Set(var z_new, BinOp (PlusA,
    BinOp (PlusA, BinOp (Mult, integer c_8, CM.exp_of_vi x, intType),
    BinOp (Mult, integer c_9, CM.exp_of_vi y, intType), intType),
    BinOp (PlusA, BinOp (Mult, integer c_10,  CM.exp_of_vi z, intType),
    integer c_11, intType), intType), !currentLoc) in

  let repairs : stmt = mkStmt (Instr [x_new_instr; y_new_instr; z_new_instr]) in
  let x_stmt : stmt = mkStmt (Instr [Set (var x, CM.exp_of_vi x_new, !currentLoc)]) in
  let y_stmt : stmt = mkStmt (Instr [Set (var y, CM.exp_of_vi y_new, !currentLoc)]) in
  let z_stmt : stmt = mkStmt (Instr [Set (var z, CM.exp_of_vi z_new, !currentLoc)]) in
  let t_block : block = mkBlock [repairs; x_stmt; y_stmt; z_stmt] in
  let if1 : stmtkind = If (Const (CStr pc), t_block, mkBlock [], !currentLoc) in
  f.sbody.bstmts <- [mkStmt if1] @ f.sbody.bstmts


let replace input output =
    Str.global_replace (Str.regexp_string input) output

let () = begin
  initCIL();
  Cil.lineDirectiveStyle := None;

  (*Get input from cmd line*)
  let src = Sys.argv.(1) in
  let preproc = (String.sub src 0 (String.index src '.')) ^ ".repair.c" in (*save here*)

  let c_0 = int_of_string Sys.argv.(2) in
  let c_1 = int_of_string Sys.argv.(3) in
  let c_2 = int_of_string Sys.argv.(4) in
  let c_3 = int_of_string Sys.argv.(5) in
  let c_4 = int_of_string Sys.argv.(6) in
  let c_5 = int_of_string Sys.argv.(7) in
  let c_6 = int_of_string Sys.argv.(8) in
  let c_7 = int_of_string Sys.argv.(9) in
  let c_8 = int_of_string Sys.argv.(10) in
  let c_9 = int_of_string Sys.argv.(11) in
  let c_10 = int_of_string Sys.argv.(12) in
  let c_11 = int_of_string Sys.argv.(13) in

  let pc = Sys.argv.(14) in
  let cond = replace "X_" "" pc in

  (*Parse the source file*)
  let ast = Frontc.parse src () in
  let buggyQFd = CM.findFun ast "buggyQ" in
  mkBuggyQ buggyQFd cond c_0 c_1 c_2 c_3 c_4 c_5 c_6 c_7 c_8 c_9 c_10 c_11;

  ast.globals <- (GText "#include \"klee/klee.h\"") :: ast.globals;
  ast.globals <- (GText "#include <stdio.h>") :: ast.globals;

  CM.writeSrc preproc ast;

end
