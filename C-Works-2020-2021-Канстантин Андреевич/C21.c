/**
 #include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int main(int argc,char*argv[]){
    int fd1,fd2;
    int count;
    char buf;
    if(argc<=2){
        return 1;
    }
    if((fd1=open(argv[1], O_RDONLY))==-1){
        return 1;
    }
    if((fd2=creat(argv[2], 0644))==-1){
        return 1;
    }
    count=1;
    while (read(fd1, &buf, 1)>0) {
        if(buf=='\n'){
            count=0;
        }
        if(count<51){
            write(fd2, &buf, 1);
            count++;
        }
    }
    close(fd1);
    close(fd2);
    return 0;
}
*/
