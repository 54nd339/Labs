#include <stdio.h>
int main(){
    printf("Enter no. of items : ");
    int n; scanf("%d",&n);
    int ar[n], c = 0;
    for(int i=0; i<n; i++){
        printf("Enter element %d : ",(i+1));
        scanf("%d",&ar[i]);
    }
    int l = ar[0];
    for(int i=1; i<n; i++)
        if (l < ar[i]){
            l = ar[i];
            c++;
        }
    printf("Largest No. : %d\n",l);
    printf("No. of leaders : %d\n",c);
    return 0;
}