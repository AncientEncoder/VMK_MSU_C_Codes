/**
 #include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int main(int argc,char* argv[]){
    int fd[2];
    pid_t pid;
    if(pipe(fd)<0){
        return 1;
    }
    pid=fork();
    if(pid<0){
        perror("fork");
        return 0;
    }else if (pid>0)
        int k;
        while (scanf("%d",&k)!=EOF) {
            write(fd[1], &k, sizeof(int));
        }
        close(fd[1]);
    }else{
        close(fd[1]);
        int n,sum=0;
        while (read(fd[0], &n, sizeof(int))>0){
            sum=sum+n;
        }
        printf("%d",sum);
        close(fd[0]);
    }
    return 0;
}
*/
