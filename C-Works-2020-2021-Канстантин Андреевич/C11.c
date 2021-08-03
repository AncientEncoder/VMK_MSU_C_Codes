/**
 //мой алгоритм не работает поэтому........


 #include <stdio.h>
 #include <string.h>
 #define MAX 20
 typedef struct NODE
 {
     char color[20];
     int count;
 }NODE;

 int add(NODE *node, char *buf, int *num);

 int main(int argc ,char* argv[]) {
     NODE node[MAX];
     char buf[20];
     int num_colours = 0, i;
     char exist = 0;

     while(scanf("%19s", buf) != EOF)
     {
         exist = 0;
         for(i = 0; i< num_colours; i++)
         {
             if(strcmp(node[i].color, buf) == 0)
             {
                 node[i].count++;
                 exist = 1;
             }
         }
         if(!exist) {
             if(add(node+num_colours, buf, &num_colours))
                 break;
         }
     }

     for(i=0; i<num_colours; i++)
     {
         printf("%s %d\n", node[i].color, node[i].count);
     }
     return 0;
 }

 int add(NODE *node, char *buf, int *num)
 {
     if(*num >= MAX)
         return 1;
     strcpy(node->color, buf);
     node->count=1;
     (*num)++;
     return 0;
 }

 */
