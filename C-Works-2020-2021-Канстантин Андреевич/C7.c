/**
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #define last 10000
 int main(int argc,char* argv[]){
     char index[last];
     gets(index);
     int x=0;
     while (1==1) {
         if(index[x]!=' '||index[x]=='\0'){
             break;
         }
         x++;
     }
     while (1==1) {
         if((index[x-1]!=' '||index[x]!=' ')&&index[x]!='\0'){
             printf("%c",index[x]);
         }
         if(index[x]=='\0'){
            break;
     }
         x++;
 }
     return 0;
 }

 */
/**
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #define last 10000
 void delete(char index[]);
 int main(int argc,char* argv[]){
     char index[last];
     gets(index);
     delete(index);
     int x=0;
     while (1==1) {
         if(index[x]!='\0'){
             printf("%c",index[x]);
         }else{
             break;
         }
         x++;
     }
     return 0;
 }
 void delete(char index[]){
     char indexcpy[last];
      int x=0,y=0;
         while (1==1) {
             if(index[x]!=' '||index[x]=='\0'){
                 break;
             }
             x++;
         }
         while (1==1) {
             if((index[x-1]!=' '||index[x]!=' ')&&index[x]!='\0'){
                 indexcpy[y]=index[x];
                 y++;
             }
             if(index[x]=='\0'){
                break;
         }
             x++;
     }
     indexcpy[y]='\0';
     strcpy(index, indexcpy);
 }


 */
