/**
#include <stdio.h>
#include <stdlib.h>
int main(int arvc,char* argv[]){
    char index;
    int sum=0;
    char *pt=NULL;
    while ( scanf("%c",&index)!=EOF) {
        if(index=='\n'){
            continue;
        }
        sum++;
        if(pt==NULL){
            pt=(char*)(malloc(sizeof(int)));
            if(pt==NULL){
                printf("-1");
                return 0;
            }
            pt[sum-1]=index;
        }
        if(pt!=NULL){
            pt=(char*)realloc(pt, sizeof(int)*(sum));
            if(pt==NULL){
                printf("-1");
                return 0;
            }
            pt[sum-1]=index;
        }
    }
    sum++;
    int end=sum-1;
    //char aparm_start,aparm_end;
    for(int n=0;n<end;n++){
        if(pt[n]>='a'&&pt[n]<='z'){
            index=pt[n];
            for(int i=n-1;i>=0;i--){
                if(i<0){
                    break;
                }
                if(pt[i]>='a'&&pt[i]<='z'){
                    pt[i+1]=index;
                    break;
                }
                pt[i+1]=pt[i];
            }
            if(pt[0]>='A'&&pt[0]<='Z'){
                pt[0]=index;
            }
        }
    }
    for(int n=0;n<sum-1;n++){
        printf("%c",pt[n]);
    }
    free(pt);
    pt=NULL;
    return 0;
}
*/
