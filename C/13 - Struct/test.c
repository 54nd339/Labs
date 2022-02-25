
#include<stdio.h>
#include<string.h>
struct prod{
    char na[20];
    int md;
    float price;
    int ed;
};
int main(){
    printf("Input from Manufacture:\n");
    int n,y,i,d,choice; 
    char p[20];float pr;
    printf("Enter no. of products : ");
    scanf("%d",&n);
    struct prod b[n];
    for(i=0;i<n;i++){
        printf("\nProduct %d :\n",i+1);
        printf("Enter name of product : ");
        scanf("%s",b[i].na);
        printf("Enter manufacture year : ");
        scanf("%d",&b[i].md);
        printf("Enter price : ");
        scanf("%f",&b[i].price);
        printf("Enter expire year : ");
        scanf("%d",&b[i].ed);
    }
    printf("\nEnter current year : ");
    scanf("%d",&y);
    printf("\nItems :\n");
    printf("Product Name\tMfd. Date\tPrice\tExpire Date\n");
    for(i=0;i<n;i++)
        printf("%s\t\t%d\t\t%.2f\t\t%d\n",b[i].na,b[i].md,b[i].price,b[i].ed);
    printf("\nInput from User :\n");
    do{
        printf("Enter product : ");
        scanf("%s",p);
        for(i=0;i<n;i++)
        if(!strcmp(b[i].na,p)){
            if(y>=b[i].md && y<=b[i].ed){
                printf("Product Available\n");
                disc:
                printf("Enter any discount : ");
                scanf("%d",&d);
                if(d>100){
                    printf("Lootoge kya?? Enter discount below 100\n");
                    goto disc;
                }
                pr=((float)(100-d)/100)*b[i].price;
                printf("Price of %s after discount : %.2f\n",p,pr); 
            }
            else{
                printf("Product Not Available\n");
                if(y<b[i].md) printf("Reason : Coming Soon, Not manufactured Yet\n");
                else if(y>b[i].ed) printf("Reason : Expired, Not Safe for consumption\n");
            }
            break;
        }
        printf("\nPress '0' to quit, or any integer to continue : ");
        scanf("%d",&choice);
    }while(choice);
    return 0;
}
