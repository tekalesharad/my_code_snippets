#include <stdio.h>
main()
{

double carrierWavePower  = -79.881484;
//int carrierWavePower  = -79;
double val, ret;
ret = modf(carrierWavePower, &val);
printf("%f ret=%f val=%f \n", carrierWavePower, ret, val );

if(   -85 <= carrierWavePower &&  carrierWavePower <= -70  )
		printf("true \n");
else
		printf("flase \n");
return 0;
}

