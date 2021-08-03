/**#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
volatile int flag=0;
void SHL(int s){
    signal(SIGUSR1, SHL);
    flag=1;
}
int main(int argc,char*argv[]){
    pid_t pid;
    int fd[2],cnt=0;
    int cnt_Max;
    scanf("%d",&cnt_Max);
    if(pipe(fd)<0){
        perror("fork");
        return 1;
    }
    signal(SIGUSR1,SHL);
    if ((pid=fork())<0) {
        perror("fork");
        return 2;
    }else if (pid==0){
        pid_t pid=getppid();
        while (cnt<cnt_Max) {
            if(!flag){
                pause();
            }
            flag=0;
            read(fd[0], &cnt, sizeof(int));
            printf("son %d\n",cnt++);
            fflush(stdout);
            write(fd[1], &cnt, sizeof(int));
            kill(pid, SIGUSR1);
        }
        close(fd[0]);
        close(fd[1]);
        return 0;
    }else{
        write(fd[1], &cnt, sizeof(int));
        kill(pid, SIGUSR1);
        while (cnt<cnt_Max) {
            if(!flag){
                pause();
            }
            flag=0;
            read(fd[0], &cnt, sizeof(int));
            printf("father %d\n",cnt++);
            fflush(stdout);
            write(fd[1], &cnt, sizeof(int));
            kill(pid, SIGUSR1);
        }
        close(fd[0]);
        close(fd[1]);
        return 0;
    }
    
    return 0;
}
*/
