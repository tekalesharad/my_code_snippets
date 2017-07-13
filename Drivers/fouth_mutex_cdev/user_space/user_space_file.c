#include <stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

#define CHAR_DEV_NAME "/dev/test_cdev"

int main()
{

  int ret;
  char theBuf[100];
  int fd;


  fd = open(CHAR_DEV_NAME, O_RDWR);
  if(fd<0){
      printf("unable to open "CHAR_DEV_NAME" device file: %s\n", strerror(errno));
      return errno;
  }

  printf("data to send to kernel:\n");
  scanf("%[^\n]%*c", theBuf);
  //scanf("%s", theBuf);
  printf("US:%s\n", theBuf);
  ret = write(fd, theBuf, strlen(theBuf)); 

  if (ret < 0) {
    printf("failed to write message: %d", errno);
    return errno;

   }

   printf("Press ENTER to read back from the device...\n");
   getchar();

   memset(theBuf, 0, sizeof(theBuf));
   ret = read(fd, theBuf, sizeof(theBuf));
   if (ret < 0) {
    printf("failed to write message: %d", errno);
    return errno;

   }
 
   printf("buffer received:%s\n", theBuf);

   return 0;

}

