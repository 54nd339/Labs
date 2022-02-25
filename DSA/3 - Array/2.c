#include <stdio.h>
#include <stdlib.h>
int main(){
    int n,*ar,i;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    ar=(int *)malloc(n*sizeof(int));
    printf("Enter array elements : ");
    for(i=0;i<n;i++)
        scanf("%d",ar+i);

    int l=ar[0],s=ar[0],sl=ar[1],ss=ar[1];
    for(i=1;i<n;i++){
        if(ar[i]>l){
            sl=l;
            l=ar[i];
        }
        else if(ar[i]>sl) sl=ar[i];
        if(ar[i]<s){
            ss=s;
            s=ar[i];
        }
        else if(ar[i]<ss) ss=ar[i];
    }

    printf("Second Smallest : %d \n",ss);
    printf("Second Largest : %d \n",sl);
    free(ar); return 0;
}