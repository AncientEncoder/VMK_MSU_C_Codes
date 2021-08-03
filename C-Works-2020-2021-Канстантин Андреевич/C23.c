/**
 
 #include <fcntl.h>
 #include <unistd.h>
 #include<stdio.h>
 int main(int argc,char* argv[]){
     int fd;
     long min, a;
     long max_p, min_p;
     if(argc<1){
         return 1;
     }
     fd = open(argv[1], O_RDWR);
     if(fd==-1){
         fprintf(stderr, "Can't open file data.bin\n");
         return 1;
     }
     if(read(fd, &a, sizeof(long)) == sizeof(long)){
         min = a;
         min_p = 0;
     }
     else
         return 0;


     while(read(fd, &a, sizeof(long)) == sizeof(long)){
         if(a<min){
             min = a;
             min_p = lseek(fd, 0, SEEK_CUR) - sizeof(long);
         }
         
     }
     min=-min;
     lseek(fd, min_p, SEEK_SET);
     write(fd, &min, sizeof(long));
     close(fd);
     return 0;
 }

 */
