#include <stdio.h>
#include <stdlib.h>
void insertionSort(int *arr, int n) {
	for (int i = 1; i < n; i++) {
		int key = arr[i], j = i-1;
        while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
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
    printf("Enter Elements : ");
    for (int i = 0; i < n; i++)
        scanf("%d", &ar[i]);
	
    printf("Original array : ");
	print(ar, n);

    insertionSort(ar, n);
	printf("Sorted array : ");
	print(ar, n);
	return 0;
}