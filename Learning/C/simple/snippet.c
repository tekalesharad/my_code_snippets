#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <openssl/bio.h>
#include <openssl/evp.h>

int main(int argc,char* argv[]){
    if(argc != 5) {
        printf("Usage: der2pem_simple derfile pemfile \"-----BEGIN CERTIFICATE-----\" \"-----END CERTIFICATE-----\"\n");
        return 1;
    }
    // to create a buffer as small as possible
    // we need the size of the input file
    struct stat fistat;
    if(stat(argv[1],&fistat)<0) {
        printf("derfile not found\n");
        return 1;
    }
    // open the derfile
    FILE* derfile = fopen(argv[1],"r");
    if (!derfile){
        printf("can't open derfile\n");
        return 1;
    }
    char buff[fistat.st_size];
    printf("Size: %d\n", fistat.st_size);
    // write the derfile to the buffer
    fread(buff,fistat.st_size,1,derfile);
    fclose(derfile);
    // open pemfile
    FILE* pemfile = fopen(argv[2],"w+");
    if (!pemfile){
        printf("can't open or create pemfile\n");
        return 1;
    }
    // create a BIO context with base64 filter
    BIO* bio_base64 = BIO_new(BIO_f_base64());
    // create a BIO for the pemfile
    BIO* bio_out = BIO_new_fp(pemfile,BIO_NOCLOSE);
    // write the header
    BIO_write(bio_out,argv[3],strlen(argv[3]));
    BIO_write(bio_out,"\n",1);
    // combine bio_base64->bio_out : enables base64 filter
    bio_out = BIO_push(bio_base64,bio_out);
    // write the buffer
    BIO_write(bio_out,buff,fistat.st_size);
    // flush before disable base64 filter
    BIO_flush(bio_out);
    // uncombine bio_base64 X bio_out : disables base64 filter
    bio_out = BIO_pop(bio_base64);
    // write the footer
    BIO_write(bio_out,argv[4],strlen(argv[4]));
    // flush to free the BIO resources
    BIO_flush(bio_out);
    BIO_free_all(bio_out);
    fclose(pemfile);
}
