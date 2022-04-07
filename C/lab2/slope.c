#include <stdio.h>
int main(){
    int x1, y1, x2, y2;
    printf("Enter the coordinate of the first point : ");
    scanf("%d%d",&x1,&y1);
    printf("Enter the coordinate of the second point : ");
    scanf("%d%d",&x2,&y2);
    float slope = (float) (y2-y1)/(x2-x1);
    printf("slope of the line joining %d,%d and %d,%d is %f",x1,y1,x2,y2,slope);
    return 0;
}