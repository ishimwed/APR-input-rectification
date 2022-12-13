import z3
import sys

c_0, c_1, c_2, c_3, c_4, c_5, c_6, c_7, c_8, c_9, c_10, c_11 = z3.Ints('c_0 c_1 c_2 c_3 c_4 c_5 c_6 c_7 c_8 c_9 c_10 c_11')
pc = sys.argv[1]
f = z3.And(pc)
solver = z3.Solver()
solver.add(f)
solver.check()
print (solver.model())
