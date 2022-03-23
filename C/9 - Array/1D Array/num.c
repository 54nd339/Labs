#include <stdio.h>
int main(){
    int n=20, ce=0, co=0, cn=0;
    /*printf("Enter number of elements:");
    scanf("%d",&n);*/
    int num[n];
    for(int i=0; i<n; i++){
        printf("Enter element %d : ",(i+1));
        scanf("%d",&num[i]);
    }
    printf("Entered Elements : ");
    for(int i=0; i<n; i++){
        int t = num[i];
        printf("%d, ",t);
        t>=0 ? (t%2 ? co++ : ce++) : cn++;
    }
    printf("\n");
    printf("No. of negative element : %d\n",cn);
    printf("No. of positive element : %d\n",20-cn);
    printf("No. of odd element : %d\n",co);
    printf("No. of even element : %d\n",ce);
    return 0;
}