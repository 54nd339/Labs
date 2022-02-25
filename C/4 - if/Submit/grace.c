#include <stdio.h>
int main(){
    int marks, age;
    printf("Enter your age : ");
    scanf("%d",&age);
    marks=40;
    if(age<50)
        marks+=20;
    printf("age: %d marks: %d\n",age,marks);
}
