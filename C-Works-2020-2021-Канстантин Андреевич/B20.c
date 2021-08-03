/**
 #include <stdio.h>
#include <stdlib.h>
int main(int argc,char* argv[]){
    int *index=NULL;
    int sum_all,sum_d=0;
    int aparm;
    scanf("%d",&sum_all);
    index=(int*)malloc((sizeof(int))*sum_all);
    if(index==NULL){
        return -1;
    }
    for(int n=0;n<sum_all;n++){
        scanf("%d",&aparm);
        if((aparm/10)%10==0){
            sum_d++;
        }
        index[n]=aparm;
    }
    aparm=0;
    int *sec_array=(int*)malloc((sizeof(int))*sum_d);
    for(int n=0;n<sum_all;n++){
        if((index[n]/10)%10==0){
            sec_array[aparm]=index[n];
            aparm++;
        }
    }
    for (int n; n<sum_d; n++) {
        printf("%d ",sec_array[n]);
    }
    free(index);
    free(sec_array);
    return 0;
}
*/
