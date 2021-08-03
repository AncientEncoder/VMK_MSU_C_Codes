/**
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include<sys/wait.h>
int main(int argc,char* argv[]){
    int fd[2];
    pid_t pid;
    if(pipe(fd)<0){
        return 1;
    }
    int index=0;
    scanf("%d",&index);
    //write(fd[1], &index, sizeof(int));
    pid=fork();
    for(int i=1;i<=index;i++){
        if(pid<0){
         perror("fork");
         return 1;
        }
        else if(pid>0)
         wait(NULL);
        else if(pid==0)
        {
            if(i==index){
                printf("%d\n", i);
            }else{
                printf("%d ", i);
            }
         fflush(stdout);
         pid=fork();
         wait(NULL);
        }
    }
    close(fd[1]);
    close(fd[0]);
    return 0;
}
*/
