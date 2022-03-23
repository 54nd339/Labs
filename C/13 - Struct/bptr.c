#include <stdio.h>
struct book{
    char name[20];
    float price;
    int pages;
};

int main(){
    printf("Enter no. of books : ");
    int n; scanf("%d",&n);
    struct book b[n], *ptr = b;
    for(int i=0; i<n; i++){
        printf("\nBook %d :\n",i+1);
        printf("Enter name of book : ");
        scanf("%s",(ptr+i)->name);
        printf("Enter price : ");
        scanf("%f",&(ptr+i)->price);
        printf("Enter pages : ");
        scanf("%d",&(ptr+i)->pages);
    }
    printf("\nEntered Data :\n");
    printf("Book Name\tPrice\tPages\n");
    for(int i=0; i<n; i++)
        printf("%s\t\t%.2f\t%d\n",(ptr+i)->name,(ptr+i)->price,(ptr+i)->pages);
}