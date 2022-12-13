#include <stdio.h>
#include "klee/klee.h"
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

int mainQ(int c_0 , int c_1 , int c_2 , int c_3 , int c_4 ,
          int c_5 , int c_6 , int c_7 , int c_8 , int c_9 , int c_10 , int c_11 )
{
  int rb ;
  int tmp ;
  int rc ;
  int tmp___0 ;
  int __cil_tmp8 ;
  int __cil_tmp9 ;
  int __cil_tmp10 ;

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
    __cil_tmp37 = (c_0 * 9 + c_1 * 2) + (c_2 * -1+ c_3);
    __cil_tmp38 = (c_4 * 9 + c_5 * 2) + (c_6 * -1+ c_7);
    __cil_tmp39 = (c_8 * 9 + c_9 * 2) + (c_10 *-1 + c_11);
    __cil_tmp40 = buggyQ(__cil_tmp37, __cil_tmp38, __cil_tmp39);
    __cil_tmp41 = correctQ(9,2,-1) == __cil_tmp40;
    // __cil_tmp28 = (c_0 * -99 + c_1 * -99) + (c_2 * 0+ c_3);
    // __cil_tmp29 = (c_4 * -99 + c_5 * -99) + (c_6 * 0+ c_7);
    // __cil_tmp30 = (c_8 * -99 + c_9 * -99) + (c_10 *0 + c_11);
    // __cil_tmp31 = buggyQ(__cil_tmp28, __cil_tmp29, __cil_tmp30);
    // __cil_tmp32 = correctQ(-99,-99,0) == __cil_tmp31;
    // __cil_tmp28 = (c_0 * -98 + c_1 * -98) + (c_2 * -23 + c_3);
    // __cil_tmp29 = (c_4 * -98 + c_5 * -98) + (c_6 * -23 + c_7);
    // __cil_tmp30 = (c_8 * -98 + c_9 * -98) + (c_10 *-23 + c_11);
    // __cil_tmp31 = buggyQ(__cil_tmp28, __cil_tmp29, __cil_tmp30);
    // int a = correctQ(-98,-98,-23) == __cil_tmp31;
    // __cil_tmp28 = (c_0 * -9 + c_1 * 38) + (c_2 * 81 + c_3);
    // __cil_tmp29 = (c_4 * -9 + c_5 * 38) + (c_6 * 81 + c_7);
    // __cil_tmp30 = (c_8 * -9 + c_9 * 38) + (c_10 *81 + c_11);
    // __cil_tmp31 = buggyQ(__cil_tmp28, __cil_tmp29, __cil_tmp30);
    // int b = correctQ(-9,38,81) == __cil_tmp31;

    if (__cil_tmp41 ) {
      printf("PASS with coeficients: %d %d %d %d %d %d %d %d %d %d %d %d\n", c_0,
             c_1, c_2, c_3, c_4, c_5, c_6, c_7, c_8, c_9, c_10, c_11);
    }
    else{
      printf("fail with coeficients: %d %d %d %d %d %d %d %d %d %d %d %d\n", c_0,
             c_1, c_2, c_3, c_4, c_5, c_6, c_7, c_8, c_9, c_10, c_11);
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
  int c_0 ;
  int c_1 ;
  int c_2 ;
  int c_3 ;
  int c_4 ;
  int c_5 ;
  int c_6 ;
  int c_7 ;
  int c_8 ;
  int c_9 ;
  int c_10 ;
  int c_11 ;
  int __cil_tmp24 ;
  int __cil_tmp25 ;
  int __cil_tmp26 ;

  {

  // klee_make_symbolic(& c_0, sizeof(c_0), "c_0");
  // klee_assume(-10 <= c_0);
  // klee_assume(c_0 <= 10);
  // klee_make_symbolic(& c_1, sizeof(c_1), "c_1");
  // klee_assume(-10 <= c_1);
  // klee_assume(c_1 <= 10);
  // klee_make_symbolic(& c_2, sizeof(c_2), "c_2");
  // klee_assume(-10 <= c_2);
  // klee_assume(c_2 <= 10);
  // klee_make_symbolic(& c_3, sizeof(c_3), "c_3");
  // klee_assume(-100 <= c_3);
  // klee_assume(c_3 <= 100);
  // klee_make_symbolic(& c_4, sizeof(c_4), "c_4");
  // klee_assume(-100 <= c_4);
  // klee_assume(c_4 <= 100);
  // klee_make_symbolic(& c_5, sizeof(c_5), "c_5");
  // klee_assume(-10 <= c_5);
  // klee_assume(c_5 <= 10);
  // klee_make_symbolic(& c_6, sizeof(c_6), "c_6");
  // klee_assume(-100 <= c_6);
  // klee_assume(c_6 <= 100);
  // klee_make_symbolic(& c_7, sizeof(c_7), "c_7");
  // klee_assume(-100 <= c_7);
  // klee_assume(c_7 <= 100);
  // klee_make_symbolic(& c_8, sizeof(c_8), "c_8");
  // klee_assume(-10 <= c_8);
  // klee_assume(c_8 <= 10);
  // klee_make_symbolic(& c_9, sizeof(c_9), "c_9");
  // klee_assume(-100 <= c_9);
  // klee_assume(c_9 <= 100);
  // klee_make_symbolic(& c_10, sizeof(c_10), "c_10");
  // klee_assume(-100 <= c_10);
  // klee_assume(c_10 <= 100);
  // klee_make_symbolic(& c_11, sizeof(c_11), "c_11");
  // klee_assume(-100 <= c_11);
  // klee_assume(c_11 <= 100);
  __cil_tmp24 = mainQ(-30, 95, 10, 85, 14, -48, -1, -22, 5, -27, -20, -17);
  __cil_tmp25 = 0;
  __cil_tmp26 = __cil_tmp25;
  return (__cil_tmp26);
}
}
