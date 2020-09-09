
#include <stdio.h>
#include <string.h>

#include <sys/socket.h>
#include <netinet/in.h>
#define VAL 0
int print(const void * data)
{
      printf("%d\n",  *(int *)data);
}
main()
{
// char ptr[12]="1234567890";
// int *val;
// val = ((char *)ptr) + 8;
// printf("val:%d\n", val);

int val=VAL;
print(&val);
}
