/* Write a C program to check whether the Host machine is in Little Endian or Big Endian.
Enter a number, print the content of each byte location and Convert the Endianness of the same
i.e. Little to Big Endian and vice-versa. */

#include <stdio.h>
#include<string.h>
unsigned int convert_to_big (unsigned int x){
    return (((x>>24) & 0x000000ff) | ((x>>8) & 0x0000ff0) | ((x<<8) & 0x00ff0000) | ((x<<24) & 0xff000000));
}
int main(void) {
    unsigned int value = 1929299;
    char *c = (char *) &value;
    if (*c){
        printf("Little endian\n");
        printf ("\nBig Endian Converted Value = 0x%x\n", convert_to_big(value));
    }
    else
        printf("Big endian\n");
 
    for(int i = 0; i < 4; i++)
        printf("Address of 0x%x = %d \n", c[i], &c[i]);

    return 0;
}