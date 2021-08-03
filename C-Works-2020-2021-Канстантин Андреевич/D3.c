/**
 #include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int main(int argc,char* argv[]){
   int fd[2];
   pid_t pid,pid_s;
   if(pipe(fd)<0){
       return 1;
   }
   pid=fork();
   if(pid<0){
       perror("fork");
       return 0;
   }else if (pid>0){
       int k;
       while (scanf("%d",&k)!=EOF) {
           write(fd[1], &k, sizeof(int));
       }
       close(fd[1]);
       wait(NULL);
   }else{
       close(fd[1]);
       int sd[2];
       if(pipe(sd)<0){
           return 1;
       }
       int r,min=99999,max=-999999;
       pid_s=fork();
       if(pid_s<0){
           return 1;
       }else if (pid_s>0){
           while (read(fd[0], &r, sizeof(int))>0){
               write(sd[1], &r, sizeof(int));
               if(r<min){
                   min=r;
               }
           }
           fflush(stdout);
           printf("%d ",min);
       }else{
           close(sd[1]);
           while (read(sd[0], &r, sizeof(int))>0) {
               if(r>max){
                   max=r;
               }
           }
           fflush(stdout);
           printf("%d",max);
           wait(NULL);
       }
       close(sd[1]);
       close(sd[0]);
       close(fd[0]);
   }
   return 0;
}
*/
