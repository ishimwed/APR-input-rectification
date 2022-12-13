#include <stdio.h>
#include "klee/klee.h"

int main(int argc, char* argv[]){
  int uk_0, uk_1, uk_2, x, y, z;
  klee_make_symbolic(& uk_0, sizeof(uk_0), "uk_0");
  klee_assume(-10 <= uk_0);
  klee_assume(uk_0 <= 10);
  klee_make_symbolic(& uk_1, sizeof(uk_1), "uk_1");
  klee_assume(-10 <= uk_1);
  klee_assume(uk_1 <= 10);
  klee_make_symbolic(& uk_2, sizeof(uk_2), "uk_");
  klee_assume(-10 <= uk_2);
  klee_assume(uk_2 <= 10);
  if (uk_0<=uk_1 && uk_0<=uk_2 && uk_1>uk_2) {
    x = 0 * uk_0 + 0 * uk_1 + 0 * uk_2 + 0;
    y = 0 * uk_0 + 0 * uk_1 + 0 * uk_2 + 0;
    z = 0 * uk_0 + 0 * uk_1 + 0 *uk_2 + -1;
    if (x<=y && x>z) {
     printf("PASS with inputs: x %d y %d z %d \n", uk_0, uk_1, uk_2);
    }
    else {
     printf("FAIL with inputs: x %d y %d z %d \n", uk_0, uk_1, uk_2);
    }
  }
   return 0;
}
