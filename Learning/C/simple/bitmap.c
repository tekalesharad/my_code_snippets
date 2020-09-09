#include <stdio.h>


main(){
int num=0x89;

printf("dec %d\n", num);
printf("dex %x\n", num);
int iter=0;
//printf("sizeof int:%d\n", sizeof(int));
for ( iter = 0; iter < sizeof(int)*8; iter++) {
    printf("%d ", num & 1);
    num =1<<num; 
}

printf("\n ");
//printf("%d\n", (num>>3)&1);
/*
int main(){
int count=0x89;
for (count=0; count; count &= count-1) 
count++;
printf("%d\n", count);
*/


return ;
}

