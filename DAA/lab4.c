#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void linearSearch(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    int index = -1;
       
    for(left = 0; left <= right; left++, right--) {
        if (arr[left] == x) {
            index = left; break;
        }
        if (arr[right] == x) {
            index = right; break;
        }
    }
    (index == -1)
        ? printf("Element is not present in array")
        : printf("Element is present at index %d", index);
}
int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}
 
int cmpfunc (const void *a, const void *b) {
   return (*(int*)a - *(int*)b);
}
int main() {
    printf("Enter the size of array : ");
    int n; scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
        arr[i] = rand() % (n+1);
    int ele = rand() % (n+1);

    printf("Original Array : ");
    for(int i = 0; i < n; i++)
        printf("%d ", &arr[i]);
    printf("\nElement to be searched : %d\n", ele);

    clock_t start = clock();
    linearSearch(arr, n, ele);
    clock_t end = clock();
    printf("\nTime taken by linear search : %f\n", (double)(end - start) / CLOCKS_PER_SEC);

    qsort(arr, n, sizeof(int), cmpfunc);
    start = clock();
    int result = binarySearch(arr, 0, n - 1, ele);
    (result == -1)
        ? printf("Element is not present in array")
        : printf("Element is present at index %d", result);
    end = clock();
    printf("\nTime taken by binary search : %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}