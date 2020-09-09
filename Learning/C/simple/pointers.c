#include <stdio.h>

main()
{
int new_val;
int *val;
int a =8; 
int b = 20;
val = &new_val;
*val = a - b;
printf("%d \n", *val );

}
