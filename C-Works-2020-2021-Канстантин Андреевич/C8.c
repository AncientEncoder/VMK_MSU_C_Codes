/**

 
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #define last 10000
 int is_palindrom(char s[]);
 int main(int argc,char* argv[]){
     char index[last];
     gets(index);
     int flag;
     flag=is_palindrom(index);
     if(flag==1){
         printf("YES");
     }else{
         printf("NO");
     }
     return 0;
 }
 int is_palindrom(char index[]){
     char aparm;
     char* pt=NULL;
     int x=0,flag=0,ang=0;
     while (1==1) {
         if(index[x]=='\0'){
             break;
         }
         aparm=index[x];
         if(aparm!='\0'){
             if((aparm<='z'&&aparm>='a')||(aparm>='A'&&aparm<='Z')){
                 ang++;
                 pt=strchr(index+1+x, aparm);
                 if(pt==NULL){
                     flag++;
                 }else{
                     *pt='-';
                     index[x]='-';
                 }
                 pt=NULL;
             }
         }
         x++;
     }
     if(flag<=1&&ang!=0){
         flag=1;
     }else{
         flag=0;
     }
     return flag;
 }
 
 */
