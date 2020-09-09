#include <stdio.h>
#include "header.h"

char tx_buf[100];
char rx_buf[100];


void print_val( char *rx_buf  )
{
	//memcpy(&rx_buf, &buf, 10);
	struct protocol_hdr *phdr = (struct protocol_hdr *)rx_buf;

	printf("Header: %d %d %d\n", phdr->msg_type, phdr->id, phdr->len );

	struct tlv_payload *tlv = (struct tlv_payload *) (rx_buf + sizeof(struct protocol_hdr));

	printf("TLV:  %d %d %s\n", tlv->type, tlv->len, tlv->val);

	tlv = tlv->val + tlv->len;

	printf("TLV:  %d %d %s\n", tlv->type, tlv->len, tlv->val);
}


int main()
{
	int tlv_len = 0;

	struct protocol_hdr *phdr = (struct protocol_hdr *)tx_buf;

	phdr->msg_type = 10;
	phdr->id = 29;

	struct tlv_payload *tlv = (struct tlv_payload *) (tx_buf + sizeof(struct protocol_hdr));

	tlv->type=1;
	memcpy(&tlv->val, "SHaRaD", 6);
	tlv->len = 6;
	tlv_len = sizeof(tlv->len) + sizeof(tlv->type) + 6;
	tlv = tlv->val + tlv->len;

	tlv->type=3;
	memcpy(&tlv->val, "ABCDEF", 6);
	tlv->len = 6;
	tlv_len += sizeof(tlv->len) + sizeof(tlv->type) + 6;

	phdr->len = tlv_len + sizeof(phdr->msg_type) + sizeof(phdr->id);

	print_val( tx_buf );

	return 0;
}
