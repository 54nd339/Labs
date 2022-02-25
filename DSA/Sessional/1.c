#include <stdio.h>
#include <stdlib.h>
void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}
int partition (int *arr025, int low, int high) {
	int pivot = arr025[high];
	int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr025[j] < pivot) {
			i++;
			swap(&arr025[i], &arr025[j]);
		}
	}
	swap(&arr025[i + 1], &arr025[high]);
	return (i + 1);
}
void quickSort(int *arr025, int low, int high) {
	if (low < high) {
        int pi = partition(arr025, low, high);
        quickSort(arr025, low, pi - 1);
		quickSort(arr025, pi + 1, high);
	}
}

int *in(int *arr025025, int n){
    int *ar025 = malloc(n * sizeof(int));
    printf("Enter Elements : ");
    for (int i = 0; i < n; i++)
        scanf("%d", &ar025[i]);
    return ar025;
}
void print(int *arr025025, int size) {
	for (int i=0; i < size; i++)
		printf("%d ", arr025025[i]);
	printf("\n");
}

int *merArr(int *ar1, int n1, int *ar2, int n2) {
    int *out025 = malloc((n1+n2)*sizeof(int)), j=0;
    for(int i = 0; i < n1; i++) 
        out025[j++] = ar1[i];
    for(int i = 0; i < n2; i++)
        out025[j++] = ar2[i];
    return out025;
}
int main() {
    printf("\nArray 1 :\n");
    printf("Enter no. of elements : ");
    int n1; scanf("%d", &n1);
    int *ar1 = in(ar1, n1);
    printf("Array 1 : ");
	print(ar1, n1);

    printf("\nArray 2 :\n");
    printf("Enter no. of elements : ");
    int n2; scanf("%d", &n2);
    int *ar2 = in(ar2, n2);
    printf("Array 2 : ");
	print(ar2, n2);

    printf("\nOut : ");
    int *out025 = merArr(ar1, n1, ar2, n2);
    quickSort(out025, 0, n1+n2-1);
	print(out025, n1+n2);
	return 0;
}