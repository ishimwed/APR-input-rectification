open Cil
module P = Printf
module L = List
module CM = Common

let mkMainQ (f:fundec) c_0 c_1 c_2 c_3 c_4 c_5 c_6 c_7 c_8 c_9 c_10 c_11 =
  let x = CM.exp_of_vi (makeVarinfo false "x" intType) in
  let y = CM.exp_of_vi (makeVarinfo false "y" intType) in
  let z = CM.exp_of_vi (makeVarinfo false "z" intType) in

  let x_new :varinfo = makeLocalVar f "x_new"  intType in
  let x_new_instr = Set(var x_new, BinOp (PlusA,
    BinOp (PlusA, BinOp (Mult, integer c_0, x, intType),
    BinOp (Mult, integer c_1, y, intType), intType),
    BinOp (PlusA, BinOp (Mult, integer c_2, z, intType),
    integer c_3, intType), intType), !currentLoc) in

  let y_new = makeLocalVar f "y_new"  intType in
  let y_new_instr = Set(var y_new, BinOp (PlusA,
    BinOp (PlusA, BinOp (Mult, integer c_4, x, intType),
    BinOp (Mult, integer c_5, y, intType), intType),
    BinOp (PlusA, BinOp (Mult, integer c_6, z, intType),
    integer c_7, intType), intType), !currentLoc) in

  let z_new = makeLocalVar f "z_new"  intType in
  let z_new_instr = Set(var z_new, BinOp (PlusA,
    BinOp (PlusA, BinOp (Mult, integer c_8, x, intType),
    BinOp (Mult, integer c_9, y, intType), intType),
    BinOp (PlusA, BinOp (Mult, integer c_10,  z, intType),
    integer c_11, intType), intType), !currentLoc) in

  let rb = makeVarinfo false "rb"  intType in
  let rc = makeVarinfo false "rc"  intType in
  let rb_instr: instr = CM.mkCall ~ftype:intType ~av:(Some (var rb)) "buggyQ" [x; y; z] in
  let rc_instr: instr = CM.mkCall ~ftype:intType ~av:(Some (var rc)) "correctQ" [x; y; z] in

  let cond = BinOp (Ne, CM.exp_of_vi rb, CM.exp_of_vi rc, intType) in
  let print : instr = CM.mkCall "printf" [Const (CStr "FAIL with inputs: x %d y %d z %d \n"); x; y; z] in
  let true_block: block = mkBlock [mkStmt (Instr [print])] in
  let if2 : stmtkind = If (cond, true_block, mkBlock [], !currentLoc) in
  let tests : stmt = mkStmt (Instr [x_new_instr; y_new_instr; z_new_instr]) in
  let t_block : block = mkBlock [tests; (mkStmt if2)] in
  let if1 : stmtkind = If (cond, t_block, mkBlock [], !currentLoc) in
  let return  = mkStmt (Instr [CM.mkCall "return" [integer 0]]) in
  f.sbody.bstmts <- [mkStmt (Instr [rb_instr; rc_instr]); mkStmt if1; return]

let () = begin
  initCIL();
  Cil.lineDirectiveStyle := None;

  (*Get input from cmd line*)
  let src = Sys.argv.(1) in
  let preproc = (String.sub src 0 (String.index src '.')) ^ ".test.c" in (*save here*)

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
  (*Parse the source file*)
  let ast = Frontc.parse src () in
  let mainQFd = CM.findFun ast "mainQ" in
  mkMainQ mainQFd c_0 c_1 c_2 c_3 c_4 c_5 c_6 c_7 c_8 c_9 c_10 c_11;
  (* visitCilFileSameGlobals (new mainQVisitor c_0 c_1 c_2 c_3 c_4 c_5 c_6 c_7 c_8 c_9 c_10 c_11) ast; *)

  ast.globals <- (GText "#include \"klee/klee.h\"") :: ast.globals;
  ast.globals <- (GText "#include <stdio.h>") :: ast.globals;

  CM.writeSrc preproc ast;

end
