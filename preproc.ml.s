open Cil
module H = Hashtbl
module P = Printf
module L = List
module CM = Common

let () = begin
  initCIL();
  Cil.lineDirectiveStyle := None;

  (*Get input from cmd line*)
  let src = Sys.argv.(1) in
  let mainQName = Sys.argv.(2) in
  let correctQName = Sys.argv.(3) in
  let preprocSrc = Sys.argv.(4) in
  let astFile = Sys.argv.(5) in

  (*Parse the source file*)
  let ast = Frontc.parse src () in

  (*Makes ever instr into its own stmt and makes every condition a side effect free variable*)
  visitCilFileSameGlobals (new CM.everyVisitor) ast;
  visitCilFileSameGlobals (new CM.breakCondVisitor :> cilVisitor) ast;

  let mainFd:fundec = CM.findFun ast "main" in
  let mainQFd:fundec = CM.findFun ast mainQName in
  let correctQName:fundec = CM.findFun ast correctQName in

  (*set of [main; mainQname; correctQName]*)
  let ignoreFuns:CM.SS.t =
    L.fold_right CM.SS.add ["main" ; mainQName; correctQName] CM.SS.empty in

  (*Add stmt id*)
  let stmtHt = H.create 1024 in
  visitCilFileSameGlobals (new CM.numVisitor stmtHt ignoreFuns :> cilVisitor) ast;

  CM.writeSrc preprocSrc ast;
  CM.write_file_bin astFile (ast, mainFd, mainQFd, correctQFd, stmtHt)

end
