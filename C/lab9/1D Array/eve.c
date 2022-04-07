#include <stdio.h>
int main(){
    printf("Enter no. of elements : ");
    int n; scanf("%d",&n);
    int num[n], c = 0;
    for(int i=0; i<n; i++){
        printf("Enter element %d : ",(i+1));
        scanf("%d",&num[i]);
    }
    printf("Even nos. in array :\n");
    for(int i=0; i<n; i++)
        if(num[i]%2 == 0){
            printf("%d\n",num[i]);c++;
        }
    printf("No. of even nos.: %d\n",c);
    return 0;
}