#include <stdio.h>
int main(){
    printf("Enter Physics marks: ");
    int m1; scanf("%d",&m1);
    printf("Enter Chemistry marks: ");
    int m2; scanf("%d",&m2);
    printf("Enter Maths marks: ");
    int m3; scanf("%d",&m3);
    printf("Enter English marks: ");
    int m4; scanf("%d",&m4);
    printf("Enter Biology marks: ");
    int m5; scanf("%d",&m5);
    float per = ((float)(m1+m2+m3+m4+m5)/500)*100;
    if (per > 59)
        printf("First Grade\n");
    else if ((per > 49) && (per < 60))
        printf("Second Grade\n");
    else if ((per > 39) && (per < 50))
        printf("third Grade\n");
    else
        printf("fail\n");
    return 0;
}