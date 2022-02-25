#include <stdio.h>
/*
void dis(){
printf("= \n");
}

void dis2(){
for(int i=1;i<=10;i++)
printf("=");
printf("\n");
}

void dis3(int n){
for(int i=1;i<=n;i++)
printf("=");
printf("\n");
}
*/
void dis4(char ch,int n){
for(int i=1;i<=n;i++)
printf("%c",ch);
printf("\n");
}

int main(){
int n;char ch;
/*
dis();

for(int i=1;i<=3;i++)
dis2();

printf("Enter a no.");
scanf("%d",&n);
dis3(n);
*/
printf("Enter a charecter:");
scanf("%c",&ch);
printf("Enter a no.");
scanf("%d",&n);
dis4(ch,n);
return 0;
}
