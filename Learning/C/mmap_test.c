#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#define F_SIZE 4096

//char * map_region()
//{

//}

void write_to_region(char * file_mem)
{
   char *p="Hello_world";
   sprintf((char *)file_mem, "%s", p);
  
}
#if 1
void read_from_region(const char* file_mem)
{
   char local_ptr[50];
   strncpy( local_ptr, file_mem, strlen(file_mem));
   printf("read_info:%s\n", local_ptr);
}
#endif
//int delete_from_region()
//{

//}


int main()
{
    //FILE * fp = fopen("./test_mmap.txt", "w+");
    int fd = open("./test_mmap.txt", O_RDWR|O_CREAT, S_IRUSR|S_IWUSR);
    void *file_mem;
    
    if(fd == -1) {
        printf("unable to open file. return\n");
        return;
    }
   lseek(fd, F_SIZE+1, SEEK_SET);
   write(fd, "", 1);
   lseek(fd, 0, SEEK_SET); 
   // void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);
   
    file_mem = mmap(NULL, F_SIZE, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0 );
 
    //printf("%p\n", (char*)file_mem); 
 
   if ((char *)file_mem == MAP_FAILED) {
        perror("mmap");
        printf("unable to map meomory\n");
        return;
   }
   close(fd);

   write_to_region(file_mem);
   sleep(2);
#if 1 
   read_from_region(file_mem);
   sleep(2);
#endif
   //int munmap(void *addr, size_t length);
   munmap(file_mem, F_SIZE);
  
   return 0;
}
