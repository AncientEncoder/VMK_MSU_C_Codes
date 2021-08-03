/**
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxLong 20
typedef struct node{
    char Inhalt[MaxLong];
    struct node* bisherige;
    struct node* letzter;
}node;
node *nue(node *ende);
node *vergleichen(node *start,char *index);
int main(int argc,char *argv[]){
    node aparm;
    node *agt=NULL;
    char index[20];
    node *ende=NULL;
    gets(index);
    while(scanf("%20s",aparm.Inhalt)!=EOF){
            ende=nue(ende);
            strcpy(ende->Inhalt, aparm.Inhalt);
        }
    if(ende==NULL){
        printf("empty");
        return 0;
    }
    while (ende->bisherige!=NULL) {
        ende=ende->bisherige;
    }
   agt=vergleichen(ende,index);
    ende=agt;
    if(agt==NULL){
        printf("empty");
        return 0;
    }
    agt=NULL;
    while (ende!=NULL) {
        printf("%s ",ende->Inhalt);
        agt=ende;
        ende=ende->letzter;
        free(agt);
    }
    return 0;
}
node *nue(node *ende){
    node *aparm=NULL;
        aparm=malloc(sizeof(node));
        if(aparm==NULL){
            printf("-1");
            exit(0);
        }
    if(ende!=NULL){
        ende->letzter=aparm;
    }
        aparm->bisherige=ende;
        aparm->letzter=NULL;
        return aparm;
}
node *vergleichen(node *start,char* index){
    node *bis=NULL,*let=NULL;
    node *inp=start;
    while (start!=NULL) {
        if(strcmp(index, start->Inhalt)==0){
            bis=start->bisherige;
            let=start->letzter;
            if(start->bisherige==NULL&&start->letzter==NULL){
                return NULL;
            }else{
                if(start->bisherige==NULL){
                    inp=let;
                    let->bisherige=NULL;
                }else{
                    if(let!=NULL){
                    let->bisherige=bis;
                    }
                    bis->letzter=let;
                }
                free(start);
            }
            break;
        }
        start=start->letzter;
    }
    return inp;
}
*/
