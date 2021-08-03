/**#include<stdio.h>
 #include<stdlib.h>
 #include<fcntl.h>
 #include<sys/msg.h>
 #include<unistd.h>
 #include<sys/wait.h>
 #include<sys/ipc.h>
 #include<string.h>
#include<sys/shm.h>
#include<sys/sem.h>
 int main(int argc,char *argv[]){
     long max_index;
     int shmid,semid,F_Ctrl;
     long *shmaddr;
     struct sembuf V1={0,1,0};
     struct sembuf P1={0,-1,0};
     struct sembuf V2={1,1,0};
     struct sembuf P2={1,-1,0};
     struct sembuf V3={2,1,0};
     struct sembuf P3={2,-1,0};
     pid_t son1,son2;
     if ((F_Ctrl=creat("F_Ctrl", 0666))<0) {
         return 1;
     }else{
         close(F_Ctrl);
     }
     key_t key=ftok("F_Ctrl",'h');
     semid = semget(key,3,IPC_CREAT|0666);
     scanf("%ld",&max_index);
     if ((son1=fork())<0) {
         perror("fork");
         return 1;
     }else if (son1==0){
         //son1
         semop(semid, &P1, 1);
         int now_index=2;
         //now_index=sizeof(shmaddr)/sizeof(shmaddr[0])-1;
         shmid = shmget(key,max_index*sizeof(int),IPC_CREAT|0666);
         shmaddr = shmat(shmid,NULL,0);
         while (now_index<max_index) {
             semop(semid, &P1, 1);
             shmaddr[now_index]=shmaddr[now_index-1]+shmaddr[now_index-2];
             now_index=now_index+2;
             semop(semid, &V2, 1);
         }
         
         //to go son2 shutdown son 1
         semop(semid, &V3, 1);
         shmdt(shmaddr);
         return 0;
     }else{
         if ((son2=fork())<0) {
             perror("fork");
             return 0;
         }else if(son2==0){
             //son2
             semop(semid, &P2, 1);
             int now_index=3;
             shmid = shmget(key,max_index*sizeof(int),IPC_CREAT|0666);
             shmaddr = shmat(shmid,NULL,0);
             while (now_index<max_index) {
                 semop(semid, &P2, 1);
                 shmaddr[now_index]=shmaddr[now_index-1]+shmaddr[now_index-2];
                 now_index=now_index+2;
                 semop(semid, &V1, 1);
             }
             semop(semid, &V3, 1);
             shmdt(shmaddr);
             return 0;
         }else{
             //father
             shmid = shmget(key,max_index*sizeof(int),IPC_CREAT|0666);
             if(shmid < 0){
                 perror("shmid");
                 return 2;
             }
             shmaddr = shmat(shmid,NULL,0);
             if(shmaddr==(void *)-1){
                 perror("shmat");
                 return 3;
             }
             if (max_index<=2) {
                 if (max_index==1) {
                     printf("0 ");
                     semop(semid, &V2, 1);
                     semop(semid, &V1, 1);
                     wait(NULL);
                     wait(NULL);
                     shmdt(shmaddr);
                     shmctl(shmid,IPC_RMID,NULL);
                     semctl(semid,0,IPC_RMID,0);
                     fflush(stdout);
                     return 0;
                 }else{
                     printf("0 1 ");
                     fflush(stdout);
                     semop(semid, &V2, 1);
                     semop(semid, &V1, 1);
                     wait(NULL);
                     wait(NULL);
                     shmdt(shmaddr);
                     shmctl(shmid,IPC_RMID,NULL);
                     semctl(semid,0,IPC_RMID,0);
                     return 0;
                 }
             }else{
                 shmaddr[0]=0;
                 shmaddr[1]=1;
                 semop(semid, &V2, 1);
                 semop(semid, &V1, 1);
                 semop(semid, &V1, 1);
             }
             semop(semid, &P3, 1);
             int index=0;
             while (index<max_index) {
                 printf("%ld ",shmaddr[index]);
                 index++;
             }
             fflush(stdout);
         }
     }
     wait(NULL);
     wait(NULL);
     shmdt(shmaddr);
     shmctl(shmid,IPC_RMID,NULL);
     semctl(semid,0,IPC_RMID,0);
     return 0;
 }
*/
