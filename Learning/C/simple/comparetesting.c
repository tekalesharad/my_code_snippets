#include <stdio.h>
main()
{
int ret;
ret = system("cmp ~/test1 ~/test2");
printf("OP=%d\n", ret);
}
