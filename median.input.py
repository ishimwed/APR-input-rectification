import z3

c_0, c_1, c_2, c_3, c_4, c_5, c_6, c_7, c_8, c_9, c_10, c_11, x, y, z = z3.Ints('c_0 c_1 c_2 c_3 c_4 c_5 c_6 c_7 c_8 c_9 c_10 c_11 x y z')
f1 = z3.And((c_0<=10), (c_0>=-10), (c_1<=10), (c_1>=-10), (c_2<=10), (c_2>=-10), (c_3<=10), (c_3>=-10), (c_4<=10), (c_4>=-10),
(c_5<=10), (c_5>=-10), (c_6<=10), (c_6>=-10), (c_7<=10), (c_7>=-10), (c_8<=10), (c_8>=-10), (c_9<=10), (c_9>=-10), (c_10<=10),
(c_10>=-10), (c_11<=10), (c_11>=-10))

f = z3.And(f1, (0==(21*c_4 + 22*c_5 - 490*c_6 - 1*c_7 - 21)),
  (0==(488*c_4 + 489*c_5 + c_7 - 488)),
  (z3.Or((((21*c_0)+(22*c_1)+(490*c_10)+c_11+(-490*c_2)+(-1*c_3)+(-21*c_8)+(-22*c_9))<=0), (((21*c_0)+(22*c_1)+(-490*c_2)+(-1*c_3)+(-21*c_4)+(-22*c_5)+(490*c_6)+c_7)<=0))),
  (z3.Or((((21*c_0)+(22*c_1)+(-490*c_2)+(-1*c_3)+(-21*c_4)+(-22*c_5)+(490*c_6)+c_7)<=0), (0<=((490*c_10)+c_11+(21*c_4)+(22*c_5)+(-490*c_6)+(-1*c_7)+(-21*c_8)+(-22*c_9))))),
  (z3.Or((((488*c_0)+(489*c_1)+(-1*c_11)+c_3+(-488*c_8)+(-489*c_9))<=0), (((488*c_0)+(489*c_1)+c_3+(-488*c_4)+(-489*c_5)+(-1*c_7))<=0))),
  (z3.Or((((488*c_0)+(489*c_1)+c_3+(-488*c_4)+(-489*c_5)+(-1*c_7))<=0), ((c_11+(-488*c_4)+(-489*c_5)+(-1*c_7)+(488*c_8)+(489*c_9))<=0))),
  (z3.Or((((490*c_10)+c_11+(21*c_4)+(22*c_5)+(-490*c_6)+(-1*c_7)+(-21*c_8)+(-22*c_9))<=0), (0<=((21*c_0)+(22*c_1)+(-490*c_2)+(-1*c_3)+(-21*c_4)+(-22*c_5)+(490*c_6)+c_7)))),
  (z3.Or((0<=((21*c_0)+(22*c_1)+(490*c_10)+c_11+(-490*c_2)+(-1*c_3)+(-21*c_8)+(-22*c_9))), (0<=((21*c_0)+(22*c_1)+(-490*c_2)+(-1*c_3)+(-21*c_4)+(-22*c_5)+(490*c_6)+c_7)))),
  (z3.Or((0<=((488*c_0)+(489*c_1)+(-1*c_11)+c_3+(-488*c_8)+(-489*c_9))), (0<=((488*c_0)+(489*c_1)+c_3+(-488*c_4)+(-489*c_5)+(-1*c_7))))),
  (z3.Or((0<=((488*c_0)+(489*c_1)+c_3+(-488*c_4)+(-489*c_5)+(-1*c_7))), (0<=(c_11+(-488*c_4)+(-489*c_5)+(-1*c_7)+(488*c_8)+(489*c_9))))))

solver = z3.Solver()
solver.add(f)
solver.check()
print (solver.model())