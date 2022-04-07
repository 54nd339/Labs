#include <stdio.h>
int main(){
    printf("Enter no. of elements in the array : ");
    int n; scanf("%d",&n);
    int ar[n], b[n+1];

    for(int i=0; i<n; i++){
        printf("Enter element %d : ",i+1);
        scanf("%d",&ar[i]);
    }
    printf("Enter an element to insert : ");
    int m; scanf("%d",&m);
    b[0] = m;

    printf("\nAt starting : \n");
    for(int i=1; i<=n; i++)
        b[i] = ar[i-1];
    for(int i=0; i<=n; i++)
        printf("element at %d : %d\n",i,b[i]);

    printf("\nAt Ending : \n");
    for(int i=0; i<n; i++)
        b[i] = ar[i];
    b[n] = m;
    for(int i=0; i<=n; i++)
        printf("element at %d : %d\n",i,b[i]);

    printf("\nfrom a point : \n");
    printf("Enter a point : ");
    int p; scanf("%d",&p);

    for(int i=0; i<p; i++)
        b[i] = ar[i];
    b[p] = m;
    for(int i=p; i<n; i++)
        b[i+1] = ar[i];
    for(int i=0;i<=n;i++)
        printf("element at %d : %d\n",i,b[i]);

    return 0;
}