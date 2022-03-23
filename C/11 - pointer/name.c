#include<stdio.h>
int main(){
    char ch, name[6][100] ,(*p)[100];
    p = name; int count = 0;
    for(int i=0; i<6; i++){   
        printf("Enter name %d : ",(i+1));
        scanf("%s",(p+i));
    }
    printf("Entered names :\n");
    for(int i=0; i<6; i++)
        printf("name %d : %s\n",(i+1),(p+i));
    getchar();  
    printf("Enter the charecter to be counted : ");
    scanf("%c",&ch);
    for(int i=0; i<6; i++)
        for(int j=0; p[i][j]; j++)
            if(p[i][j] == ch){
                printf("Found at pos %d in %s \n",(j+1),(p+i));
                count++;
            }
    printf("no. of %c is %d \n",ch,count);
    return 0;
}