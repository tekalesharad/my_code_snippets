#include <stdio.h>
#include <stdint.h>

struct aes_xcbc_tvs {
  unsigned char key[50];
  unsigned char message[80];
  unsigned char mac[69];
  unsigned char mac_96[24];
} tVectors[] = {
   {
     {0x00 ,0x01 ,0x02 ,0x03 ,0x04 ,0x05 ,0x06 ,0x07 ,0x08 ,0x09 ,0x0a ,0x0b ,0x0c ,0x0d ,0x0e ,0x0f},
     "",
     {0x75 ,0xf0 ,0x25 ,0x1d ,0x52 ,0x8a ,0xc0 ,0x1c ,0x45 ,0x73 ,0xdf ,0xd5 ,0x84 ,0xd7 ,0x9f ,0x29},
     {0x75 ,0xf0 ,0x25 ,0x1d ,0x52 ,0x8a ,0xc0 ,0x1c ,0x45 ,0x73 ,0xdf ,0xd5} 
   },
   {
     "000102030405060708090a0b0c0d0e0f",
     "000102",
     "5b376580ae2f19afe7219ceef172756f",
     "5b376580ae2f19afe7219cee",
   },
   {
     "000102030405060708090a0b0c0d0e0f",
     "000102030405060708090a0b0c0d0e0f",
     "d2a246fa349b68a79998a4394ff7a263",
     "d2a246fa349b68a79998a439",
   },
   {
     "000102030405060708090a0b0c0d0e0f",
     "000102030405060708090a0b0c0d0e0f10111213",
     "47f51b4564966215b8985c63055ed308",
     "47f51b4564966215b8985c63",
   },
   {
     "000102030405060708090a0b0c0d0e0f",
     "000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f",
     "f54f0ec8d2b9f3d36807734bd5283fd4",
     "f54f0ec8d2b9f3d36807734b",
  },
  {
     "000102030405060708090a0b0c0d0e0f",
     "000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f2021",
     "becbb3bccdb518a30677d5481fb6b4d8",
     "becbb3bccdb518a30677d548",
  },
};

main()
{
 int i=0;
 for (i=0; i< sizeof(tVectors)/sizeof(tVectors[0]); i++) {
      printf("\n val:%s",  tVectors[i].key );
      printf("\n val:%s",  tVectors[i].message );
      printf("\n val:%s",  tVectors[i].mac );
      printf("\n val:%s",  tVectors[i].mac_96 );
 }

  getchar();

}


