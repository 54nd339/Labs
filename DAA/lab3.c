#include<stdio.h>
#include<stdlib.h>
#include<time.h>
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

int *reverse(int *arr, int n) {
    int *rev = malloc(n * sizeof(int));
    for (int i = 0; i < n/2; i++) {
        int temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
    }
    return rev;
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
        ar[i] = rand() % (n+1);
    // printf("Original array : ");
	// print(ar, n);

    clock_t start = clock();
    insertionSort(ar, n);
    clock_t end = clock();
    printf("Time taken : %f\n", (double)(end - start) / CLOCKS_PER_SEC);

	// printf("Sorted array : ");
	// print(ar, n);
	
    printf("Best Case : ");
    start = clock();
    insertionSort(ar, n);
    end = clock();
    printf("Time taken : %f\n", (double)(end - start) / CLOCKS_PER_SEC);

    printf("Worst Case : ");
    start = clock();
    insertionSort(reverse(ar, n), n);
    end = clock();
    printf("Time taken : %f\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}