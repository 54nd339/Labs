/*Write a program to display the information stored in 4 byte separately of integer
variable, also the endian which your system follows.*/


#include <stdio.h>
int main()
{
   unsigned int i = 299;
   char *c = (char*)&i;
      if (*c)
       printf("Little endian\n");
   else
       printf("Big endian\n");
   for (int k=0;k<4;k++){
    printf("Byte %d = %d\n",k+1,*c);
    c++;
   }
   getchar();
   return 0;
}
