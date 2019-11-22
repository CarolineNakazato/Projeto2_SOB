#include <stdio.h>
#include <stdlib.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <sys/types.h>  // open()
#include <sys/stat.h>   // open()
#include <fcntl.h>      // open()
#include <unistd.h> //syscall() e close()
#include <string.h>

int main(int argc, char ** argv)
{
    if(argc == 2){
        int fd;
        switch(argv[1][0]){
            case 'w':
                fd = open("out_teste.txt",O_WRONLY|O_CREAT,0640);//O_RDWR  = read and write
                const char * txt = "ZAZAZAZA";
                if(fd != -1){
                    syscall(546, fd, txt, 8); //faz o write_crypt
                    close(fd);
                }
                break;
            
            case 'r':
                fd = open("out_teste.txt", O_RDONLY);
                char * r = (char *)malloc(8);
                if(fd != -1){
                    syscall(547, fd, r, 8); //faz o read_crypt
                    close(fd);
                }
                printf("String READ=%s\n",r);
                free(r);
                break;
            
            default:
                printf("USE O ARGUMENTO r ou w\n");
                break;
        }
    }
    else{
        printf("USE O ARGUMENTO r ou w\n");
    }

   return 0;
}