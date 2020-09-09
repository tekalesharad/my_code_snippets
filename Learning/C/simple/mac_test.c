#include <sys/types.h> 
#include <sys/socket.h> 
#include <stdio.h> 
#include <sys/ioctl.h> 
#include <net/if.h>
#include <netinet/in.h>
int main(int argc,char** argv)
{
int fd;
struct ifreq ifbuf;
struct sockaddr_in sa;
unsigned char* hwaddr;
int i = 0;
char mac[6];
fd = socket(AF_INET, SOCK_DGRAM, 0);

strcpy(ifbuf.ifr_name,argv[1]?argv[1]:"eth0");

ioctl(fd,SIOCGIFHWADDR,&ifbuf);

for ( i =0; i< 6; i++ )
	mac[i] = ifbuf.ifr_hwaddr.sa_data[i];

printf("%s\n", (unsigned char*) mac);
hwaddr = (unsigned char*) ifbuf.ifr_hwaddr.sa_data;

printf("%2.2X:%2.2X:%2.2X:%2.2X:%2.2X:%2.2X\n",hwaddr[0],hwaddr[1],hwaddr[2],hwaddr[3],hwaddr[4],hwaddr[5]);
#if 0
{
    char mac[19]; /* one extra for terminating '\0'; 
                     You may want to make it a little larger
                     still, just to be sure. */

    sprintf(mac, " %02x:%02x:%02x:%02x:%02x:%02x", 
        (unsigned char)ifbuf.ifr_hwaddr.sa_data[0],
        (unsigned char)ifbuf.ifr_hwaddr.sa_data[1],
        (unsigned char)ifbuf.ifr_hwaddr.sa_data[2],
        (unsigned char)ifbuf.ifr_hwaddr.sa_data[3],
        (unsigned char)ifbuf.ifr_hwaddr.sa_data[4],
        (unsigned char)ifbuf.ifr_hwaddr.sa_data[5]);

    printf("%s\n", mac); // string was "printed" to mac array!

}
#endif
{
  5c
ffffffd9
ffffff98
4c
4
27

}
return 0;
}
