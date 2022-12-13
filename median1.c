#include <stdio.h>
#include <civlc.cvh>
$input int x, y, z;

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
    }
    else
      m = y; // error location
      // return z;
      $pathCondition();
  }
  return m;
}

int main(int argc, char* argv[]){
     int rv = max(x, y, z);
     return 0;
}
