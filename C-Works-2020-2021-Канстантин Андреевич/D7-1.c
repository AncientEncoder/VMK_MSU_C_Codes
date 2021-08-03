/**
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/wait.h>
#include<fcntl.h>
int main(int argc,char *argv[]){
        int fd[2], semid, cnt =0;
        int Cnt_Max, ff;
        struct sembuf P1 = {0, -1, 0};
        struct sembuf V1 = {0, 1, 0};
        struct sembuf P2 = {1, -1, 0};
        struct sembuf V2 = {1, 1, 0};
        key_t key;
        pid_t pid;
        scanf("%d", &Cnt_Max);
        ff=creat("file", 0666);
        if(ff < 0) {
            perror("creat");
            return 5;}
        key = ftok("file", 'd');
        if (key<0) {
            perror ("key");
            return 1;}
        close(ff);
        semid = semget (key, 2, IPC_CREAT | 0666);
         if (semid<0) {
             perror ("semget");
             return 2;}

        semctl(semid, 0, SETVAL, 0);
        semctl(semid, 1, SETVAL, 0);

        if(pipe(fd) < 0) {
            perror ("pipe");
            return 3;}

        if ((pid = fork()) < 0) {
            perror("fork");
            return 4;}
        else if (pid>0){
                write(fd[1], &cnt, sizeof(int));
                semop(semid, &V1, 1);
                while(cnt<Cnt_Max){
                        semop(semid, &P2, 1);
                        read(fd[0], &cnt, sizeof(int));
                        printf("father %d\n", cnt++);
                        fflush(stdout);
                        write(fd[1],&cnt,sizeof(int));
                        semop(semid, &V1,1);
                }
                close(fd[0]); close(fd[1]);
                wait(NULL);
                
        }else{
                while(cnt<Cnt_Max){
                        semop(semid, &P1, 1);
                        read(fd[0], &cnt, sizeof(int));
                        printf("son %d\n", cnt++);
                        fflush(stdout);
                        write(fd[1],&cnt, sizeof(int));
                        semop(semid, &V2, 1);
                }
                close(fd[0]); close(fd[1]);
                return 0;

        }

        semctl(semid, 0, IPC_RMID, 0);
        return 0;

}
*/
        
