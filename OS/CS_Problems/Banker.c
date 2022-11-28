#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, m;
    printf("Enter No. of processes : ");
	scanf("%d", &n);
	printf("Enter No. of Resources : ");
	scanf("%d", &m);
    int alloc[n][m], max[n][m], need[n][m];
    int avail[m], f[n], ans[n], ind = 0;
    for(int i = 0; i < n; i++){
        printf("Enter resources for p%d : ",i);
        for(int j = 0; j < m; j++)
            scanf("%d",&alloc[i][j]);
    }
    for(int i = 0; i < n; i++){
        printf("Enter max resources for p%d : ",i);
        for(int j = 0; j < m; j++)
            scanf("%d",&max[i][j]);
    }
	printf("Enter Available resources : ");
    for(int j = 0; j < m; j++)
        scanf("%d",&avail[j]);

	for (int k = 0; k < n; k++) f[k] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			need[i][j] = max[i][j] - alloc[i][j];
	}
	for (int k = 0; k < 5; k++) {
		for (int i = 0; i < n; i++) {
			if (f[i] == 0) {
                int flag = 0;
				for (int j = 0; j < m; j++) {
					if (need[i][j] > avail[j]){
						flag = 1; break;
					}
				}
				if (flag == 0) {
					ans[ind++] = i;
					for (int y = 0; y < m; y++)
						avail[y] += alloc[i][y];
					f[i] = 1;
				}
			}
		}
	}

	int flag = 1;
	for(int i = 0; i < n; i++) {
        if(f[i]==0) {
            printf("The following system is not safe");
            exit(0);
        }
	}
	if(flag==1) {
        printf("Following is the SAFE Sequence\n");
        for (int i = 0; i < n - 1; i++)
            printf(" P%d ->", ans[i]);
        printf(" P%d", ans[n - 1]);
	}
	return 0;
}