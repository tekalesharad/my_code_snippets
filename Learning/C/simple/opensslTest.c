#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>



#if 0
  uint8_t key[16];
  uint32_t key_len;
  uint8_t message[40];
  int len;
  uint8_t actual_mac[16];
  uint8_t xcbc_mac_96[12];

     {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f},
     16,
     {0x00 ,0x01 ,0x02 ,0x03 ,0x04 ,0x05 ,0x06 ,0x07 ,0x08 ,0x09 ,0x0a ,0x0b ,0x0c ,0x0d ,0x0e ,0x0f},
     16,
     {0xd2, 0xa2, 0x46, 0xfa, 0x34, 0x9b, 0x68, 0xa7, 0x99, 0x98, 0xa4, 0x39, 0x4f, 0xf7, 0xa2, 0x63},
     {0xd2, 0xa2, 0x46, 0xfa, 0x34, 0x9b, 0x68, 0xa7, 0x99, 0x98, 0xa4, 0x39},
#endif


#define KEY_LEN 16
unsigned char selftest_in[KEY_LEN] = {0x00 ,0x01 ,0x02 ,0x03 ,0x04 ,0x05 ,0x06 ,0x07 ,0x08 ,0x09 ,0x0a ,0x0b ,0x0c ,0x0d ,0x0e ,0x0f};
//AES_set_encrypt_key(key,key_len,AES_KEY *);
//AES_encrypt(in, out, AES_KEY * );
unsigned char key[KEY_LEN]={0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};


unsigned char in[KEY_LEN]={0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01 };
unsigned char in2[KEY_LEN]={0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02 };
unsigned char in3[KEY_LEN]={0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03 };

void my_debug(unsigned char *val) {
  int i=0;
  while(i<KEY_LEN)
    printf("%02x ",val[i++]);
  printf("\n");
}


void generate_keys(AES_KEY *C1_out, unsigned char *key2, unsigned char* key3)
{

AES_KEY C1;
unsigned char out[16] = {0};

memset(&C1, 0, sizeof(AES_KEY));
memset(out, 0, sizeof(out));

AES_set_encrypt_key(key, KEY_LEN * 8, &C1);
AES_encrypt(in, out, &C1);

AES_set_encrypt_key(out, KEY_LEN*8, C1_out);

AES_encrypt(in2, key2, &C1);

AES_encrypt(in3, key3, &C1);

printf("Key set in : ");
my_debug((unsigned char *)C1_out->rd_key);

printf("Key2 String: ");
my_debug((unsigned char*)key2);

printf("Key3 String: ");
my_debug((unsigned char*)key3);
}


int main()
{
AES_KEY get_k1;
char key2[KEY_LEN]={0};
char key3[KEY_LEN]={0};
char out[KEY_LEN]={0};
char temp[KEY_LEN]={0};
int iter = 0;

generate_keys(&get_k1, key2, key3);

memset(temp, 0, KEY_LEN);
memset(out, 0, KEY_LEN);

for (iter =0; iter < KEY_LEN; iter++ ) {
  temp[iter] ^= selftest_in[iter];
  temp[iter] ^= key2[iter];
}
AES_encrypt(temp, out, &get_k1);

printf("Fianl encrypted String: \n ");
my_debug((unsigned char*)out);

}


#if 0
//printf("Encrypted Key Set g: \n");
AES_KEY C1;
AES_KEY C2;
unsigned char out[16] = {0};
unsigned char out2[16] = {0};
unsigned char out3[16] = {0};

memset(&C1, 0, sizeof(AES_KEY));
memset(&C2, 0, sizeof(AES_KEY));
memset(out, 0, sizeof(out));

AES_set_encrypt_key(key, KEY_LEN * 8, &C1);
printf("key: ");
my_debug((unsigned char*)key);
printf("Gen Key String: ");
my_debug((unsigned char*)C1.rd_key);
AES_encrypt(in, out, &C1);
#if 0
printf("Key  String: ");
my_debug((unsigned char*)key);
printf("Key  Set: ");
my_debug((unsigned char *)C1.rd_key);

printf("In String: ");
my_debug((unsigned char*)in);
#endif

printf("Out1 String: ");
my_debug((unsigned char*)out);

AES_set_encrypt_key(out, KEY_LEN*8, &C2);

printf("Key set in C2: ");
my_debug((unsigned char *)C2.rd_key);

AES_encrypt(in2, out2, &C1);
printf("Out2 String: ");
my_debug((unsigned char*)out2);

AES_encrypt(in3, out3, &C1);
printf("Out3 String: ");
my_debug((unsigned char*)out3);
#endif



