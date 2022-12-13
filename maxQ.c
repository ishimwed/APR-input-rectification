#include <stdio.h>
int buggyQ(int x , int y , int z )
{
  int __cil_tmp4 ;
  int __cil_tmp5 ;
  int __cil_tmp6 ;
  int __cil_tmp7 ;
  int __cil_tmp8 ;
  int __cil_tmp9 ;
  int __cil_tmp10 ;
  int __cil_tmp11 ;
  int __cil_tmp12 ;
  int __cil_tmp13 ;
  int __cil_tmp14 ;
  int __cil_tmp15 ;
  int __cil_tmp16 ;
  int __cil_tmp17 ;
  int __cil_tmp18 ;
  int __cil_tmp19 ;
  int __cil_tmp20 ;
  int __cil_tmp21 ;
  int __cil_tmp22 ;
  int __cil_tmp23 ;
  int __cil_tmp24 ;
  int __cil_tmp25 ;
  int __cil_tmp26 ;
  int __cil_tmp27 ;
  int __cil_tmp28 ;
  int __cil_tmp29 ;
  int __cil_tmp30 ;
  int __cil_tmp31 ;
  int __cil_tmp32 ;
  int __cil_tmp33 ;
  int __cil_tmp34 ;
  int __cil_tmp35 ;
  int __cil_tmp36 ;

  {
  __cil_tmp14 = x > y;
  __cil_tmp25 = __cil_tmp14;
  __cil_tmp36 = __cil_tmp25;
  if (__cil_tmp36) {
    __cil_tmp8 = y > z;
    __cil_tmp19 = __cil_tmp8;
    __cil_tmp30 = __cil_tmp19;
    if (__cil_tmp30) {
      __cil_tmp4 = x;
      __cil_tmp15 = __cil_tmp4;
      __cil_tmp26 = __cil_tmp15;
      return (__cil_tmp26);
    } else {
      __cil_tmp7 = x > z;
      __cil_tmp18 = __cil_tmp7;
      __cil_tmp29 = __cil_tmp18;
      if (__cil_tmp29) {
        __cil_tmp5 = x;
        __cil_tmp16 = __cil_tmp5;
        __cil_tmp27 = __cil_tmp16;
        return (__cil_tmp27);
      } else {
        __cil_tmp6 = z;
        __cil_tmp17 = __cil_tmp6;
        __cil_tmp28 = __cil_tmp17;
        return (__cil_tmp28);
      }
    }
  } else {
    __cil_tmp13 = x > z;
    __cil_tmp24 = __cil_tmp13;
    __cil_tmp35 = __cil_tmp24;
    if (__cil_tmp35) {
      __cil_tmp9 = y;
      __cil_tmp20 = __cil_tmp9;
      __cil_tmp31 = __cil_tmp20;
      return (__cil_tmp31);
    } else {
      __cil_tmp12 = y > z;
      __cil_tmp23 = __cil_tmp12;
      __cil_tmp34 = __cil_tmp23;
      if (__cil_tmp34) {
        __cil_tmp10 = y;
        __cil_tmp21 = __cil_tmp10;
        __cil_tmp32 = __cil_tmp21;
        return (__cil_tmp32);
      } else {
        __cil_tmp11 = y;
        __cil_tmp22 = __cil_tmp11;
        __cil_tmp33 = __cil_tmp22;
        return (__cil_tmp33);
      }
    }
  }
}
}
int correctQ(int x , int y , int z )
{
  int __cil_tmp4 ;
  int __cil_tmp5 ;
  int __cil_tmp6 ;
  int __cil_tmp7 ;
  int __cil_tmp8 ;
  int __cil_tmp9 ;
  int __cil_tmp10 ;
  int __cil_tmp11 ;
  int __cil_tmp12 ;
  int __cil_tmp13 ;
  int __cil_tmp14 ;
  int __cil_tmp15 ;
  int __cil_tmp16 ;
  int __cil_tmp17 ;
  int __cil_tmp18 ;
  int __cil_tmp19 ;
  int __cil_tmp20 ;
  int __cil_tmp21 ;
  int __cil_tmp22 ;
  int __cil_tmp23 ;
  int __cil_tmp24 ;
  int __cil_tmp25 ;
  int __cil_tmp26 ;
  int __cil_tmp27 ;
  int __cil_tmp28 ;
  int __cil_tmp29 ;
  int __cil_tmp30 ;
  int __cil_tmp31 ;
  int __cil_tmp32 ;
  int __cil_tmp33 ;
  int __cil_tmp34 ;
  int __cil_tmp35 ;
  int __cil_tmp36 ;

  {
  __cil_tmp14 = x > y;
  __cil_tmp25 = __cil_tmp14;
  __cil_tmp36 = __cil_tmp25;
  if (__cil_tmp36) {
    __cil_tmp8 = y > z;
    __cil_tmp19 = __cil_tmp8;
    __cil_tmp30 = __cil_tmp19;
    if (__cil_tmp30) {
      __cil_tmp4 = x;
      __cil_tmp15 = __cil_tmp4;
      __cil_tmp26 = __cil_tmp15;
      return (__cil_tmp26);
    } else {
      __cil_tmp7 = x > z;
      __cil_tmp18 = __cil_tmp7;
      __cil_tmp29 = __cil_tmp18;
      if (__cil_tmp29) {
        __cil_tmp5 = x;
        __cil_tmp16 = __cil_tmp5;
        __cil_tmp27 = __cil_tmp16;
        return (__cil_tmp27);
      } else {
        __cil_tmp6 = z;
        __cil_tmp17 = __cil_tmp6;
        __cil_tmp28 = __cil_tmp17;
        return (__cil_tmp28);
      }
    }
  } else {
    __cil_tmp13 = x > z;
    __cil_tmp24 = __cil_tmp13;
    __cil_tmp35 = __cil_tmp24;
    if (__cil_tmp35) {
      __cil_tmp9 = y;
      __cil_tmp20 = __cil_tmp9;
      __cil_tmp31 = __cil_tmp20;
      return (__cil_tmp31);
    } else {
      __cil_tmp12 = y > z;
      __cil_tmp23 = __cil_tmp12;
      __cil_tmp34 = __cil_tmp23;
      if (__cil_tmp34) {
        __cil_tmp10 = y;
        __cil_tmp21 = __cil_tmp10;
        __cil_tmp32 = __cil_tmp21;
        return (__cil_tmp32);
      } else {
        __cil_tmp11 = z;
        __cil_tmp22 = __cil_tmp11;
        __cil_tmp33 = __cil_tmp22;
        return (__cil_tmp33);
      }
    }
  }
}
}

