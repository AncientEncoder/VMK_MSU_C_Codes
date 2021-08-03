/**
 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc,char* argv[]){
    char *array=NULL;
    char **ar2d=NULL;
    char aparm;
    int index=0;
    int count=1;
    array=(char*)malloc(sizeof(char));
    while (1==1) {
        scanf("%c",&aparm);
        if(aparm==' '){
        }else goto nspace;
    }
    while (1==1) {
        scanf("%c",&aparm);
    nspace:
        if(index!=0){
            if((array[index-1]==' ')&&(aparm==' ')){
                continue;
            }
        }
        if(aparm==' '&&array[index-1]!=' '){
            count++;
        }
        if(aparm!='\n'){
            array=(char*)realloc(array, sizeof(char)*(index+2));
            if(array==NULL){
                printf("-1");
                return 0;
            }
            array[index]=aparm;
            index++;
        }else{
            if(array[index-1]==' '){
                int sssssss=1;
                while(array[index-sssssss]==' '){
                    count--;
                    sssssss++;
                }
            }
            array[index]='\0';
            break;
        }
    }
    int lins=count;
    ar2d=(char**)malloc(sizeof(char*)*count);
    if(ar2d==NULL){
        printf("-1");
        return 0;
    }
    //apply for memo
    index=0;
    count=0;
    int liner=0;
    
    while(1==1){
        if(array[index]!=' '&&array[index]!='\0'){
            count++;
            index++;
        }
        if(array[index]==' '){
            ar2d[liner]=(char*)malloc(sizeof(char)*(count+2));
            if(ar2d[liner]==NULL){
                printf("-1");
                break;
            }
            count=0;
            index++;
            liner++;
        }
        if(array[index]=='\0'){
            ar2d[liner]=(char*)malloc(sizeof(char)*(count+2));
            if(ar2d[liner]==NULL){
                printf("-1");
                break;
            }
            break;
        }
    }
    //copy
    index=0;
    count=0;
    for(int n=0;n<lins;n++){
        count=0;
        while(array[index]!=' '&&array[index]!='\0'){
            ar2d[n][count]=array[index];
            index++;
            count++;
        }
        if(array[index]==' '){
            ar2d[n][count]='\0';
        }
        if(array[index]=='\0'){
            ar2d[n][count]='\0';
            break;
        }
        index++;
        
    }
    //out
    count=0;
    int min=0;
    for(int pr=0;pr<lins;pr++){
        for(int i=0;i<lins;i++){
            if(strcmp(ar2d[min], ar2d[i])>0){
                min=i;
                count=0;
            }
        }
        while (ar2d[min][count]!='\0') {
            printf("%c",ar2d[min][count]);
            ar2d[min][count]='~';
            count++;
        }
        printf("\n");
    }
    for(int n=0;n<lins;n++){
        free(ar2d[n]);
        ar2d[n]=NULL;
    }
    free(ar2d);
    free(array);
    return 0;
}
*/
