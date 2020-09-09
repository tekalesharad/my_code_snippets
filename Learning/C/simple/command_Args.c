#include <stdio.h>
main(int argc, char* argv[])
{
int i=0;
printf("Argc:%d\n", argc);
for (i=0; i<argc; i++)
     printf("%d %s\n", i, argv[i]);

    if( ( argv[argc] != '\0' ) && !(strcmp(argv[4],"reference-id")))
        printf("%s\n",argv[5]);

    if(!(strcmp(argv[6],"sender-name")))
        printf("%s\n", argv[7]);

     if (!(strcmp(argv[8], "ca-psk")))
        printf("%s\n", argv[9]);

     if (!(strcmp(argv[8], "recipient-name")))
        printf("%s\n",argv[9]);

}
