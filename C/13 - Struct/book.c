#include <stdio.h>
struct book{
    //char na[20];
    char nb[20];
    float price;
    int pages;
};
int main(){
    printf("Enter no. of books : ");
    int n; scanf("%d",&n);
    struct book b[n];
    for(int i=0; i<n; i++){
        printf("\nBook %d :\n",(i+1));
        printf("Enter name of book : "); getchar();
        scanf("%[^\n]s",b[i].nb);
        //printf("Enter name of author :");
        //scanf("%s",b[i].na);
        printf("Enter price : ");
        scanf("%f",&b[i].price);
        printf("Enter pages : ");
        scanf("%d",&b[i].pages);
    }
    printf("\nEntered Data :\n");
    //printf("Book Name\tAuthor Name\tPrice\tPages\n");
    printf("Book Name\tPrice\tPages\n");
    for(int i=0; i<n; i++)
        printf("%s\t\t%.2f\t%d\n",b[i].nb,b[i].price,b[i].pages);
        //printf("%s\t\t%s\t\t%.2f\t%d\n",b[i].nb,b[i].na,b[i].price,b[i].pages);
}