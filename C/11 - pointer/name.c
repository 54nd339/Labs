#include<stdio.h>
int main(){
    int i,j,count=0;
    char ch, name[6][100] ,(*p)[100];
    p=name;
    
    for(i=0;i<6;i++){   
        printf("Enter name %d: ",(i+1));
        scanf("%s",(p+i));                            //Accept names
    }
    
    printf("Entered names:\n");                     //Display names
    for(i=0;i<6;i++)
        printf("name %d: %s\n",(i+1),(p+i));
        
    getchar();  
    printf("Enter the charecter to be counted: ");
    scanf("%c",&ch);                                //Accept charecter
    
    for(i=0;i<6;i++)
        for(j=0;p[i][j];j++)
            if(p[i][j]==ch){
                printf("Found at pos %d in %s \n",(j+1),(p+i)); //display position
                count++;
            }
    
    printf("no. of %c is %d \n",ch,count);          //display count
    return 0;
}
