#include <stdio.h>
#include <stdlib.h>
#define DA 0.05
#define HRA 0.05
typedef struct employee {
    int empId;
    float basic, da, hra, gross;
}emp;

int main() {
    emp *employee = malloc(3 * sizeof(emp));
    for(int i=0; i<3; i++) {
        printf("Enter empId : ");
        scanf("%d",&(employee+i)->empId);
        printf("Enter basic : ");
        scanf("%f",&(employee+i)->basic);
        (employee+i)->da = (employee+i)->basic * DA;
        (employee+i)->hra = (employee+i)->basic * HRA;
        (employee+i)->gross = (employee+i)->basic * (1+DA+HRA);
    }
    printf("\nEntered Details :");
    for(int i=0; i<3; i++) {
        printf("\nempId : %d\n",(employee+i)->empId);
        printf("Basic : %.2f\n",(employee+i)->basic);
        printf("DA : %.2f\n",(employee+i)->da);
        printf("HRA : %.2f\n",(employee+i)->hra);
        printf("Gross : %.2f\n",(employee+i)->gross);
    }
    return 0;
}