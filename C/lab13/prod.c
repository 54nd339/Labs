#include<stdio.h>
#include<string.h>
struct prod{
    char na[20];
    int md, ed;
    float price;
};

int main(){
    printf("Input from Manufacture:\n");
    char p[20];
    printf("Enter no. of products : ");
    int n; scanf("%d",&n);
    struct prod b[n];
    for(int i=0; i<n; i++){
        printf("\nProduct %d :\n",i+1);
        printf("Enter name of product, manufacture year, price, expire year : ");
        scanf("%s%d%f%d",b[i].na,&b[i].md,&b[i].price,&b[i].ed);
    }
    printf("\nEnter current year : ");
    int y; scanf("%d",&y);
    printf("\nItems :\n");
    printf("Product Name\tMfd. Date\tPrice\tExpire Date\n");
    for(int i=0; i<n; i++)
        printf("%s\t\t%d\t\t%.2f\t\t%d\n",b[i].na,b[i].md,b[i].price,b[i].ed);
    
    printf("\nInput from User :\n");
    printf("Enter product : ");
    scanf("%s",p); int flag = 1;
    for(int i=0; i<n; i++){
        if(!strcmp(b[i].na,p)){  
            if(y>=b[i].md && y<=b[i].ed){
                printf("Product Available\n");
                printf("Available till %d\n",b[i].ed);
                printf("Enter any discount : ");
                float d; scanf("%d",&d);
                float pr = ((float)(100-d)/100)*b[i].price;
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
    if(flag)
        printf("Product Not Available\n");
    return 0;
}