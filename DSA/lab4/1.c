#include <stdio.h>
struct employee{
    char gender, name[20], desig[20], dept[20];
    float basic, hr, da, gross;
};
int main(){
    printf("Enter no. of employees : ");
    int n; scanf("%d",&n);
    struct employee e[n];
    for(int i=0; i<n; i++){
        printf("\nEnter details of employee %d :\n",i+1);
        printf("Name : ");
        scanf("%s",e[i].name); 
        printf("Gender (M/F) : ");getchar();
        scanf("%c",&e[i].gender); 
        printf("Designation : ");
        scanf("%s",e[i].desig); 
        printf("Department : ");
        scanf("%s",e[i].dept); 
        printf("Basic Pay : ");
        scanf("%f",&e[i].basic);
        e[i].hr = 0.25 * e[i].basic;
        e[i].da = 0.75 * e[i].basic;
        e[i].gross = e[i].basic + e[i].hr + e[i].da;
    }
    printf("\nEmployee Name.\tGross Pay\n");
    for(int i=0; i<n; i++)
        printf("%s\t\t%.2f\n",e[i].name,e[i].gross);
    return 0;
}