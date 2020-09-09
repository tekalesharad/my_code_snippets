#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <openssl/bio.h>
#include <openssl/evp.h>

#include <openssl/x509v3.h>
#include <openssl/x509.h>
#include <openssl/pem.h>
#include <openssl/bio.h>

 //manual conversion

#if 0 //working
static void build_name (char * cn){
   int i =0, j =0 ;
   char *subname[100];
   if( strchr(cn, '/') == NULL)
       return;
   
   for (i =0 ; (subname[i] !='\0') ; i++ ) {
     if (i ==0 && subname[i] == '/' ) continue ;
     if ( i !=0 && subname[i] == '/' ) { 
          cn[j] = ',';
          cn[j += 1] = ' ';
     }
     else
       cn[j] = subname[i];  
     j++;
    }
   printf("subname:%s len:%d\n", subname, strlen(subname));

}
#endif
#if 1 //working
static void build_name (char * cn){
   int i =0, j =0 ;
   char subname[512];
   if( strchr(cn, '/') == NULL)
       return;
   strncpy(subname, cn, strlen(cn));
   printf("subname:%s len:%d\n", subname, strlen(subname));
//   memset(cn, 0, strlen(cn));
   for (i =0 ; (subname[i] !='\0') ; i++ ) {
     if (i ==0 && subname[i] == '/' ) continue ;
     if ( i != 0 && subname[i] == '/' ) { 
          cn[j++] = ',';
          cn[j++] = ' ';
     }
     else
       cn[j++] = subname[i];  
    }
    cn[j] = '\0';

}
#endif

static void use_bio_for_sub_name(X509* cert) {
    char *dataStart = NULL;
    char *subjectString = NULL;
    long nameLength ;
    X509_NAME *subject;
   if( !( subject = X509_get_subject_name( cert )))
        fprintf( stderr, "X509_get_subject_name failed" );


      BIO *subjectBio = BIO_new(BIO_s_mem());

   // Now, put the subject line into the BIO.
    X509_NAME_print_ex(subjectBio, subject, 0, XN_FLAG_RFC2253);
 
   // Obtain a reference to the data and copy out
    // just the length of the data.
    nameLength = BIO_get_mem_data(subjectBio, &dataStart);
    subjectString = (char *)malloc(100 * sizeof(char)) ;
    memset(subjectString, 0x00 , nameLength + 1);
    memcpy(subjectString, dataStart, nameLength);
    printf("OP: %s\n", subjectString);
    free(subjectString);
}


static void use_ssl_api(X509* cert) {
 
   X509_NAME *subjName;
    unsigned char *utf8;
    int idx;
 int length; 
  char sub_name[512];

X509_NAME_ENTRY *entry;
 ASN1_STRING *entryData; 
   if( !( subjName = X509_get_subject_name( cert )))
        fprintf( stderr, "X509_get_subject_name failed" );

    idx = X509_NAME_get_index_by_NID( subjName, NID_commonName, -1 );
    entry = X509_NAME_get_entry( subjName, idx );
    entryData = X509_NAME_ENTRY_get_data( entry );
    length = ASN1_STRING_to_UTF8( &utf8, entryData );
    printf( "CN value: %s\n", utf8 );
    printf( "CN length: %d\n", length );
    sprintf(sub_name, "%s", utf8);
    idx = X509_NAME_get_index_by_NID( subjName, NID_organizationName, -1 );
    entry = X509_NAME_get_entry( subjName, idx );
    entryData = X509_NAME_ENTRY_get_data( entry );
    length = ASN1_STRING_to_UTF8( &utf8, entryData );
    sprintf(sub_name + strlen(sub_name), "%s", utf8);
    printf( "Or value: %s\n", utf8 );
    printf( "Or length: %d\n", length );

    idx = X509_NAME_get_index_by_NID( subjName, NID_countryName, -1 );
    entry = X509_NAME_get_entry( subjName, idx );
    entryData = X509_NAME_ENTRY_get_data( entry );
    length = ASN1_STRING_to_UTF8( &utf8, entryData );
    sprintf(sub_name + strlen(sub_name), "%s", utf8);
    printf( "Cc value: %s\n", utf8 );
    printf( "Cc length: %d\n", length );



    printf( "sub_name %s\n", sub_name );

    OPENSSL_free( utf8 );

}

int main(int argc,char* argv[]){
    if(argc < 2) {
        printf("Usage: pem_file\"\n");
        return 1;
    }

    X509 *x509;
    FILE *pemfile = NULL;
             char cn[100] = "/CN=9772-WISC-L-B4-C7-99-6C-88-3E";
    if((pemfile = fopen(argv[1],"r")) == NULL ) 
        return;
    x509 = PEM_read_X509(pemfile, NULL, NULL, NULL); 
    if (x509 != NULL) {
        switch (argv[2][0] ) {
           case 'b':
             use_bio_for_sub_name(x509);
             break;
           case 's':
             use_ssl_api(x509);
             break;
           case 'm':
//             cn ="/CN=9772-WISC-L-B4-C7-99-6C-88-3E"; 
             printf("123 cn:%s\n", cn); 
             //cn = X509_NAME_oneline(X509_get_subject_name(x509), 0, 0);
             build_name(cn);
             printf("cn:%s\n", cn); 
             //OPENSSL_free(cn);
            
             break;
           default:
             use_ssl_api(x509);
             break;
       }
        X509_free(x509);
   }
} 
