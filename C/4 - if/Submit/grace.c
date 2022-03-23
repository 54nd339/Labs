#include <stdio.h>
int main(){
    printf("Enter your age : ");
    int age; scanf("%d",&age);
    int marks = 40;
    if(age<50)
        marks+=20;
    printf("age: %d marks: %d\n",age,marks);
}