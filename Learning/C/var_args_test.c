#include <stdio.h>
#include <stdarg.h>

#define TOT_SIZE 50

void print_str(char *buf, const char *fmt, ...)
{
    va_list vptr;

    va_start(vptr, fmt);
    vsnprintf(buf, TOT_SIZE, fmt, vptr);
    va_end(vptr);

}

main()
{
    char buf[TOT_SIZE];

     //print_str(buf, "%s %s %s %d %c", "sharad", "chandra", ".tekale", 100, 'C');
     sprintf(buf, "%s %s %s %d %c", "sharad", "chandra", ".tekale", 100, 'C');
    printf("%s", buf);
}

