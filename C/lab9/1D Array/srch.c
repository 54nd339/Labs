#include <stdio.h>
int main(){
    printf("Enter an item : ");
    int item; scanf("%d",&item);
    printf("Enter no. of items : ");
    int n; scanf("%d",&n);
    int ite[n], pos = -1;
    for(int i=0; i<n; i++){
        printf("Enter item %d :",(i+1));
        scanf("%d",&ite[i]);
    }
    for(int i=0; i<n; i++)
        if (item == ite[i]){
            pos = i+1;
            break;
        }
    if(pos == -1)
        printf("Item not found\n");
    else
        printf("Found at pos.: %d\n", pos);
}