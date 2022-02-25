#include <stdio.h>
#include <stdlib.h>
int main(){
    int n,*ar,i,k,max,c=0;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    ar=(int *)malloc(n*sizeof(int));
    printf("Enter array elements : ");
    for(i=0;i<n;i++)
        scanf("%d",ar+i);
    
    max=ar[0];
    for(i=1;i<n;i++){
        if(ar[i]>max){
            max=ar[i];
            c=0;
        }
        if(ar[i]==max) c++;
    }

    printf("Max occurence of %d : %d",max, c);
    free(ar); return 0;
}