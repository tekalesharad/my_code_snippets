#include <stdio.h>
#include <inttypes.h>
main()
{
/*
  uint8_t *y=NULL;;
  uint8_t *z=NULL;;
   y = (uint8_t *)x;
  z = *y;
  w = *x;
 uint16_t  *w;
*/
  uint16_t *x = malloc(sizeof(short int));
  uint8_t *y=NULL;;
  *x = 684;

  y = (uint8_t*) x; 
  uint8_t z = *y; 
  uint16_t w = *x;

  printf("x: %d\n", *x);
  printf("y: %d\n", *y);
  printf("z: %d\n", z);
  printf("w: %d\n", w);
}

