#include <stdio.h>
int main(){
    int x1,y1,x2,y2,x3,y3,x4,y4,t;
    float m1,m2;
    printf("Enter the coordinate of the first point of L1 : ");
    scanf("%d%d",&x1,&y1);
    printf("Enter the coordinate of the second point of L1 : ");
    scanf("%d%d",&x2,&y2);
    printf("Enter the coordinate of the first point of L2 : ");
    scanf("%d%d",&x3,&y3);
    printf("Enter the coordinate of the second point of L2 : ");
    scanf("%d%d",&x4,&y4);
    m1=(float) (y2-y1)/(x2-x1);
    m2=(float) (y4-y3)/(x4-x3);
    t=(int) m1*m2*(-1);
    //printf("%d %d , %d %d , %d %d , %d %d , %d , %f %f \n",x1,y1,x2,y2,x3,y3,x4,y4,t,m1,m2);
    printf("Are the lines joining the coordinates perpendicular?\n");
    printf("Display - 1 if yes else any other integer: %d \n",t);
    return 0;
}
