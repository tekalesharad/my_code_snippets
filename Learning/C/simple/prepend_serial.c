#include <stdio.h>
#include <string.h>

struct vars {
int test:1;  
}


main()
{
char dst[100];
const char src[100]="CN=SIMBA-ALCATEL-LUCENT.com,O=Alcatel Lucent";
//char src[100]="O=Alcatel Lucent,CN=SIMBA-ALCATEL-LUCENT.com";
char *tmp; 
char *serial="102102"; 

struct vars new;
new.test = 1;
if(!new.test) {
tmp = strstr(src,"CN=");
strncpy(dst,src, tmp-src);
dst[tmp-src] = '\0';
sprintf(dst+(tmp-src), "CN=%s-%s", serial, tmp+3);
printf("src: %s\n", src);
printf("dst %s\n", dst);
}
}
