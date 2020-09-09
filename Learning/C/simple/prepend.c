#include <stdio.h>
#include <strings.h>
char sender_name[100];
main()
{
char *sreialnum = "1234566";
char * sendername= "CN=Motorola.com";
memcpy(sender_name,sreialnum,strlen(sreialnum));
memcpy(sender_name+strlen(sreialnum),"-",1);
memcpy(sender_name+strlen(sreialnum)+1,sendername,strlen(sendername));
printf("Sender_name = %s\n", sender_name);
}

