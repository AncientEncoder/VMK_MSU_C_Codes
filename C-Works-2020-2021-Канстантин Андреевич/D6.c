 #include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
int main(int argc,char *argv[]){
    int fd[2],fs[2];
    if(pipe(fd)<0){
        return 1;
    }
    if(pipe(fs)<0){
        return 1;
    }
       int pid1,pid2,pid3;
    pid1=fork();
    if(pid1<0){
        return 2;
    }else if(pid1==0){
        dup2(fd[1], 1);
        close(fd[0]);
        close(fd[1]);
        close(fs[0]);
        close(fs[1]);
        execlp(argv[1], argv[1],argv[2],argv[3],NULL);
        fprintf(stderr, "_BAD_EXEC 0x000000");
        return 3;
    }else{
        pid2=fork();
        if(pid2<0){
            return 2;
        }else if(pid2==0){
            dup2(fd[0],0);
            dup2(fs[1], 1);
            close(fd[0]);
            close(fd[1]);
            close(fs[0]);
            close(fs[1]);
            execlp(argv[4], argv[4],argv[5],NULL);
            fprintf(stderr, "_BAD_EXEC 0x00001");
            return 3;
            }else{
                pid3=fork();
                if (pid3<0) {
                    printf("error");
                    return 1;
                }else if (pid3==0){
                    dup2(fs[0], 0);
                    close(fs[1]);
                    close(fs[0]);
                    close(fd[0]);
                    close(fd[1]);
                    execlp(argv[6], argv[6],NULL);
                    fprintf(stderr, "_BAD_EXEC 0x00002");
                    return 3;
                }
            }
    }
    close(fd[0]);
    close(fd[1]);
    close(fs[0]);
    close(fs[1]);
    wait(NULL);
    wait(NULL);
    wait(NULL);
    return 0;
}
