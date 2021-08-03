/**#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
volatile int flag=0;
volatile int fgs=1;
void SHL(int s){
    signal(SIGUSR1, SHL);
    flag=1;
}
int main(int argc,char*argv[]){
    fgs=1;
    pid_t pid,pid_gs;
    int fd[2],cnt=0;
    int cnt_Max;
    pid_t pid_f=getpid();
    scanf("%d",&cnt_Max);
    int count;
    count=(cnt_Max<=2 ) ? 0 : 2;
    if(pipe(fd)<0){
        perror("fork");
        return 1;
    }
    signal(SIGUSR1,SHL);
    if ((pid=fork())<0) {
        perror("fork");
        return 2;
    }else if (pid==0){
        if((pid_gs=fork())<0){
            perror("fork");
            return 1;
        }else if(pid_gs==0){
            if (cnt==cnt_Max) {
                exit(0);
            }
            pid_t pid=getppid();
            while (cnt<cnt_Max-count) {
                if(!flag){
                    pause();
                }
                flag=0;
                read(fd[0], &cnt, sizeof(int));
                printf("grandson %d\n",cnt++);
                fflush(stdout);
                write(fd[1], &cnt, sizeof(int));
                kill(pid, SIGUSR1);
                if (cnt_Max<=2){
                 close (fd[0]);
                 close (fd[1]);
                 exit(0);
                }
                if (cnt_Max<=2){
                    close (fd[0]);
                    close (fd[1]);
                    exit(0);
                }
            }
            close(fd[0]);
            close(fd[1]);
            return 0;
        }
            pause();
            pid_t pid_f=getppid();
            while (cnt<cnt_Max) {
                if(!flag){
                    pause();
                }
                flag=0;
                read(fd[0], &cnt, sizeof(int));
                printf("son %d\n",cnt++);
                fflush(stdout);
                write(fd[1], &cnt, sizeof(int));
                if (cnt==cnt_Max) {
                    
                }
                if (fgs==1) {
                    fgs=0;
                    kill(pid_f, SIGUSR1);
                }else{
                    fgs=1;
                    kill(pid_gs, SIGUSR1);
                }
                if (cnt_Max<=2){
                    close (fd[0]);
                    close (fd[1]);
                    exit(0);
                }
            }
            close(fd[0]);
            close(fd[1]);
            return 0;
            
    }else{
        write(fd[1], &cnt, sizeof(int));
        kill(pid, SIGUSR1);
        if (cnt_Max<2){
            close (fd[0]);
            close (fd[1]);
            exit(0);
        }
        while (cnt<cnt_Max-count) {
            if(!flag){
                pause();
            }
            flag=0;
            read(fd[0], &cnt, sizeof(int));
            printf("father %d\n",cnt++);
            fflush(stdout);
            write(fd[1], &cnt, sizeof(int));
            if (cnt_Max<=2){
                close (fd[0]);
                close (fd[1]);
                exit(0);
            }
            kill(pid, SIGUSR1);
        }
        close(fd[0]);
        close(fd[1]);
        return 0;
    }
    
    return 0;
}
*/
