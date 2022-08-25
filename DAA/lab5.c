#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int *xp, int *yp) {
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void merge(int *arr, int l, int m, int r) {
	int n1 = m-l+1;
	int n2 = r-m;
    int L[n1], R[n2], i, j, k;
    for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = 0; j = 0; k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
    while (i < n1) {
		arr[k] = L[i];
		i++; k++;
	}
    while (j < n2) {
		arr[k] = R[j];
		j++; k++;
	}
}
void mergeSort(int arr[], int l, int r) {
	if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
	}
}

int partition (int *arr, int low, int high) {
	int pivot = arr[high];
	int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}
void quickSort(int *arr, int low, int high) {
	if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
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
    quickSort(ar, 0, n-1);
    clock_t end = clock();
    printf("Time taken by Quick Sort : %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    // printf("Sorted array : ");
	// print(ar, n);

    start = clock();
    mergeSort(br, 0, n-1);
    end = clock();
    printf("Time taken by Merge Sort : %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    // printf("Sorted array : ");
	// print(br, n);
	return 0;
}