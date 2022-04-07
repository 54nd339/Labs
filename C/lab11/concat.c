#include <stdio.h>
int len(char str[]){
   int i = -1;
   while(str[++i]);
   return i;
}
int main(){
   char str1[100], str2[100];
   printf("Enter 1st string: ");
   scanf("%s",str1);
   int l1 = len(str1), i = 0;
   printf("Enter 2nd string: ");
   scanf("%s",str2);
   char *p1 = str1, *p2 = str2;
   /*for(int i=0;p2[i];i++)
   p1[l1+i]=p2[i];*/
   while(str2[i++])
      str1[l1+i] = str2[i];
   printf("Concated String: %s\n",str1);
   return 0;
}