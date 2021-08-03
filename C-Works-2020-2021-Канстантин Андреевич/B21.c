/**
#include <stdio.h>
#include <stdlib.h>
int calc(int n,int k);
long long int fact(int n);
void out(int **thr,int index);
int main(int argc,char*argv[]){
    int index;
    int **thr=NULL;
    scanf("%d",&index);
    index++;
    thr=(int**)malloc(sizeof(int*)*index);
    if(thr==NULL){
        printf("-1");
        return -1;
    }
    for (int n=0; n<index; n++){
        thr[n]=malloc(sizeof(int)*(n+1));
        if(thr[n]==NULL){
            printf("-1");
            return -1;
        }
    }
    for(int i=0;i<index;i++){
        for(int j=0;j<i+1;j++){
            thr[i][j]=calc(i,j);
        }
    }
    out(thr,index);
    for(int i=0;i<index;i++){
        free(thr[i]);
        thr[i] =NULL;
    }
    free(thr);
    thr= NULL;
    return 0;
}

long long int fact(int n){
    if (n==1||n==0){
        return 1;
        }else{return fact(n-1)*n;
    }
}
int calc(int n,int k){
 long long int aparm;
 aparm=fact(n)/(fact(k)*fact(n-k));
 return (int)aparm;
}
void out(int **thr,int index){
    for(int i=0;i<index;i++){
        for(int j=0;j<i+1;j++){
            printf("%d ",thr[i][j]);
        }
    printf("\n");
    }
}
*/
