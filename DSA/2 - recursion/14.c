#include <stdio.h>
#include <stdlib.h>
struct attendance{
    int roll;
    char pa;
};
struct attendance *input(int n){
    struct attendance *in = malloc(n*sizeof(struct attendance));
    for(int i=0; i<n; i++){
        printf("\nEnter details of student %d :\n",i+1);
        printf("Roll No. : ");
        scanf("%d",&((in+i)->roll));
        getchar();
        printf("Present / Absent : ");
        scanf("%c",&((in+i)->pa));
    }
    return in;
}
void display(int n){
    struct attendance *report = malloc(n*sizeof(struct attendance));
    report = input(n);
    printf("\nAttendance Display : \n Roll No.\tP/A\n");
    for(int i=0; i<n; i++)
    printf("%d\t%c\n",(report+i)->roll,(report+i)->pa);
}
int main(){
    printf("Enter no. of Students : ");
    int n; scanf("%d",&n);
    display(n);   
    return 0;
}