#include <stdio.h>
int main(){
    int m1,m2,m3,m4,m5;
    float per,avg;
    printf("Enter 5 marks : \n");
    scanf("%d%d%d%d%d",&m1,&m2,&m3,&m4,&m5);
    avg=(float)(m1+m2+m3+m4+m5)/5;
    per=((float)(m1+m2+m3+m4+m5)/500)*100;
    printf("Average scored by the student is  %f\n",avg);
    printf("Percentage scored by the student is %f\n",per);
    return 0;
}
