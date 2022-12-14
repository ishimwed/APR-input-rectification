import z3

c_0, c_1, c_2, c_3, c_4, c_5, c_6, c_7, c_8, c_9, c_10, c_11, x, y, z = z3.Ints('c_0 c_1 c_2 c_3 c_4 c_5 c_6 c_7 c_8 c_9 c_10 c_11 x y z')
f1 = z3.And((c_0<=10), (c_0>=-10), (c_1<=10), (c_1>=-10), (c_2<=10), (c_2>=-10), (c_3<=10), (c_3>=-10), (c_4<=10), (c_4>=-10),
(c_5<=10), (c_5>=-10), (c_6<=10), (c_6>=-10), (c_7<=10), (c_7>=-10), (c_8<=10), (c_8>=-10), (c_9<=10), (c_9>=-10), (c_10<=10),
(c_10>=-10), (c_11<=10), (c_11>=-10))

f = z3.And(f1, (0==(3*c_0 + 2*c_1 + c_2 - 1*c_3 - 1)),
  (0==(9*c_0 - 38*c_1 - 81*c_2 - 1*c_3 + 81)),
  (0==(25*c_0 - 38*c_1 - 69*c_2 - 1*c_3 + 69)),
  (0==(98*c_0 + 98*c_1 + 23*c_2 - 1*c_3 - 23)),
  (0==(99*c_0 + 99*c_1 - 1*c_3)),
  (0==(258*c_0 + 320*c_1 + 512*c_2 + c_3 - 512)),
  (0==(896*c_0 - 95*c_1 - 126*c_2 - 1*c_3 + 126)),
  (0==(929*c_0 + 929*c_1 + 928*c_2 - 1*c_3 - 928)),
  (0==(992*c_0 + 696*c_1 + 640*c_2 - 1*c_3 - 640)),
  (0==(5*c_1 + 6*c_2 + c_3 - 6)),
  (0==(10*c_1 + 20*c_2 + c_3 - 20)),
  (((3*c_0)+(2*c_1)+c_2+(-1*c_3)+(-3*c_4)+(-2*c_5)+(-1*c_6)+c_7+1)<=0),
  (((9*c_0)+(-38*c_1)+(-81*c_2)+(-1*c_3)+(-9*c_4)+(38*c_5)+(81*c_6)+c_7+1)<=0),
  (((25*c_0)+(-38*c_1)+(-69*c_2)+(-1*c_3)+(-25*c_4)+(38*c_5)+(69*c_6)+c_7+1)<=0),
  (((98*c_0)+(98*c_1)+(23*c_2)+(-1*c_3)+(-98*c_4)+(-98*c_5)+(-23*c_6)+c_7+1)<=0),
  (((99*c_0)+(99*c_1)+(-1*c_3)+(-99*c_4)+(-99*c_5)+c_7+1)<=0),
  (((896*c_0)+(-95*c_1)+(-126*c_2)+(-1*c_3)+(-896*c_4)+(95*c_5)+(126*c_6)+c_7+1)<=0),
  (((929*c_0)+(929*c_1)+(928*c_2)+(-1*c_3)+(-929*c_4)+(-929*c_5)+(-928*c_6)+c_7+1)<=0),
  (((992*c_0)+(696*c_1)+(640*c_2)+(-1*c_3)+(-992*c_4)+(-696*c_5)+(-640*c_6)+c_7+1)<=0),
  (((6*c_10)+c_11+(-5*c_5)+(-6*c_6)+(-1*c_7)+(5*c_9)+1)<=0),
  (((20*c_10)+c_11+(-10*c_5)+(-20*c_6)+(-1*c_7)+(10*c_9)+1)<=0),
  (((69*c_10)+c_11+(25*c_4)+(-38*c_5)+(-69*c_6)+(-1*c_7)+(-25*c_8)+(38*c_9)+1)<=0),
  (((81*c_10)+c_11+(9*c_4)+(-38*c_5)+(-81*c_6)+(-1*c_7)+(-9*c_8)+(38*c_9)+1)<=0),
  (((126*c_10)+c_11+(896*c_4)+(-95*c_5)+(-126*c_6)+(-1*c_7)+(-896*c_8)+(95*c_9)+1)<=0),
  (((512*c_10)+c_11+(-258*c_4)+(-320*c_5)+(-512*c_6)+(-1*c_7)+(258*c_8)+(320*c_9)+1)<=0),
  ((c_11+(99*c_4)+(99*c_5)+(-1*c_7)+(-99*c_8)+(-99*c_9)+1)<=0),
  (0<=((258*c_0)+(320*c_1)+(512*c_2)+c_3+(-258*c_4)+(-320*c_5)+(-512*c_6)+(-1*c_7)-1)),
  (0<=((5*c_1)+(6*c_2)+c_3+(-5*c_5)+(-6*c_6)+(-1*c_7)-1)),
  (0<=((10*c_1)+(20*c_2)+c_3+(-10*c_5)+(-20*c_6)+(-1*c_7)-1)),
  (0<=(c_10+(-1*c_11)+(-3*c_4)+(-2*c_5)+(-1*c_6)+c_7+(3*c_8)+(2*c_9)-1)),
  (0<=((23*c_10)+(-1*c_11)+(-98*c_4)+(-98*c_5)+(-23*c_6)+c_7+(98*c_8)+(98*c_9)-1)),
  (0<=((640*c_10)+(-1*c_11)+(-992*c_4)+(-696*c_5)+(-640*c_6)+c_7+(992*c_8)+(696*c_9)-1)),
  (0<=((928*c_10)+(-1*c_11)+(-929*c_4)+(-929*c_5)+(-928*c_6)+c_7+(929*c_8)+(929*c_9)-1)))

solver = z3.Solver()
solver.add(f)
solver.check()
print (solver.model())
