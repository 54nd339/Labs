#include<stdio.h>
int main(){
    printf("Enter no. of names : ");
    int n; scanf("%d",&n);
    char ch, name[n][100],(*p)[100];
    p = name; int count = 0;
    
    for(int i=0; i<n; i++){   
        printf("Enter name %d : ",(i+1));
        scanf("%s",(p+i));
    }
    getchar();
    printf("Enter the charecter to be counted : ");
    scanf("%c",&ch);
    
    for(int i=0; i<n; i++)
        for(int j=0; p[i][j]; j++)
            if(p[i][j] == ch){
                printf("Found at pos %d in %s \n",(j+1),(p+i));
                count++;
            }
    
    printf("no. of %c is %d \n",ch,count); //Display count
    return 0;
}