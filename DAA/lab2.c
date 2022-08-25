#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int *xp, int *yp) {
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionSort(int arr[], int n) {
	int min_ind;
    for (int i = 0; i < n-1; i++) {
        min_ind = i;
		for (int j = i+1; j < n; j++){
            if (arr[j] < arr[min_ind])
                min_ind = j;
        }
        swap(&arr[min_ind], &arr[i]);
	}
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
        }
        if (flag) break;
    }
}

int *create(int n) {
    int *arr = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
        arr[i] = rand() % (n+1);
    return arr;
}
void print(int *arr, int size) {
	for (int i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main() {
    printf("Enter no. of elements : ");
    int n; scanf("%d", &n);
    int *ar = create(n);
    int *br = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        br[i] = ar[i];
	
    // printf("Original array : ");
	// print(ar, n);

    clock_t start = clock();
    selectionSort(ar, n);
    clock_t end = clock();
    printf("Time taken by Selection Sort : %f\n", (double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    bubbleSort(br, n);
    end = clock();
    printf("Time taken by Bubble Sort : %f\n", (double)(end - start) / CLOCKS_PER_SEC);
	
    // printf("Sorted array : ");
	// print(ar, n);
	return 0;
}