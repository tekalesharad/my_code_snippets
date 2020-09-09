
#define P2PCAPABILITY 0x2
#include <stdio.h>
main()
{
struct element_id *elem = (struct element_id *)elements;

//unsigned char element[12] = {0x39, 0x50, 0x6F, 0x9A, 0x09, 0x02, 0x02, 0x00, 0x25, 0x89, 0x0d};
unsigned char  wfa_oui[4] = {0x50, 0x6F, 0x9A, 0x09};
unsigned char beacon[12] = {0x39, 0x50, 0x6F, 0x9A, 0x09, 0x02, 0x02, 0x00, 0x25, 0x00, 0x0d};

unsigned char *ptr = beacon +1;

ptr += sizeof(wfa_oui);
if (*ptr == P2PCAPABILITY) {
    ptr += 1; // go past capability type
    ptr += 2; // go past attribute length
    ptr += 1; // go past device capability
    printf("capalibilty exists %d\n", *ptr & 1);
}
printf("%d", *ptr);

}
