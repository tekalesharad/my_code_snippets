
#include <stdio.h>
#include <string.h>

#define SERIAL_NUM "$SN"
#define MINT_ID    "$MINT-ID"

#define STRING4 "LB.ALu.$MINT-ID.F1."
#define STRING1 "LB-ALU-$SN-F1."
#define STRING2 "LB-ALu-$-F1."
#define STRING3 "LB-ALu-$MINT-ID-F1."
#define STRING5 "LB-ALU-SN-F1."
#define STRING ""

#define SERIAL "12345678"
#define MINT "12.34.56.78"

void formulate_unique_id(char * out, char * str, char* substr, int len, char* val )
{
  char *postfix;  
  char prefix[32];  
  printf("str %s\n", str);

  strncpy(prefix, str, (substr-str)) ;
  prefix[substr-str] = '\0'; 
  printf("prefix %s\n", prefix);
  
  postfix = substr + len; 
  printf("postfix %s\n", postfix);

  strcpy( out, prefix);
  strcat( out, val);
  strcat( out, postfix);
  printf("postfix  : %s  \n", out );
  return out;

}


main() {

 char * ptr;
 char * ptr1 = STRING;
 char out[64]= "Sharad";
 if ((ptr = strchr( ptr1, '$')) != NULL) {

   if (( ptr = strstr( ptr1, MINT_ID )) != NULL) {
     formulate_unique_id(out, ptr1, ptr, strlen(MINT_ID), MINT);
   }
   else if (( ptr = strstr(ptr1, SERIAL_NUM )) != NULL) {
     formulate_unique_id(out, ptr1, ptr, strlen(SERIAL_NUM), SERIAL);
   }
   

   printf("%s\n", out);
#if 0
//     postfix =  ptr + strlen(SERIAL_NUM); 
     //strncpy(prefix, ptr1, (ptr-ptr1)  ) ;
//     memcpy( prefix, ptr1, (ptr-ptr1) ) ;
//     prefix[ptr-ptr1] = '\0'; 
//     strcat(prefix, SERIAL);
//     strcat(prefix, postfix);
//     printf("pre-fix  : %s %d  \n", prefix, strlen(prefix) );
//     printf("postfix  : %s  \n", postfix );
#endif
  }

 else
   strcpy(out, ptr1);

   printf("Doesnt name %s\n", out);
}
