/**
 #include<stdio.h>
int Strlen(char *c);
int main(int argc,char *argv[]){
    char index[1000];
    gets(index);
    printf("%d",Strlen(index));
}
int Strlen(char *c){
    int sum=0;
    while(c[sum]!='\0'){
        sum++;
    }
    return sum;
}
*/
