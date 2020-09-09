#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#if 0
#define PACKED __attribute__ ((packed))
//#pragma pack(1)
struct not_padded
{
   uint8_t a;
   uint32_t b;
   uint16_t c;
};

struct padded
{
   uint8_t a;
   uint32_t b;
   uint16_t c;
}PACKED;

struct hand_rearranged_padded
{
   uint8_t a;
   uint16_t c;
   uint32_t b;
};
//}PACKED;

struct foo1 {
   char *p;
   char c;
   long x;
};

struct foo2 {
   int p
   char c;
   short x;
};

struct foo2 {
   char c;
   char *p;
   long x;
};

struct foo3 {
  short s;
  char c;
};
#endif
struct fooA {
   char *p;
   char c;
   long x;
};

struct fooB {
   char c1;
   int p;
   short x;
//   char *c;
};

int main(int argc, char * argv[])
{
 #if 0
   struct not_padded inst;
   printf ("size_of struct %d\n", sizeof(inst));


   struct padded inst1;
   printf ("size_of struct %d\n", sizeof(inst1));


   struct hand_rearranged_padded inst2;
   printf ("size_of struct %d\n", sizeof(inst2));

   char *p;
    printf("sizeof :%d\n", sizeof(p));
   struct foo1 inst1;
   printf ("size_of struct %d\n", sizeof(inst1));

   struct foo2 inst2;
   printf ("size_of struct %d\n", sizeof(inst2));
   struct foo3 inst3;
   printf ("size_of struct %d\n", sizeof(inst3));
#endif

   struct fooA inst2;
   printf ("size_of struct %d\n", sizeof(inst2));
   struct fooB inst3;
   printf ("size_of struct %d\n", sizeof(inst3));


}

