int buggyQ(int a, int b, int c) {
  int median;
  if((a >= b && a <= c) || (a >= c && a <= b))
    median = a;
  if((b >= a && b <= c) || (b >= c && b <= a))
    median = b;
  else
    median = c;

  return median;
}


int correctQ(int a, int b, int c){
  int median;
  if((a >= b && a <= c) || (a >= c && a <= b))
    median = a;
  else if((b >= a && b <= c) || (b >= c && b <= a))
    median = b;
  else
    median = c;

  return median;
}

int mainQ(int x, int y, int z){
     int rb = buggyQ(x,y,z);
     int rc = correctQ(x, y, z);

     if (rb == rc){
     	  printf("PASS (rb = rc = %d) with input: x %d, y %d, z %d\n",
     		 rc, x, y, z);
	  return 1;
     }
     else{
     	  printf("FAIL (rb %d, rc %d) with input: x %d, y %d, z %d\n",
     		 rb, rc, x, y, z);
	  return 0;
     }
}
int main(int argc, char* argv[]){
     int rv = mainQ(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
     return 0;
}
