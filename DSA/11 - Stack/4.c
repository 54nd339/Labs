#include <stdio.h>
#include <stdlib.h>
typedef struct intervals {
    int start, end;
}interval;

void findFreeinterval(interval *arr, int n){
    if (n <= 0) return;
    interval *out = malloc(n*sizeof(interval));
    for(int i=0; i<n-1; i++){
        if(arr[i].start > arr[i+1].start){
            interval temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
    /*for (int i = 0; i < n; i++) 
        printf("[%d,%d] ", arr[i].start, arr[i].end);*/
    int j = 0;
    for (int i = 1; i < n; i++) {
        int prevEnd = arr[i-1].end;
        int currStart = arr[i].start;
        if (prevEnd < currStart){
            //printf("%d %d %d\n", j, prevEnd, currStart);
            out[j].start = prevEnd;
            out[j].end = currStart;
            j++;
        }
    }
    for (int i = 0; i < j; i++) 
        printf("[%d,%d] ", out[i].start, out[i].end);
}
 
int main(){
    printf("No. of intervals to be created : ");
    int n; scanf("%d",&n);
    interval *arr = malloc(n*sizeof(interval));
    for(int i=0; i<n; i++){
        printf("Enter interval %d (Enter Start, End): ",i+1);
        scanf("%d%d", &arr[i].start, &arr[i].end);
    }
    findFreeinterval(arr, n);
    return 0;
}