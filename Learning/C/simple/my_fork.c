#include <stdio.h>
main()
{
int val = 0;
val = fork();
if(val !=0) {
  printf( "parent");
  getchar();
  return 0;
}
else { 
  printf("child_exit");
}
}

