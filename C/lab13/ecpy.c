#include <stdio.h>
#include <string.h>
struct employee{
    char name[20];
    float salary;
    int age;
};
int main(){
    struct employee e[3];
    printf("Enter name of employee : ");
    scanf("%s",e[0].name);
    printf("Enter salary : ");
    scanf("%f",&e[0].salary);
    printf("Enter age: ");
    scanf("%d",&e[0].age);
    for(int i=1; i<3; i++){
        strcpy(e[i].name,e[0].name);
        e[i].salary = e[0].salary;
        e[i].age = e[0].age;
    }
    printf("Entered Data :\n");
    printf("Employee No.\tEmployee Name\tSalary\tAge\n");
    for(int i=0; i<3; i++)
        printf("E%d\t\t%s\t\t%.2f\t%d\n",i+1,e[i].name,e[i].salary,e[i].age);
    return 0;
}