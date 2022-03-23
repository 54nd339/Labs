#include<stdio.h>
int main(){
    int m1[4][4], m2[4][4], r[4][4];
    printf("Enter Matrix 1 : \n");
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++){
            printf("Enter Element %d,%d: ",i+1,j+1);
            scanf("%d",&m1[i][j]);
        }
    printf("Enter Matrix 2 : \n");
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++){
            printf("Enter Element %d,%d: ",i+1,j+1);
            scanf("%d",&m2[i][j]);
            r[i][j] = m1[i][j] + m2[i][j];
        }
    printf("Entered Matrix 1 : \n");
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++)
            printf("%d\t",m1[i][j]);
        printf("\n");
    }
    printf("Entered Matrix 2 : \n");
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++)
            printf("%d\t",m2[i][j]);
        printf("\n");
    }
    printf("Resultant Matrix : \n");
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++)
            printf("%d\t",r[i][j]);
        printf("\n");
    }
    return 0;
}