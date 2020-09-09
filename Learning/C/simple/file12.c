#include <stdio.h>
#include <string.h>

#include <sys/socket.h>
#include <netinet/in.h>

//const static struct sockaddr_in sin = { .sin_family = AF_INET, .sin_port = 0 };

#if 0
const char INPUT[]= "00D095FA6F1C646400FE657A";
//unsigned long  INPUT= 00D095FA6F1C646400FE657A;
typedef struct tlv
{
int type;
int length;
char *val;
} TLV;
#endif
typedef struct wired_integration_input {
struct sockaddr_in *ip_addr;
//char mac[6];
//char ipadr[4];
//char port[4];
} INPUT_VAL;

INPUT_VAL new_val_test = {NULL};

main()
{
printf("Hello World\n");
#if 0
TLV *new_tlv = (struct tlv *) malloc(100);
new_tlv->val =(char *) malloc(30);
INPUT_VAL new_ip;

memcpy(new_tlv->val, INPUT, sizeof(INPUT));

memset (&new_ip, 0, sizeof(new_ip));
memcpy(new_ip.mac, (char*)INPUT, 6);
//new_ip.mac[strlen(new_ip.mac+1)] = '\0';

memcpy(new_ip.ipadr, (char*)INPUT+6, 6);
new_ip.mac[strlen(new_ip.ipadr+1)] = '\0';

printf("INPUT: %d \n", INPUT);

printf("mac:%s\nipadr:%s\n", new_ip.mac, new_ip.ipadr);


printf("INPUT: %s \n", new_tlv->val);
#endif
}
