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
int suchen(baum *p);
void freigeben(baum *wurzel);
int main(int argc,char*argv[]){
   // int index;
    int aparm=-1008611;
    baum* jetzt=NULL;
    baum *wurzel=NULL;
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
    int flag=suchen(wurzel);
    return 0;
}
int suchen(baum *p){
    if(p==NULL){
        return 0;
    }
    int min_1=0,min_2=99999;
    baum *pt=p;
    while (1==1) {
        if(pt->links!=NULL){
            min_2=pt->inhalt;
            pt=pt->links;
        }else{
           min_1=pt->inhalt;
            if(pt->recht!=NULL){
                pt=pt->recht;
                //min_2=pt->recht;
                while (1==1) {
                    if(pt->links!=NULL){
                        pt=pt->links;
                    }else{
                        if(pt->inhalt<min_2){
                            min_2=pt->inhalt;
                        }
                        break;
                    }
                }
            }
            break;
        }
        
    }
    printf("%d %d",min_1,min_2);
    return 0;
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
