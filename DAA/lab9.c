#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int tabulate(int *arr, int n) {
    int dp[n][n], i;
    for (i = 1; i < n; i++)
		dp[i][i] = 0;

	for (int len = 2; len < n; len++) {
		for (i = 1; i < n-len+1; i++) {
			int j = i+len-1;
			dp[i][j] = INT_MAX;
			for (int k = i; k <= j-1; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
				if (cost < dp[i][j])
					dp[i][j] = cost;
			}
		}
	}
	return dp[1][n - 1];
}

int memoize(int *arr, int i, int j, int **dp) {
    if (i >= j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int ans = INT_MAX;
    for (int k = i; k < j; k++) {
        int temp = memoize(arr, i, k, dp) + memoize(arr, k + 1, j, dp) + arr[i - 1] * arr[k] * arr[j];
        if (temp < ans)
            ans = temp;
    }
    dp[i][j] = ans;
    return ans;
}

int main() {
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);
    int arr[n + 1];
    printf("Enter the dimensions of the matrices: ");
    for (int i = 0; i <= n; i++)
        scanf("%d", &arr[i]);

    int **dp = (int **)malloc(sizeof(int *) * (n + 1));
    for (int i = 0; i <= n; i++)
        dp[i] = (int *)malloc(sizeof(int) * (n + 1));
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = -1;

    printf("Minimum number of multiplications required: %d", memoize(arr, 1, n, dp));
    printf("\nMinimum number of multiplications required: %d", tabulate(arr, n + 1));
    return 0;
}

/*
Enter the number of matrices : 4
Enter the dimensions of each matrix :
40 20 30 10 20
Minimum number of multiplications required : 22000
Minimum number of multiplications required : 22000
*/