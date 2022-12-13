#include <stdio.h>
#include "klee/klee.h"

int buggyQ(int x,int y, int z){
  if(x > y){
    if(y > z) return x;
    else if(x > z) return x;
    else return z;
  }else{
    if(x > z) return y;
    else if(y > z) return y;
    else
      return y; // error location
      // return z;
  }
}

int correctQ(int x,int y, int z){
  if(x > y){
    if(y > z) return x;
    else if(x > z) return x;
    else return z;
  }else{
    if(x > z) return y;
    else if(y > z) return y;
    else
      return z;
  }
}

int mainQ(int x , int y , int z )
{
  int rb = buggyQ(x, y, z);
  int rc = correctQ(x, y, z);

  if (rc==rb) {
    printf("PASS with input: x %d, y %d, z%d\n", x, y, z);
    return 0;
  }
  else{
    printf("FAIL with input: x %d, y %d, z %d\n", x, y, z);
    return 1;
  }

}

int main() {
  int uk_0, uk_1, uk_2;

  klee_make_symbolic(& uk_0, sizeof(uk_0), "uk_0");
  klee_assume(-100 <= uk_0);
  klee_assume(uk_0 <= 100);
  klee_make_symbolic(& uk_1, sizeof(uk_1), "uk_1");
  klee_assume(-100 <= uk_1);
  klee_assume(uk_1 <= 100);
  klee_make_symbolic(& uk_2, sizeof(uk_2), "uk_2");
  klee_assume(-100 <= uk_2);
  klee_assume(uk_2 <= 100);

  int rv = mainQ(uk_0, uk_1, uk_2);
  return 0;
  }
