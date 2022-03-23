#include <stdio.h>
int main(){
    int m1, m2, m3, m4, m5;
    printf("Enter Physics marks: ");
    scanf("%d",&m1);
    printf("Enter Chemistry marks: ");
    scanf("%d",&m2);
    printf("Enter Maths marks: ");
    scanf("%d",&m3);
    printf("Enter English marks: ");
    scanf("%d",&m4);
    printf("Enter Biology marks: ");
    scanf("%d",&m5);
    float per = ((float)(m1+m2+m3+m4+m5)/500)*100;
    if (per>59)
        printf("First Grade\n");
    else if ((per>49) && (per<60))
        printf("Second Grade\n");
    else if ((per>39) && (per<50))
        printf("third Grade\n");
    else
        printf("fail\n");
    return 0;
}