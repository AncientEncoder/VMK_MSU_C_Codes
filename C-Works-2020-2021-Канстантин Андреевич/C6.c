/**
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 int main(int argc,char* argv[]){
     char index[1000];
     gets(index);
     int i=0;
     while (i<=1000){
         if(index[i]=='\0'){
             break;
         }
         if(index[i]=='C'&&index[i+1]=='a'&&index[i+2]=='o'){
             i=i+3;
             printf("Ling");
         }else{
             printf("%c",index[i]);
             i++;
         }
 }
     return 0;
 }

 */
