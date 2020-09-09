#include <stdio.h>

struct foo 
{
   char aa[9];
   int *  p;
};

main()
{

struct foo a;
printf("padding info:%d", sizeof(a));

}
