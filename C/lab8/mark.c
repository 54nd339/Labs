#include <stdio.h>
int main(){
    int m1, m2, m3, m4, m5;
    printf("Enter 5 marks : \n");
    scanf("%d%d%d%d%d",&m1,&m2,&m3,&m4,&m5);
    float per = ((float)(m1+m2+m3+m4+m5)/500)*100;
    int c = (int)per/10;
    switch(c){
        case (10):
            printf("Either you're god, or you're fantasizing");
            break;

        case (9):
            printf("Percentage: %f, Grade:O\n",per);
            break;

        case (8):
            printf("Percentage: %f, Grade:E\n",per);
            break;

        case (7):
            printf("Percentage: %f, Grade:A\n",per);
            break;

        case (6):
            printf("Percentage: %f, Grade:B\n",per);
            break;

        case (5):
            printf("Percentage: %f, Grade:C\n",per);
            break;

        case(4):
            printf("Percentage: %f, Grade:D\n",per);
            break;

        case (3):
            printf("Percentage: %f, Grade:F\n",per);
            break;

        case (2):
            printf("Percentage: %f, Grade:F\n",per);
            break;

        case (1):
            printf("Percentage: %f, Grade:F\n",per);
            break;

        case (0):
            printf("Percentage: %f, Grade:F\n",per);
            break;

        default:
            printf("Wrong inputs");
            break;
    }
}