#include <stdio.h>
#include <stdlib.h>
typedef struct heap {
    int *arr, size, capacity;
}Heap;
void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}
void heapify(int *arr, int n, int i){
    int largest = i;
    int l = 2*i+1, r = 2*i+2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        swap(&(arr[i]), &(arr[largest]));
        heapify(arr, n, largest);
    }
}
void heapSort(int *arr, int n) {
    for (int i = n/2-1; i >= 0; i--)
        heapify(arr, n, i);
 
    for (int i = n - 1; i > 0; i--) {
        swap(&(arr[0]), &(arr[i]));
        heapify(arr, i, 0);
    }
}

void insertNode(Heap *h, int Key) {
    h->size++;
    int i = h->size - 1;
    h->arr[i] = Key; int j = (i-1)/2;
    while (i != 0 && h->arr[j] < h->arr[i]) {
        swap(&(h->arr[i]), &(h->arr[j]));
        i = j; j = (i-1)/2;
    }
}
void deleteNode(Heap *h, int i) {
    h->arr[i] = h->arr[h->size-1];
    h->size--;
    heapify(h->arr, h->size, i);
}
void print(Heap h) {
    for (int i = 0; i < h.size; ++i)
        printf("%d ", h.arr[i]);
    printf("\n");
}

int main() {
    Heap *h = (Heap*)malloc(sizeof(Heap));
    printf("Enter the size of the array: ");
    scanf("%d", &h->capacity);
    h->arr = (int*)malloc(h->capacity * sizeof(int));
    h->size = 0;

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Sort\n0. Exit\nEnter choice : ");
        int ch; scanf("%d", &ch);
        switch (ch) {
            case 1: if (h->size == h->capacity)
                        printf("Heap is full :\n");
                    else {
                        printf("Enter the key to be inserted: ");
                        int key; scanf("%d", &key);
                        insertNode(h, key);
                    }
                    print(*h);
                    break;
            case 2: if (h->size == 0) {
                        printf("Heap is empty\n");
                        break;
                    }
                    printf("Enter the index of the node to be deleted: ");
                    int i; scanf("%d", &i);
                    deleteNode(h, i);
                    print(*h);
                    break;
            case 3: heapSort(h->arr, h->size);
                    print(*h);
                    break;
            case 0: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}