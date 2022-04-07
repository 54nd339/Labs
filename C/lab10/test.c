#include <stdio.h>
int main(){
    char src[100], dst[100]; int i=0;
    printf("Enter Source Code: ");
    scanf("%[^\n]s",src);
    while(dst[i] = src[i++])
        printf("src=%s src[%d]=%c dst=%s dst[%d]=%c \n",src,i-1,src[i-1],dst+1,i-1,dst[i-1]);
    printf("src=%s src[%d]=%c dst=%s dst[%d]=%c \n",src,i-1,src[i-1],dst+1,i-1,dst[i-1]);
    printf("Destination Code: %s\n",dst+1);
    return 0;
}