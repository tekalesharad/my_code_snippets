#include <stdio.h>
main()
{
#if 0
int val  = 1;
char *c = &val;
if (*c)    
       printf("Little endian");
   else
       printf("Big endian");

printf("%d\n", *c);
printf("%d\n", *(c+1));

char *x = (char *)&val;

if( x == 0x10 )
printf("Littlen endiness %d", *x);
else
printf("big endiness %d", *x);
#endif


int val = 0x76543210;

  char *c = (char*) &val;
 
  printf ("*c is: 0x%x\n", *c);
  if (*c == 0x10)
  {
    printf ("Underlying architecture is little endian. \n");
  }
  else
  {
     printf ("Underlying architecture is big endian. \n");
  }
 
  return 0;
}

//}
