#include <stdio.h>
int main(){
    int m1,m2,m3,m4,m5;
    printf("Enter 5 marks\n");
    scanf("%d%d%d%d%d",&m1,&m2,&m3,&m4,&m5);
    float per = ((float)(m1+m2+m3+m4+m5)/500)*100;
    if(per>90){
        printf("Percentage: %f, Grade:O\n",per);
        return 0;
    }
    if((per>80) && (per<90)){
        printf("Percentage: %f, Grade:E\n",per);
        return 0;
    }
    if((per>70) && (per<80)){
        printf("Percentage: %f, Grade:A\n",per);
        return 0;
    }
    if((per>60) && (per<70)){
        printf("Percentage: %f, Grade:B\n",per);
        return 0;
    }
    if((per>50) && (per<60)){
        printf("Percentage: %f, Grade:C\n",per);
        return 0;
    }
    if((per>40) && (per<50)){
        printf("Percentage: %f, Grade:D\n",per);
        return 0;
    }
    if(per<40){
        printf("Percentage: %f, Grade:F\n",per);
        return 0;
    }
}