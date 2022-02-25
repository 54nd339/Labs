#include<stdio.h>
#include<string.h>
struct prod{
    char na[20];
    int md;
    float price;
    int ed;
};
int main(){
    int n,y,i,d,flag=1; 
    printf("Input from Manufacture:\n");
    char p[20];float pr;
    printf("Enter no. of products : ");
    scanf("%d",&n);
    struct prod b[n];
    for(i=0;i<n;i++){                                       //Product input
        printf("\nProduct %d :\n",i+1);
        printf("Enter name of product, manufacture year, price, expire year : ");
        scanf("%s%d%f%d",b[i].na,&b[i].md,&b[i].price,&b[i].ed);
    }
    printf("\nEnter current year : ");
    scanf("%d",&y);
    printf("\nItems :\n");                                     //Display product
    printf("Product Name\tMfd. Date\tPrice\tExpire Date\n");
    for(i=0;i<n;i++)
        printf("%s\t\t%d\t\t%.2f\t\t%d\n",b[i].na,b[i].md,b[i].price,b[i].ed);
    
    printf("\nInput from User :\n");
    printf("Enter product : ");                                //Product wanted
    scanf("%s",p);
    for(i=0;i<n;i++){
        if(!strcmp(b[i].na,p)){  
            if(y>=b[i].md && y<=b[i].ed){      //check avaibility by year
                printf("Product Available\n");
                printf("Available till %d\n",b[i].ed);
                printf("Enter any discount : ");
                scanf("%d",&d);
                pr=((float)(100-d)/100)*b[i].price;
                printf("Price of %s after discount : %.2f\n",p,pr);
                flag=0; 
            }
            else{
                printf("Product Not Available\n");
                if(y<b[i].md) 
                ("Reason : Coming Soon, Not manufactured Yet\n");
                else if(y>b[i].ed) 
                printf("Reason : Expired, Not Safe for consumption\n");
                flag=0;
            }
            break;
        }
    }
    if(flag)                                 //check avaibility by name  
    printf("Product Not Available\n");
    return 0;
}
