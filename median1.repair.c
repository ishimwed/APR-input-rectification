#include <stdio.h>
#include <civlc.cvh>
$input int c_0, c_1, c_2, c_3, c_4, c_5, c_6, c_7, c_8, c_9, c_10, c_11;

int max(int x,int y, int z){
  int m;
  if(x > y){
    if(y > z) m = x;
    else if(x > z) m = x;
    else return z;
  }else{
    if(x > z) m = y;
    else if(y > z) {
      m = y;
      $pathCondition();
    }
    else
      m = y; // error location
      // return z;
  }
  return m;
}

int main(int argc, char* argv[]){

     int x1, y1, z1;
     x1 = c_0 * 0 + c_1 * 1 + c_2 * 0 + c_3;
     y1 = c_4 * 0 + c_5 * 1 + c_6 * 0 + c_7;
     z1 = c_8 * 0 + c_9 * 1 + c_10 *0 + c_11;

     int x2, y2, z2;
     x2 = c_0 * -5 + c_1 * 9 + c_2 * -5 + c_3;
     y2 = c_4 * -5 + c_5 * 9 + c_6 * -5 + c_7;
     z2 = c_8 * -5 + c_9 * 9 + c_10 *-5 + c_11;

     if (x1<=y1&&x1>z1 && x2<=y2&&x2>z2) {
      $pathCondition();
      $assert($false);
     }
     return 0;
}
