#include <stdio.h>

struct cmp_cfg {
char *post_path[2];
};
struct cmp_cfg cmp_cfg1;


main()
{

cmp_cfg1.post_path[0]="Sharad";
cmp_cfg1.post_path[1]="done";

printf("1-%s 2-%s\n", cmp_cfg1.post_path[0], cmp_cfg1.post_path[0]);

}
#if 0
{
   int arr[10]= {501,501,501,501,501,501,501,501,501,501};
   int i=0;
 
   for(i=2; i< 4; i++) {
       arr[i]= 500;
       arr[i+3]=500;
}
       
   for(i =0 ; i<10 ; i++)
       printf("arr[%d]=%d\n", i, arr[i]);

}
#endif
