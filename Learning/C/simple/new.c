#include <stdio.h>
#include <inttypes.h>
main()
{

int ret=10;
char m[2000]; 
system("touch ./cl"); 
sprintf(m,"echo 'VerifyVal:%d' >> ./cl",ret) ;
system(m);

}
