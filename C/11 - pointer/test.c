#include<stdio.h>
int main(){
    int i,j,n,count=0;
    printf("Enter no. of names: ");
    scanf("%d",&n);
    char ch, name[n][100],(*p)[100];
    p=name;
    
    for(i=0;i<n;i++){   
        printf("Enter name %d: ",(i+1));
        scanf("%s",(p+i)); //Accept names
    }
    getchar();
    printf("Enter the charecter to be counted: ");
    scanf("%c",&ch);     //Accept character
    
    for(i=0;i<n;i++)
        for(j=0;p[i][j];j++)
            if(p[i][j]==ch){ //Display position
                printf("Found at pos %d in %s \n",(j+1),(p+i));
                count++;
            }
    
    printf("no. of %c is %d \n",ch,count); //Display count
    return 0;
}
