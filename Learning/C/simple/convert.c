#include <stdio.h>


void fun(int str );
void fun(int str ) {
//    printf("Val: %s\n", str);
    printf("Val: %d\n", str);
}

int main(int argc, char * argv[]) {
  int val;
  fun(atoi(argv[1])); 
}



#if 0
void fun(const char * str );
void fun(const char * str ) {
    printf("Val: %s\n", str);
}

int main(int argc, char * argv[]) {

  fun(argv[1]); 
}
#endif


