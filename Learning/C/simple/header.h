#include <stdio.h>
#define uint8_t unsigned char
#define uint16_t unsigned int
struct Hello {
int a;
int b;
};

struct tlv_payload {
  uint8_t type;
  uint8_t len;
  char val[];
};

// UDP message header
struct protocol_hdr {
  uint8_t     msg_type;
  uint8_t     id;
  uint16_t    len;
};

extern struct Hello hello;
