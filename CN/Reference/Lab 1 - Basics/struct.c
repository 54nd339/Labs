/*  Write a C program to assign values to each members of the following structure.
Pass the populated structure to a function Using call-by address and print the value of each member of the structure with in that function. */
#include<stdio.h>
struct info{
int roll_no;
char name[50];
float CGPA;
};
struct info input()
{
struct info object;
printf("Enter roll number: ");
scanf(" %d",&object.roll_no);
printf("Enter name: ");
scanf(" %[^\n]%*c",object.name);
printf("Enter CGPA: ");
scanf(" %f",&object.CGPA);

return object;
}
void output(struct info *x)
{
printf("Roll number: %d\n",x->roll_no);
printf("Name: %s\n",x->name);
printf("CGPA: %.3f\n",x->CGPA);
}

int main()
{
int n;
printf("Enter number of students: ");
scanf("%d",&n);
struct info object[n];

for(int i=0;i<n;i++)
{
printf("\nEnter details of student no. %d,\n ",i+1);
object[i]=input();
}
for(int i=0;i<n;i++)
{
printf("\n\nDetails of student no. %d: ",i+1);
output(&object[i]);
}
}
