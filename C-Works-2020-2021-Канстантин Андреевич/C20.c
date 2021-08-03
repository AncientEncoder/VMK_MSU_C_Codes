/**
 #include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
int main(int argc,char*argv[]){
    int fl1,fl2,n;
    char buf[2014];
    struct stat s;
    if(argc<3){
        return 3;
    }
    fl1=open(argv[1], O_RDONLY);
    if(fl1==-1){
        return 1;
    }
    stat(argv[1], &s);
    fl2=creat(argv[2], s.st_mode);
    if(fl2==-1){
        return 2;
    }
    while ((n=read(fl1, buf, 1024))>0) {
        write(fl2, buf, n);
    }
    close(fl1);
    close(fl2);
    return 0;
}
*/
