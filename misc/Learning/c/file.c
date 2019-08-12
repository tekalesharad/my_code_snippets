#include <stdio.h>

int * findoddnum(int l, int m, int * size)
{

    int i =0;
    int res = 0;
    int *arr =(int *) malloc(sizeof(int)* ((m-l)/2) + 2);

    for(i=l;i<=m;i++)
    {
	    if(i==0) continue;
	 //   if(i==1) {
//		    arr[res++] = i;
//	    };
	    if (i%2 !=0 ){
		    arr[res++] = i;
	    }

    }
    
    *size = res-1  ;
    return arr;


}


main()
{

    int *arr;  
    int num1 =0;
    int num2 =0, k =0;
    int size;
    scanf("%d", &num1);
    scanf("%d", &num2);

    arr = findoddnum(num1,num2, &size);

    for(k=0;k<=size;k++)
    {
	    printf("Odd:%d\n", arr[k]);
    }



}

