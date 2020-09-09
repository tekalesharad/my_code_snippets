#include <stdio.h>
main()
{
char *val="trustpoint cmp-test subject-name ""CN=SIMBA-ALCATEL-LUCENT.com,O=Alcatel Lucent"" ABCecret 0 test  reference-id 123456 sender-name ""CN=SIMBA-ALCATEL-LUCENT.com,O=Alcatel Lucent"" recipient-name ""O=Alcatel Lucent,CN=ALU.com";

if (( strstr(val, "trustpoint") !=NULL )  && ( strstr(val, "secret") != NULL))
    printf("In If: val = %s \n", val );
else
    printf("In else %s\n", val);
}