int mainQ(int x , int y , int z , int c_0 , int c_1 , int c_2 , int c_3 , int c_4 ,
          int c_5 , int c_6 , int c_7 , int c_8 , int c_9 , int c_10 , int c_11 )
{
  int rb ;
  int tmp ;
  int rc ;
  int tmp___0 ;
  int __cil_tmp8 ;
  int __cil_tmp9 ;
  int __cil_tmp10 ;
  int cond ;
  int __cil_tmp24 ;
  int __cil_tmp25 ;
  int __cil_tmp26 ;
  int __cil_tmp27 ;
  int __cil_tmp28 ;
  int __cil_tmp29 ;
  int __cil_tmp30 ;
  int __cil_tmp31 ;
  int __cil_tmp32 ;
  int __cil_tmp33 ;
  int __cil_tmp34 ;
  int __cil_tmp35 ;
  int __cil_tmp36 ;
  int __cil_tmp37 ;
  int __cil_tmp38 ;
  int __cil_tmp39 ;
  int __cil_tmp40 ;
  int __cil_tmp41 ;

  {
  tmp = buggyQ(x, y, z);
  rb = tmp;
  tmp___0 = correctQ(x, y, z);
  rc = tmp___0;
  __cil_tmp10 = rc == rb;
  __cil_tmp26 = __cil_tmp10;
  __cil_tmp35 = __cil_tmp26;
  if (__cil_tmp35) {
    printf("PASS (rb = rc = %d) with input: x %d, y %d, z %d\n", rc, x, y, z);
    __cil_tmp8 = 1;
    __cil_tmp24 = __cil_tmp8;
    __cil_tmp33 = __cil_tmp24;
    return (__cil_tmp33);
  } else {
    __cil_tmp37 = (c_0 * x + c_1 * y) + (c_2 * z + c_3);
    __cil_tmp38 = (c_4 * x + c_5 * y) + (c_6 * z+ c_7);
    __cil_tmp39 = (c_8 * x + c_9 * y) + (c_10 *z + c_11);
    __cil_tmp40 = buggyQ(__cil_tmp37, __cil_tmp38, __cil_tmp39);
    __cil_tmp41 = rc == __cil_tmp40;

    if (__cil_tmp41 && __cil_tmp32) {
      printf("PASS with coeficients: %d %d %d %d %d %d %d %d %d %d %d %d\n", c_0,
             c_1, c_2, c_3, c_4, c_5, c_6, c_7, c_8, c_9, c_10, c_11);
    } else {
      printf("FAIL with input: x %d, y %d, z %d\n", x, y, z);
    }
  }
  __cil_tmp27 = 0;
  __cil_tmp36 = __cil_tmp27;
  return (__cil_tmp36);
}
}

int main(int argc , char **argv )
{
  int rv ;
  int tmp ;
  int tmp___0 ;
  int tmp___1 ;
  int tmp___2 ;
  int __cil_tmp8 ;
  int __cil_tmp24 ;
  int __cil_tmp25 ;
  int __cil_tmp26 ;

  {

  __cil_tmp24 = mainQ(-9,38,81, 0, 0, 0, -23, 23, -23, 22, 0, 80, 0, 23, 37);
  __cil_tmp25 = 0;
  __cil_tmp26 = __cil_tmp25;
  return (__cil_tmp26);
}
}
