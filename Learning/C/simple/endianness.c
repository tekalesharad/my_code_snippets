#include <stdio.h>
main()
{
int val  = 1;
char *c = &val;
if (*c)    
       printf("Little endian");
   else
       printf("Big endian");

printf("%d\n", *c);
printf("%d\n", *(c+1));
}
