#include <stdio.h>
#include <string.h>
#include <linux/types.h>
#include <inttypes.h>

#define MAC_ADDR_LEN 8
#if 0
//ddv
vvoid dpd2_str2mac(const char *str, uint8_t *mac)
{
  int idx=0;
    for (idx=0; idx<MAC_ADDR_LEN; idx++) {
        *mac = (*str <= '9') ? ((*str-'0') << 4) : ((tolower(*str)-'a'+0xA)<<4);
        str++;
        *mac |= (*str <= '9') ? ((*str-'0')) : (tolower(*str)-'a'+0xA);
        str++;
        str++;  // skip the '-' or ':'
        mac++;
    }

}
#endif

main()
{

  //char addr[] = "00D095FA6F1C646400FE657A";
//   char* addr_in = "00D095FA6F1C"; 
//  char addr_out[12] = "00D095FA6F1C";
  uint8_t addr_out[5];
  uint8_t addr_in[] = "00D095FA6F1C";
  snprintf(addr_out,4, "%s", (const char *) addr_in+2  );
  
printf("%s\n", addr_out);

}

