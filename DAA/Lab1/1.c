#include <stdio.h>
#include <stdlib.h>
int main() {
    printf("Enter the size of array : ");
    int n; scanf("%d", &n);
    int *ar = malloc(n * sizeof(int));

    printf("Enter Array Element : ");
    for (int i = 0; i < n; i++)
        scanf("%d", &ar[i]);

    int max = ar[0], min = ar[0];
    for (int i = 1; i < n; i++) {
        if (max < ar[i])
            max = ar[i];
        if (min > ar[i])
            min = ar[i];
    }

    printf("Max : %d\n", max);
    printf("Min : %d\n", min);
    return 0;
}