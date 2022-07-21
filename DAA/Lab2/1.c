#include <stdio.h>
#include <stdlib.h>
int count = 0;
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
            count++;
        }
        swap(&arr[min_ind], &arr[i]);
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

    selectionSort(ar, n);
	printf("Sorted array : ");
	print(ar, n);
    
	printf("No. of iteration : %d", count);
	return 0;
}