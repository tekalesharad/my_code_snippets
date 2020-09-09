#include <stdio.h>

void fun (int *val)
{
printf("Val:%d", *val);

}

void main()
{
int i = 10;
fun(&i);
}

