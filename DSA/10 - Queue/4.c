#include <stdio.h>
#include <stdlib.h>
int find(int **M, int n){
    int i = 0, j = n - 1;
    while (i < j) {
        if (M[j][i] == 1) j--;
        else i++;
    }
    int ind = i;
    for (i = 0; i < n; i++) {
        if (i != ind) {
            if (M[i][ind] == 0 || M[ind][i] == 1)
                return -1;
        }
    }
    return ind;
}
int main(){
    printf("Enter no. of people : ");
    int n; scanf("%d", &n);
    int **ar = (int **)malloc(n*sizeof(int *));
    for (int i=0; i<n; i++)
        *(ar+i) = (int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(i==j) ar[i][j] = 0;
            else{
                printf("Does %d knows %d : ",i,j);
                scanf("%d",&ar[i][j]);
            }
        }
    int ind = find(ar, n);
    if(ind == -1) printf("No such person\n");
    else printf("Person Index : %d\n",ind);
    return 0;
}