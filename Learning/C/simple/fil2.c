

#include <stdio.h>
void fun( char* info) 
{
printf("1");
char * pdata = info;
printf("2");
//char *arg = "FromUI from-ui sftp://sharadLsymbol@192.168.8.177/test False";
char *start_buf = strstr(pdata, "-----BEGIN");
char *end_buf = strstr(pdata, "-----END");
char cert[3000] = {0};

  while (1) {
   char * cert_buf_start = strstr( pdata, "-----BEGIN" );
   if(!cert_buf_start)
        break;

   char * cert_buf_end = strstr( pdata, "-----END" );
    //Sanity check ; ideally we must find  END for each BEGIN 
    if(!cert_buf_end)
        break;
    //Increase the ptr by end string '-----END CERTIFICATE-----'
    cert_buf_end +=strlen ("-----END CERTIFICATE-----");
    cert_buf_end ++ ;//copy new line 
    unsigned int cert_len = cert_buf_end-cert_buf_start;
    //Now increase input ptr to find next cert
    pdata += (cert_buf_end - pdata);
    memcpy(&cert, cert_buf_start, cert_len);
    }

printf("DBG3... %s \n", cert);

}


int main(){
char *arg = "FromUI from-string -----BEGIN CERTIFICATE-----\
MIIEojCCA4qgAwIBAgIQIxgbIOZYmrVMeljs0YK4BTANBgkqhkiG9w0BAQUFADBO\
MRMwEQYKCZImiZPyLGQBGRYDY29tMSAwHgYKCZImiZPyLGQBGRYQS0Nyb2xhLVNv\
bHV0aW9uczEVMBMGA1UEAxMMS0MtU09MVVRJT05TMB4XDTEyMDcwNTA5NTQ1MloX\
DTE3MDcwNTEwMDMzMVowTjETMBEGCgmSJomT8ixkARkWA2NvbTEgMB4GCgmSJomT\
8ixkARkWEEtDcm9sYS1Tb2x1dGlvbnMxFTATBgNVBAMTDEtDLVNPTFVUSU9OUzCC\
ASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAJXy5fDspYWZd8J7kw9168Ls\
hD00tpED8qM+nqzd4VSa3oSw+S+JndTStuq/5SHBs/JEKCTMS6O4PO3kqEKD9qas\
l/Ouu+4/nqPfCQ9WvZl7eMfyHG1c8Jp7OqA4zQdvM46YuhxfWL20qVzuN60JoRBZ\
KdbaDgDgelkv3YeWivzSyPfvOCWDNvnPSiP6pKwpek3hq9rdqMdyG4dDE5BeIiFv\
wLMsIQ+H1AyBgqZD3Tm/1r+bpjp8NcnX4QWqytwmJYEI5ZflDu/h529nqVDX1hbR\
NSU+t83kafCfBB8tanBqhSTJqruvgsvsM1qK35/rEt8R2bD1Xvdqb1JDBzgevJ0C\
AwEAAaOCAXowggF2MAsGA1UdDwQEAwIBhjAPBgNVHRMBAf8EBTADAQH/MB0GA1Ud\
DgQWBBSHUHekXuNCXaN6IMvaF09Jlhw4DDCCASMGA1UdHwSCARowggEWMIIBEqCC\
AQ6gggEKhoHBbGRhcDovLy9DTj1LQy1TT0xVVElPTlMsQ049QmFuZGl0U2VydmVy\
LENOPUNEUCxDTj1QdWJsaWMlMjBLZXklMjBTZXJ2aWNlcyxDTj1TZXJ2aWNlcyxD\
Tj1Db25maWd1cmF0aW9uLERDPUtDcm9sYS1Tb2x1dGlvbnMsREM9Y29tP2NlcnRp\
ZmljYXRlUmV2b2NhdGlvbkxpc3Q/YmFzZT9vYmplY3RDbGFzcz1jUkxEaXN0cmli\
dXRpb25Qb2ludIZEaHR0cDovL2JhbmRpdHNlcnZlci5rY3JvbGEtc29sdXRpb25z\
LmNvbS9DZXJ0RW5yb2xsL0tDLVNPTFVUSU9OUy5jcmwwEAYJKwYBBAGCNxUBBAMC\
AQAwDQYJKoZIhvcNAQEFBQADggEBAGeUcuuQdoWY7u78NnSwlvNW3kVHSeRdnntc\
D0coBqy5/HMhl8LWn1e6V6AJdTa4ufoVf/vLJYVPHZCfL0dXFAhfXyE9d9s6kxaS\
RozPVQs4DEg4oyWj5X50lRthxm4+wAX74nWNTsWylz7xuB2d4MzmvIXxvrO3ozxZ\
nV1OXTcVQex5v+dL5YZJsW4vDJJkPfHg6YmI5KLXKhMYXJMSvIKS/j7ly/DmS1hT\
I1G0YJEH2sp5lRZzZfu2aiRQS2qGiGIchEYVmzXaPjQxtsUbDe1lBiRFZx6GHFYo\
J6qaiCQIU8Dva+aq41Ng7hjP3yyMH62oEaj9Fq/qt+Ub17j8wUo=\
-----END CERTIFICATE----- False";

//char * memPtr = (char *)malloc(3000 * sizeof(char));
//memcpy(memPtr, arg, strlen(arg));
//fun(memPtr);
fun(arg);

}
