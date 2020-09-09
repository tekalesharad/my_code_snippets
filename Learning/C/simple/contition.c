#include <stdio.h>

//#define TAR1 "nx7"
//#define TAR2 "nuxi"
//#define BRAND "alps"

main()
{

#if (defined(TAR1) || defined(TAR2)) && defined(BRAND)
printf("correcti\n");
#else
printf("incorrect\n");
#endif
}
