/**
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
int main(int argc,char *argv[]){
    int fd_c;
    if (argc<4) {
        return 1;
    }
    fd_c = open(argv[4],O_CREAT | O_RDWR,0664);
    if(-1 == fd_c)
        return 1;
    dup2(fd_c,STDOUT_FILENO);
    close(fd_c);
    execlp(argv[1],argv[1],argv[2],argv[3],  NULL);
    return 0;
}
*/
