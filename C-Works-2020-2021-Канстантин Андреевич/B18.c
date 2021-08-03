/**
#include <stdio.h>
#define max_x 5
#define max_y 5
int findDiag(int (*index)[max_x]);
int comp(int (*index)[max_x]);
int main(int argc,char *argv[]){
    int mart[max_y][max_x];
    for(int y=0;y<max_y;y++){
        for(int x=0;x<max_x;x++){
            scanf("%d",&mart[y][x]);
        }
    }
    printf("%d",comp(mart));
    return 0;
}


int findDiag(int (*index)[max_x]){
    int avg=0;
    for(int n=0;n<max_y;n++){
        avg= *(*(index+n)+n)+avg;
    }
    avg=avg/max_y;
    return avg;
}

int comp(int (*index)[max_x]){
    int sum_big=0;
    int diag=findDiag(index);
    for(int y=0;y<max_y;y++){
        for(int x=0;x<max_x;x++){
            if(*(*(index+y)+x)>diag){
                sum_big++;
            }
        }
    }
    return sum_big;
}
*/
