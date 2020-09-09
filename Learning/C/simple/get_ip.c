#include <sys/ioctl.h>
#include <net/if.h>
#include <netinet/in.h>

#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <arpa/inet.h>

main()
{
struct ifreq ifr;
int fd;

if ( fd = socket(AF_INET, SOCK_DGRAM, 0) < 0 ) {
	printf("Error..\n");
	exit(1);
}

strncpy(ifr.ifr_name, "eth0", IFNAMSIZ-1);


