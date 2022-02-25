#include <stdio.h>
#include <stdlib.h>
int main(){
    int *ar, n, i, s, l;
    printf("Enter the no. of elements in the array : ");
    scanf("%d",&n);
    ar=(int *)malloc(n*sizeof(int));
    printf ("Enter array elements :\n");
    for(i=0;i<n;i++){
        scanf("%d",ar+i);
        if(i==0){
            l=*(ar);
            s=*(ar);
        }
        else{
            if(l<*(ar+i)) l=*(ar+i);
            if(s>*(ar+i)) s=*(ar+i);
        }
    }
    printf("Smallest : %d\n",s);
    printf("Largest : %d",l);
    free(ar);
    return 0;
}