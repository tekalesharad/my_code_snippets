#include <stdio.h>

main(int argc, char* argv[])
{

int i = 0 ;
//for (;i < argc; i++) {
        if ( strlen(argv[0]) > 0 )
	printf("%d argv[%d]=%s\n", i, i, argv[0]);
//}
        if ( strlen(argv[1]) > 0 )
	printf("%d argv[%d]=%s\n", i, i, argv[1]);

        if ( strlen(argv[2]) > 0 )
	printf("%d argv[%d]=%s\n", i, i, argv[2]);

        if ( strlen(argv[0]) > 0 )
	printf("%d argv[%d]=%s\n", i, i, argv[3]);

        if ( strlen(argv[3]) > 0 )
	printf("%d argv[%d]=%s\n", i, i, argv[4]);

        if ( strlen(argv[4]) > 0 )
	printf("%d argv[%d]=%s\n", i, i, argv[5]);

        if ( strlen(argv[5]) > 0 )
	printf("%d argv[%d]=%s\n", i, i, argv[6]);
return 0;
}
