#define U_BOOT_VERSION "U-Boot 5.5.0.0-170857X"

#include <stdio.h>
#include <string.h>
main()
{
 char *str = strchr(U_BOOT_VERSION, ' ');
 printf("%s\n", str);

}
