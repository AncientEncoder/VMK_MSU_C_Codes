/**
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

 typedef struct Color {
     int rgb;  //w=100;b=010;o=001;
     int sum;
 }Color;
 int main(int argc,char*argv[]){
     char index[1000];
     Color white;
     Color black;
     Color other;
     white.rgb=100;
     white.sum=0;
     black.rgb=10;
     black.sum=0;
     other.rgb=1;
     other.sum=0;
     gets(index);
     int n=0,p=0;
     while(index[n]!='\0'){
         if(p==20){
             break;
         }
         if(index[n]==' '){
             n++;
             continue;
         }
         if(index[n]=='W'&&index[n+1]=='H'&&index[n+2]=='I'&&index[n+3]=='T'&&index[n+4]=='E'&&(index[n+5]==' '||index[n+5]=='\0')){
             white.sum++;
             n=n+5;
         }else if (index[n]=='B'&&index[n+1]=='L'&&index[n+2]=='A'&&index[n+3]=='C'&&index[n+4]=='K'&&(index[n+5]==' '||index[n+5]=='\0')){
             black.sum++;
             n=n+5;
         }else{
             while (index[n]!=' '&&index[n]!='\0') {
                 n++;
             }
             other.sum++;
         }
         p++;
     }
     printf("WHITE %d\nBLACK %d\nOTHER %d",white.sum,black.sum,other.sum);
     return 0;
 }
 */
