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
//learn deutsch so all func. , names are in deuesch))
//loschen=delete
//Hinzufugen=addd
node* loschen(node *del);
node* Hinzufugen(node *end);
int main(int argc,char *argv[]){
    node aparm;
    node *end=NULL;
    while(scanf("%20s",aparm.Inhalt)!=EOF){
        end=Hinzufugen(end);
        strcpy(end->Inhalt, aparm.Inhalt);
    }
    while (end!=NULL) {
        printf("%s\n",end->Inhalt);
        end=loschen(end);
    }
    return 0;
}
node* loschen(node *del){
    node* aparm=NULL;
    aparm=del->letzter;
    free(del);
    return aparm;
}
node* Hinzufugen(node *end){
    node *aparm=NULL;
    aparm=malloc(sizeof(node));
    if(aparm==NULL){
        printf("-1");
        exit(0);
    }
    aparm->letzter=end;
    aparm->bisherige=NULL;
    return aparm;
}
*/
