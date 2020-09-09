#include <stdio.h>

void fun1()
{
volatile unsigned int *new_vol_var = (unsigned int *)0x1234;

while (new_vol_var == 0)
   print("DOne");

}

void fun()
{
int new_var = 0;
while (new_var == 0)
   print("DOne");

}
main()
{
fun();
printf("DOne");
}
