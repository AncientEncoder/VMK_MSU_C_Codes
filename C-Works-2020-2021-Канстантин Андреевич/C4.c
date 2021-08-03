/**
 #include<stdio.h>
 int Strlen(char *c);
 int main(int argc,char *argv[]){
     int flag=0;
     char index[100000];
     int num=0;
     int index_max=0;
     int max=0;
     int index_aparm=0;
     int aparm;
     gets(index);
     while(index[num]!='\0'){
         index_aparm=num;
         aparm=num;
         while((index[num]!=' ')&&(index[num]!='\0')){
             num++;
         }
         aparm=num-aparm;
         if(aparm>max){
             flag=0;
             index_max=index_aparm;
             max=aparm;
         }
         if((aparm==max)&&(index_max!=index_aparm)){
             flag=1;
         }
         num++;// jump out of ' '
     }
     while((index[index_max]!=' ')&&(index[index_max]!='\0')&&(flag==0)){
         printf("%c",index[index_max]);
         index_max++;
     }
     return 0;
 }
 
*/
