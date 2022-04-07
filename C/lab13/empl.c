#include <stdio.h>
struct employee{
    char name[20];
    char add[20];
    int age;
    float sal;
};
int main(){
    printf("Enter no. of Employees : ");
    int n; scanf("%d",&n);
    struct employee e[n];
    for(int i=0; i<n; i++){
        printf("\nEmployee %d :\n",i+1);
        printf("Enter name : ");
        scanf("%s",e[i].name);
        printf("Enter address : ");
        scanf("%s",e[i].add);
        printf("Enter age : ");
        scanf("%d",&e[i].age);
        printf("Enter salary : ");
        scanf("%f",&e[i].sal);
    }
    int s = 0;
    printf("\nEntered Data :\n");
    printf("Name\tAddress\tAge\tSalary\n");
    for(int i=0; i<n; i++){
        printf("%s\t%s\t%d\t%.2f\n",e[i].name,e[i].add,e[i].age,e[i].sal);
        s += e[i].sal;
    }
    printf("Average Salary : %.2f\n",(float)s/n);
}