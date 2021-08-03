/**
#include <stdio.h>
#include <stdlib.h>
int main(int arvc,char* argv[]){
    int index;
    int sum=0;
    int *pt=NULL;
    while ( scanf("%d",&index)!=EOF) {
        sum++;
        if(pt==NULL){
            pt=(int*)(malloc(sizeof(int)));
            if(pt==NULL){
                printf("-1");
                return 0;
            }
            pt[sum-1]=index;
        }
        if(pt!=NULL){
            pt=(int*)realloc(pt, sizeof(int)*(sum));
            if(pt==NULL){
                printf("-1");
                return 0;
            }
            pt[sum-1]=index;
        }
    }
    for(int n=sum-1;n>=0;n--){
        printf("%d ",pt[n]);
    }
    free(pt);
    pt=NULL;
    return 0;
}
*/
