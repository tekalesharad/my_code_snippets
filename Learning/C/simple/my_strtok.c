#include <stdio.h>
#include <string.h>
main()
{

char tunnel_session_name[20]="all test";
char tunnel_name[32] = "";
char session_name[32] = "";

#if 0
printf("(Tunnel Name %s Session Name %s)\n",tunnel_name, session_name);
strncpy(tunnel_name, strtok(tunnel_session_name, " "), 31);
printf("(Tunnel Name %s Session Name %s)\n",tunnel_name, session_name);
strncpy(session_name, strtok(NULL, " "), 31);

tunnel_name[31] = '\0';
session_name[31] = '\0';

printf("(Tunnel Name %s Session Name %s)\n",tunnel_name, session_name);
#endif

}
