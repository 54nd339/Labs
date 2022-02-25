#include <stdio.h>
#include <stdlib.h>
int n,i;
struct attendance{
    int roll;
    char pa;
};
struct attendance *input(){
    struct attendance *in=malloc(n*sizeof(struct attendance));
    for(i=0;i<n;i++){
        printf("\nEnter details of student %d :\n",i+1);
        printf("Roll No. : ");
        scanf("%d",&((in+i)->roll));
        getchar();
        printf("Present / Absent : ");
        scanf("%c",&((in+i)->pa));
    }
    return in;
}
void display(){
    struct attendance *report=malloc(n*sizeof(struct attendance));
    report=input();
    printf("\nAttendance Display : \n Roll No.\tP/A\n");
    for(i=0;i<n;i++)
    printf("%d\t%c\n",(report+i)->roll,(report+i)->pa);
}
int main(){
    printf("Enter no. of Students : ");
    scanf("%d",&n);
    display();   
    return 0;
}