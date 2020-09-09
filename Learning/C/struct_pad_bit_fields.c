#include <stdio.h>
#include <stdint.h>
#define MAC_ADDR_LEN 6 

struct bit_fields
{
   struct bit_fields1 
   {
     char  *bf;
     short val;
   }inner;
   char val1;
};

main()
{
  
  struct bit_fields bf;
  printf("bit_field_pad:%d\n", sizeof(bf));
}
