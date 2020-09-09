#include <stdio.h>
#include <time.h>
#include <string.h>

char s[64];
//static void time_now( char *s)
static char * time_now()
{
     time_t t = time(NULL);
     struct tm *tm = localtime(&t);
    strftime(s, 64, "%c", tm);
    return s;
}


int main()
{
    //time_now(&s);
    printf("%s\n", time_now());
    sleep(1);
    printf("%s\n", time_now());
    sleep(1);
    printf("%s\n", time_now());
   return 0;

}
