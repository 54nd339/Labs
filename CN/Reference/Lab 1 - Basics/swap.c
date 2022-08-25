/* Write a C program to swap the content of 2 variables using pointer. */

#include<stdio.h>
int main()
{
int x,y;
printf("Enter value of x and y : \n");
scanf("%d%d",&x,&y);
swap (&x,&y);
printf("Values of x and y after swapping: \n");
printf("%d %d\n",x,y);
return 0;
}
void swap (int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
