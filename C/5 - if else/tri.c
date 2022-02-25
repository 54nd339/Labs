#define m(a1,b1,a2,b2) (b2-b1)/(a2-a1)
#include <stdio.h>
int main(){
    float x1,y1,x2,y2,x3,y3,m1,m2,m3;
    printf("Enter the coordinate of first point : ");
    scanf("%f%f",&x1,&y1);
    printf("Enter the coordinate of second point : ");
    scanf("%f%f",&x2,&y2);
    printf("Enter the coordinate of third point : ");
    scanf("%f%f",&x3,&y3);
    m1=(x1,y1,x2,y2);
    m2=(x2,y2,x3,y3);
    m3=(x3,y3,x1,y1);
    //printf("%f %f %f\n",m1,m2,m3);
    if ((m1==m2)||(m2==m3)||(m3==m1))
        printf("Triangle not possible\n");
    else
        printf("Triangle is possible\n");
    return 0;
}
