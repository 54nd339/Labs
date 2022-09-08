#include <stdio.h>
#include <stdlib.h>

typedef struct Activitiy {
	int start, finish;
}act;

void sort(act *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].finish > arr[j + 1].finish) {
                act t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
}

void printMaxActivities(act *arr, int n) {
	// Sort jobs according to finish time
	sort(arr, n);

	printf("Following activities are selected n");
	// The first activity always gets selected
	int i = 0;
	printf("(%d, %d)\n", arr[i].start, arr[i].finish);

	// Consider rest of the activities
	for (int j = 1; j < n; j++) {
        if (arr[j].start >= arr[i].finish) {
	        printf("(%d, %d)\n", arr[i].start, arr[i].finish);
            i = j;
        }
	}
}

// Driver program
int main() {
    printf("Enter no. of activities : ");
    int n; scanf("%d", &n);
    act *ar = malloc(n * sizeof(act));
    
    printf("Enter start and finish time of activities : ");
    for (int i = 0; i < n; i++)
        scanf("%d %d", &ar[i].start, &ar[i].finish);

	printMaxActivities(ar, n);
	return 0;
}