/**
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
 typedef struct baum{
     int inhalt;
     struct baum *links;//left
     struct baum *recht;//right
 }baum;
 //left smaller right bigger
 //baum* einfugen(int num,baum *p);
 int suchen(int ziele,baum *p);
 void freigeben(baum *wurzel);
 int main(int argc,char*argv[]){
     int index;
     int aparm=-1008611;
     baum* jetzt=NULL;
     baum *wurzel=NULL;
     if(argc<2){
         printf("NO\n");
         return 2;
     }else{
         index=atoi(argv[1]);
         if(index==0){
             return -1;
         }
     }
     while (scanf("%d",&aparm)!=EOF) {
         if(wurzel==NULL){
             wurzel=malloc(sizeof(baum));
             wurzel->inhalt=aparm;
             wurzel->links=NULL;
             wurzel->recht=NULL;
             jetzt=wurzel;
         }else{
             while (1==1) {
                 if(aparm>jetzt->inhalt){
                     if(jetzt->recht!=NULL){
                         jetzt=jetzt->recht;
                     }else{
                         break;
                     }
                 }else if(aparm<jetzt->inhalt){
                     if(jetzt->links!=NULL){
                         jetzt=jetzt->links;
                     }else{
                         break;
                     }
                 }
             }
             if(aparm>jetzt->inhalt){
                 jetzt->recht=malloc(sizeof(baum));
                 jetzt=jetzt->recht;
                 jetzt->inhalt=aparm;
                 jetzt->links=NULL;
                 jetzt->recht=NULL;
             }else if(aparm<jetzt->inhalt){
                 jetzt->links=malloc(sizeof(baum));
                 jetzt=jetzt->links;
                 jetzt->inhalt=aparm;
                 jetzt->links=NULL;
                 jetzt->recht=NULL;
             }
             jetzt=wurzel;
         }
     }
     int flag=suchen(index, wurzel);
     if(flag==1){
         printf("YES");
     }else{
         printf("NO");
     }
     freigeben(wurzel);
     return 0;
 }
 int suchen(int ziele,baum *p){
     if(p==NULL){
         return 0;
     }
     int flag=0;
     baum *pt=p;
     while (1==1) {
         if(pt!=NULL){
             if(ziele>pt->inhalt){
                 if(pt->recht!=NULL){
                 pt=pt->recht;
                 }else{
                     break;
                 }
             }else if (ziele<pt->inhalt){
                 if(pt->links!=NULL){
                     pt=pt->links;
                 }else{
                     break;
                 }
             }else{
                 if(pt->inhalt==ziele){
                 flag=1;
                 break;
                 }
                 break;
             }
         }
     }
     return flag;
 }
 void freigeben(baum *wurzel){
     if(wurzel==NULL){
         exit(0);
     }
     baum *index=wurzel;
     if(index->links!=NULL){
         freigeben(index->links);
     }
     if(index->recht!=NULL){
         freigeben(index->recht);
     }
     free(index);
 }

 */
