OCAML_OPTIONS = \
  -I /home/dishimwe/dishimwe/cil/_build/src \
  -I /home/dishimwe/dishimwe/cil/_build/src/frontc \
  -I /home/dishimwe/dishimwe/cil/_build/src/ocamlutil

CAMLC =        ocamlc                          $(OCAML_OPTIONS)
OCAMLOPT =      ocamlopt                        $(OCAML_OPTIONS)
OCAMLDEP =      ocamldep                        $(OCAML_OPTIONS)
OCAMLLEX =      ocamllex

all:  preproc.exe instr.exe modify.exe test.exe repair.exe

%.cmo: %.ml
	@if [ -f $*.mli -a ! -f $*.cmi ] ; then $(OCAMLC) -c -g $*.mli ; fi
	$(OCAMLC) -c -g $*.ml
	@$(OCAMLDEP) $*.ml > $*.d

%.cmx: %.ml
	@if [ -f $*.mli -a ! -f $*.cmi ] ; then $(OCAMLC) -c -g $*.mli ; fi
	$(OCAMLOPT) -c $*.ml
	@$(OCAMLDEP) $*.ml > $*.d

%.cmi: %.mli
	$(OCAMLC) -c -g $*.mli

%.ml: %.mll
	$(OCAMLLEX) $*.mll


PREPROC_MODULES = \
	common.cmo \
	preproc.cmo \

preproc.exe: $(PREPROC_MODULES:.cmo=.cmx)
		$(OCAMLOPT) -o $@ unix.cmxa str.cmxa nums.cmxa cil.cmxa $^

TEST_MODULES = \
	common.cmo \
	test.cmo \

test.exe: $(TEST_MODULES:.cmo=.cmx)
		$(OCAMLOPT) -o $@ unix.cmxa str.cmxa nums.cmxa cil.cmxa $^

REPAIR_MODULES = \
	common.cmo \
	repair.cmo \

repair.exe: $(REPAIR_MODULES:.cmo=.cmx)
		$(OCAMLOPT) -o $@ unix.cmxa str.cmxa nums.cmxa cil.cmxa $^

INSTR_MODULES = \
	common.cmo \
	instr.cmo \

instr.exe: $(INSTR_MODULES:.cmo=.cmx)
	$(OCAMLOPT) -o $@ unix.cmxa str.cmxa nums.cmxa cil.cmxa $^

MODIFY_MODULES = \
	common.cmo \
	modify.cmo \

modify.exe: $(MODIFY_MODULES:.cmo=.cmx)
	$(OCAMLOPT) -o $@ unix.cmxa str.cmxa nums.cmxa cil.cmxa $^

clean:
	rm -f *.cmo *.cmi *.d *.cmx *.dx *.o *.exe
