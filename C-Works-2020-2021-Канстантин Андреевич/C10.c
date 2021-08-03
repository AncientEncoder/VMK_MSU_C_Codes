/**
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <math.h>
 typedef struct vector{
     double x;
     double y;
     double z;
 }vector;
 double cos_angle_vectors(vector *v1, vector *v2);
 int main(int argc,char *argv[]){
     vector v1;
     vector v2;
     scanf("%lf%lf%lf%lf%lf%lf",&v1.x,&v1.y,&v1.z,&v2.x,&v2.y,&v2.z);
     printf("%.4lf",cos_angle_vectors(&v1, &v2));
     return 0;
 }
 double cos_angle_vectors(vector *v1, vector *v2){
     double cos_r=0;
     cos_r=(v1->x*v2->x+v1->y*v2->y+v1->z*v2->z)/(sqrt(v1->x*v1->x+v1->y*v1->y+v1->z*v1->z)*sqrt(v2->x*v2->x+v2->y*v2->y+v2->z*v2->z));
     if(cos_r>=-1&&cos_r<=1){
         cos_r=cos_r;
     }else{
         cos_r=-2;
     }
     return cos_r;
 }

 */
