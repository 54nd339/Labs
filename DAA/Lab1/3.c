#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int main() {
    printf("Enter the size of array : ");
    int n; scanf("%d", &n);
    int *ar = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &ar[i]);

	int firstl, secondl;
	int firsts, seconds;
	firstl = secondl = INT_MIN;
	firsts = seconds = INT_MAX;

	for (int i = 0; i < n; i++) {
		if (ar[i] > firstl) {
			secondl = firstl;
			firstl = ar[i];
		}
        else if (ar[i] > secondl && ar[i] != firstl)
			secondl = ar[i];

        if (ar[i] < firsts) {
			seconds = firsts;
			firsts = ar[i];
		}
        else if (ar[i] < seconds && ar[i] != firsts)
			seconds = ar[i];	
	}
    printf("\nThe second largest element is %d", secondl);
    printf("\nThe second smallest element is %d", seconds);
	return 0;
}
