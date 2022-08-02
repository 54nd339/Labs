#include <stdio.h>
#include <stdlib.h>
int count = 0;
void swap(int *xp, int *yp) {
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubbleSort(int *arr, int n) {
    int flag;
    for (int i = 0; i < n-1; i++) {
        flag = 1;
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                flag = 0;
            }
            count++;
        }
        if (flag) break;
    }
}

void print(int *arr, int size) {
	for (int i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
int main() {
    printf("Enter no. of elements : ");
    int n; scanf("%d", &n);
    int *ar = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        ar[i] = (rand() % (n + 1));
	
    printf("Original array : ");
	print(ar, n);

    bubbleSort(ar, n);
	printf("Sorted array : ");
	print(ar, n);
    printf("No. of iteration : %d", count);
	return 0;
}