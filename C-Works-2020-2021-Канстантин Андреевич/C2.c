/**
 #include<stdio.h>
#include <stdlib.h>
#define INT_MAX 2147483647
int main(int argc,char *argv[]){
    int *num=NULL;
    char *index=NULL;
    num=(int*)malloc(sizeof(int));
    if(num==NULL){
        printf("-1");
        return 0;
    }
    index=(char*)malloc(sizeof(char));
    if(index==NULL){
        printf("-1");
        return 0;
    }
    //-----------------
    char aparm=' ';
    int index_c=0;
    while(1==1){
        scanf("%c",&aparm);
        if(aparm!=('\n')){
            index=(char*)realloc(index, sizeof(char)*(index_c+2));
            index[index_c]=aparm;
            index_c++;
        }else{
            index[index_c]='\0';
            break;
        }
    }
    int p=0;
    int numb=0;
    int index_num=0;
    while(index[p]!='\0'){
        if((index[p]<='9')&&(index[p]>='0')){
            numb=(int)(index[p]-'0')+numb;
            if((index[p+1]<='9')&&(index[p+1]>='0')){
                numb=numb*10;
            }else{
                num=(int*)realloc(num, sizeof(int)*(index_num+1));
                if(num==NULL){
                    printf("-1");
                    return 0;
                }
                num[index_num]=numb;
                numb=0;
                index_num++;
            }
        }
        p++;
    }
    //out
    int min=INT_MAX;
    int min_addr=0;
    for(int a=0;a<index_num;a++){
        for(int d=0;d<index_num;d++){
            if(num[d]<min){
                min_addr=d;
                min=num[d];
            }
        }
        printf("%d ",min);
        num[min_addr]=INT_MAX;
        min=INT_MAX;
    }
    free(num);
    free(index);
    return 0;
}
*/
