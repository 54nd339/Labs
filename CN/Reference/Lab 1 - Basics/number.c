/* Write a C Program to enter a number and store the
number across the following structure and print the
content of each member of the structure. Then
aggregate each member of the structure to form the
original number and print the same.
struct pkt{
char ch1;
char ch2[2];
char ch3;
}; */


#include<stdio.h>
#include<string.h>

struct pkt{
char ch1;
char ch2[2];
char ch3;
};

void number_aggregate(struct pkt p)
{
	int number,r,c=1;
	printf("Enter a number of 4 digits \n");
	scanf("%d",&number);
	while(number!=0&& c<=4)
	{
	r=number%10;
	if(c==1)
	p.ch1=r;
	if(c==2)
	p.ch2[0]=r;
	if(c==3)
	p.ch2[1]=r;
	if(c==4)
	p.ch3=r;
	c++;
	number=number/10;
	}
	printf("The aggregated characters are: %d %d %d %d ",p.ch3,p.ch2[1],p.ch2[0],p.ch1);
	printf("\nThe original number: %d%d%d%d",p.ch3,p.ch2[1],p.ch2[0],p.ch1);
}
int main()
{
	struct pkt p;
	number_aggregate(p);
}
