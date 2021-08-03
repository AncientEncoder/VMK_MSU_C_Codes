/**
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/msg.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/ipc.h>
#include<string.h>
struct msgbuf{
    long mtype;
    char data[256];
    long cnt_max;
};
int main(int argc,char*argv[]){
    int F_Ctrl;
    pid_t pid1,pid2,pid3;
    struct msgbuf message;
    if ((F_Ctrl=creat("F_ctrl", 0666))<0) {
        return 1;
    }else{
        close(F_Ctrl);
    }
    key_t key=ftok("F_Ctrl",'h');
    int msgid=msgget(key, IPC_CREAT | 0666);
    if(msgid<0){
        perror("msgget"); return 2;
    }
    //------------------ctr endl--------------
    if ((pid1=fork())<0) {
        perror("fork");
        return 3;
    }else if(pid1==0){
        //son1
        char msg1[256];
        char sonbuf1[2];
        sonbuf1[1]='\0';
        sonbuf1[0]='a';
        msgrcv(msgid,&message,sizeof(message),1,0);
        strcpy(msg1,message.data);
        while (1==1) {
            message.mtype =2;
            strcat(msg1,sonbuf1);
            strcpy(message.data,msg1);
            if (sonbuf1[0]=='z') {
                sonbuf1[0]='a';
            }else{
                sonbuf1[0]++;
            }
            msgsnd(msgid, &message, sizeof(message), 0);
            
            //---CTRL loop-----
            if (strlen(msg1)==message.cnt_max) {
                message.mtype=5;
                msgsnd(msgid, &message, sizeof(message), 0);
                exit(0);
            }
            msgrcv(msgid,&message,sizeof(message),4,0);
            strcpy(msg1,message.data);
            if (strlen(msg1)==message.cnt_max) {
                message.mtype=2;
                msgsnd(msgid, &message, sizeof(message), 0);
                exit(0);
            }
        }
        return 0;
    }else{
        if ((pid2=fork())<0) {
            perror("fork");
            return 3;
        }else if (pid2==0){
            //son2
            char msg2[256];
            char sonbuf2[2];
            sonbuf2[0]='0';
            sonbuf2[1]='\0';
            while (1==1) {
                msgrcv(msgid, &message, sizeof(message), 2, 0);
                //aus son1;
                message.mtype=3;
                strcpy(msg2, message.data);
                //Wenn größer als cnt_max, senden
                if (strlen(msg2)==message.cnt_max) {
                    msgsnd(msgid, &message, sizeof(message), 0);
                    exit(0);
                }
                strcat(msg2, sonbuf2);
                strcpy(message.data, msg2);
                if (sonbuf2[0]=='9') {
                    sonbuf2[0]='0';
                }else{
                    sonbuf2[0]++;
                }
                msgsnd(msgid, &message, sizeof(message), 0);
                //---CTRL loop-----
                if (strlen(msg2)==message.cnt_max) {
                    message.mtype=5;
                    msgsnd(msgid, &message, sizeof(message), 0);
                    exit(0);
                }
            }
            return 0;
        }else{
            if ((pid3=fork())<0) {
                perror("fork");
                return 3;
            }else if(pid3==0){
                //son3
                char msg3[256];
                char sonbuf3[2];
                sonbuf3[1]='\0';
                sonbuf3[0]='A';
                while (1==1) {
                    msgrcv(msgid, &message, sizeof(message),3 , 0);
                    //aus son2;
                    message.mtype=4;
                    strcpy(msg3, message.data);
                    //Wenn größer als cnt_max, senden
                    if (strlen(msg3)==message.cnt_max) {
                        message.mtype=4;
                        msgsnd(msgid, &message, sizeof(message), 0);
                        exit(0);
                    }
                    strcat(msg3, sonbuf3);
                    strcpy(message.data, msg3);
                    if (sonbuf3[0]=='Z') {
                        sonbuf3[0]='A';
                    }else{
                        sonbuf3[0]++;
                    }
                    msgsnd(msgid, &message, sizeof(message), 0);
                    //---CTRL loop-----
                    if (strlen(msg3)==message.cnt_max) {
                        message.mtype=5;
                        msgsnd(msgid, &message, sizeof(message), 0);
                        exit(0);
                    }
                }
                return 0;
            }else{
                //father
                scanf("%ld",&message.cnt_max);
                message.mtype=1;
                message.data[0]='\0';
                msgsnd(msgid, &message, sizeof(message), 0);
                msgrcv(msgid, &message, sizeof(message),5,0);
                printf("%s\n",message.data);
                wait(NULL);
                wait(NULL);
                wait(NULL);
                msgctl(msgid, IPC_RMID, 0);
                return 0;
            }
        }
    }
    return 0;
}
*/
