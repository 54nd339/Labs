#include <stdio.h>
#include <stdlib.h>
int main(){
    printf("Enter the size of array : ");
    int n, l, s; scanf("%d",&n);
    int *ar = (int *)malloc(n*sizeof(int));
    printf ("Enter array elements : ");
    for(int i=0; i<n; i++){
        scanf("%d",ar+i);
        if(i == 0){
            l = *(ar);
            s = *(ar);
        }
        else{
            if(l < *(ar+i)) l = *(ar+i);
            if(s > *(ar+i)) s = *(ar+i);
        }
    }
    printf("Smallest : %d\n",s);
    printf("Largest : %d",l);
    free(ar);
    return 0;
}