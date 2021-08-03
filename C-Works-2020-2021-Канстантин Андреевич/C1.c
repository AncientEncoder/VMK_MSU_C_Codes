/**
 #include<stdio.h>
int Strlen(char *c);
int main(int argc,char *argv[]){
    char index[100000];
    gets(index);
    Strlen(index);
}
int Strlen(char *c){
    int sum=0;
    int small=0;
    int big=0;
    while(c[sum]!='\0'){
        if(c[sum]<='z'&&c[sum]>='a'){
            small++;
        }if(c[sum]<='Z'&&c[sum]>='A'){
            big++;
        }
        sum++;
    }
    printf("%d %d",small,big);
    return sum;
}
*/
