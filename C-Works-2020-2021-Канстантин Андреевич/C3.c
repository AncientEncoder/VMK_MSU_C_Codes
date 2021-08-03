/**
 #include<stdio.h>
 int Strlen(char *c);
 int main(int argc,char *argv[]){
     char index[100000];
     gets(index);
     Strlen(index);
 }
 int Strlen(char *c){
     int sum=0,flag=0;
     while(c[sum]!='\0'){
         if(c[sum]!=' '){
             for(int n=0;n<sum;n++){
                 if(c[n]==c[sum]){
                     flag=1;
                 }
             }
             if(flag==0){
                 printf("%c",c[sum]);
             }else{
                 flag=0;
             }
         }
         sum++;
     }
     return sum;
 }

 */
