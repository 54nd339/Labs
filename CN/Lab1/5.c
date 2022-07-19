#include <stdio.h>
#include <stdlib.h>
#define DA 0.05
#define HRA 0.05
typedef struct employee {
    int empId;
    float basic, da, hra, gross;
}emp;
typedef struct emp_info {
    int age;
    emp empl;
}info;

int main() {
    info employee[3];
    for(int i=0; i<3; i++) {
        printf("Enter empId : ");
        scanf("%d",&employee[i].empl.empId);
        printf("Enter age : ");
        scanf("%d",&employee[i].age);
        printf("Enter basic : ");
        scanf("%f",&employee[i].empl.basic);
        employee[i].empl.da = employee[i].empl.basic * DA;
        employee[i].empl.hra = employee[i].empl.basic * HRA;
        employee[i].empl.gross = employee[i].empl.basic * (1+DA+HRA);
    }
    printf("\nEntered Details :");
    for(int i=0; i<3; i++) {
        printf("\nEmpId : %d\n",employee[i].empl.empId);
        printf("\nAge : %d\n",employee[i].age);
        printf("Basic : %.2f\n",employee[i].empl.basic);
        printf("DA : %.2f\n",employee[i].empl.da);
        printf("HRA : %.2f\n",employee[i].empl.hra);
        printf("Gross : %.2f\n",employee[i].empl.gross);
    }
    return 0;
}