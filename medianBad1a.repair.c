#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <civlc.cvh>
$input int c_0, c_1, c_2, c_3, c_4, c_5, c_6, c_7, c_8, c_9, c_10, c_11;

int buggyQ(int x, int y, int z) {
     int m = z;
     if (y < z){
	  if (x<y){
	       m = y;
	  }
	  else {
	       if (x>=z){
		    m = y; //BUG, should be m = x
	       }
	  }
     }
     else{
	  if(x>y){
	       m=y;
	  }
	  else {
	       if (x>z){
		    m =x;
	       }
	  }
     }

     return m ;
}


int correctQ(int x, int y, int z){
     int m = z;
     if (y < z){
	  if (x<y){
	       m = y;
	  }
	  else {
	       if (x<z){
		    m = x;
	       }
	  }
     }
     else{
	  if(x>y){
	       m=y;
	  }
	  else {
	       if (x>z){
		    m =x;
	       }
	  }
     }
     return m;     
}

int mainQ(){
  int x_new, y_new, z_new;
  x_new = c_0 * 488 + c_1 * 489 + c_2 * 0 + c_3;
  y_new = c_4 * 488 + c_5 * 489 + c_6 * 0 + c_7;
  z_new = c_8 * 488 + c_9 * 489 + c_10 *0 + c_11;
  int rb1 = buggyQ(x_new, y_new, z_new);
  int rc1 = correctQ(488,489,0);

  x_new = c_0 * -21 + c_1 * -22 + c_2 * 490 + c_3;
  y_new = c_4 * -21 + c_5 * -22 + c_6 * 490 + c_7;
  z_new = c_8 * -21 + c_9 * -22 + c_10 *490 + c_11;
  int rb2 = buggyQ(x_new, y_new, z_new);
  int rc2 = correctQ(-21,-22,490);


  if(rb1==rc1 && rb2==rc2){
    $pathCondition();
    $assert($false);
  }
  return 0;
}
int main(){
     int rv = mainQ();
     return 0;
}
