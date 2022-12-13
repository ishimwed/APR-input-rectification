#include <stdio.h>
#include <civlc.cvh>
$input int x, y, z;

int buggyQ(){

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

int correctQ(){
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

int mainQ()
{
  int rb, rc;
  rb = buggyQ();
  rc = correctQ();

  if (rb!=rc) {

    $pathCondition();
    // $assert($false);
  }
  return 0;
}

int main() {
  int rv = mainQ();
  return 0;
  }
