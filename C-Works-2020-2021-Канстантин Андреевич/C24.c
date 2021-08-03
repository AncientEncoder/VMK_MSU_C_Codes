/**
 #include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main(int argc,char* argv[]){
    if (argc<3) {
        return 1;
    }
    int fd,fo;
    int min=0, a=0,present=0;
    long len1,len2,lenf;
    long min_p,present_p;
    fd = open(argv[1], O_RDWR);
    if(fd==-1){
        //fprintf(stderr, "Can't open file 1\n");
        return 1;
    }
    len1=read(fd, &a, sizeof(int));
    if((len1>0)&&(len1<=sizeof(int))){
        while ((len1>0)&&(len1<=sizeof(int))) {
            if(len1!=sizeof(int)){
                fo=creat(argv[2],O_RDWR);
                if(fo==-1){
                    //fprintf(stderr, "Can't open file 2\n");
                    return 1;
                }
                close(fo);
                return 0;
            }
            len1=read(fd, &a, sizeof(int));
        }
        lseek(fd, 0, SEEK_SET);
    }
    else{
        fo=creat(argv[2],O_RDWR);
        if(fo==-1){
            //fprintf(stderr, "Can't open file 2\n");
            return 1;
        }
        return 0;
    }
    while(1==1){
        len1=read(fd, &a, sizeof(int));
        //printf("%d %d\n",a,min);
        if((len1>0)&&(len1<=sizeof(int))){
            present_p=lseek(fd, 0, SEEK_CUR)-sizeof(int);
            present=a;
            min=a;
            min_p=present_p;
            while (1==1) {
                len2=read(fd, &a, sizeof(int));
                if ((len2>0)&&(len2<=sizeof(int))) {
                    //printf("%d %d\n",a,min);
                    if(a<min){
                        min=a;
                        min_p=lseek(fd, 0, SEEK_CUR)-sizeof(int);
                    }
                }else{
                    break;
                }
        }
            lseek(fd, present_p+sizeof(int), SEEK_SET);
            lenf=read(fd, &a, sizeof(int ));
            if((lenf>0)&&(lenf<=sizeof(int))){
                lseek(fd, present_p, SEEK_SET);
                write(fd, &min, sizeof(int));
                lseek(fd, min_p, SEEK_SET);
                write(fd, &present, sizeof(int));
                lseek(fd, present_p+sizeof(int), SEEK_SET);
            }else{
                break;
            }
        }else{
            break;
        }
    }
    fo=creat(argv[2],O_RDWR);
    if(fo==-1){
        //fprintf(stderr, "Can't open file 2\n");
        return 1;
    }
    lseek(fd, 0, SEEK_SET);
    while (1==1) {
        len1=read(fd, &a, 1);
        if((len1>0)&&(len1<=1)){
            write(fo, &a, 1);
        }else{
            break;
        }
    }
    close(fd);
    close(fo);
    return 0;

}
*/
