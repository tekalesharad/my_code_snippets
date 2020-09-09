#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#if 0
void split_and_print(uint16_t val) {
 uint8_t tmp;
 uint8_t tmp1;
 tmp1 = (val ) & 0x00FF;
 tmp = (val >> 8) & 0x00FF;
 printf ("printing first half value= %x", tmp1);
 printf ("printing second half value= %x", tmp);
} 
#endif

void merge_and_print(uint8_t val1, uint8_t val2) {
uint16_t tmp;

tmp = val1 << 8;
tmp |= val2;
printf ("printing first half value= %x", tmp);
}

main()
{
//uint8_t a =0xFF;
uint8_t z =0xBB;
uint8_t y =0xCC;
//uint16_t b = 0xAACC;
//uint32_t c = 0xFFFFFFFF;
//printf("a=%d b=%d,c=%d\n", sizeof(a), sizeof(b), sizeof(c));
//printf("a=%x b=%x,c=%x\n", a, b, c);

//split_and_print(b);
merge_and_print(z,y);


}

