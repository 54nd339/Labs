#include <stdio.h>
int main() {
    int n, tq, t = 0;
	printf("Enter No. of processes : ");
    scanf("%d",&n);
    printf("Enter the time quanta : ");
    scanf("%d",&tq);
    int p[n], bt[n], wt[n], tat[n], ct[n], rem_bt[n];
    
    printf("\nEnter process IDS :\n");
    for(int i=0; i<n; i++)
        scanf("%d",&p[i]);

    printf("\nEnter Burst time of all p :\n");
    for(int i=0; i<n; i++){
        scanf("%d",&bt[i]);
        rem_bt[i] = bt[i];
    }

    while (1) {
		int done = 1;
        for (int i = 0 ; i < n; i++) {
            if (rem_bt[i] > 0) {
				done = 0;
                if (rem_bt[i] > tq) {
                    t += tq; rem_bt[i] -= tq;
				}
                else {
                    t += rem_bt[i];
                    ct[i] = t;
                    wt[i] = ct[i] - bt[i];
                    rem_bt[i] = 0;
				}
			}
		}
        if (done) break;
	}

	printf("\nProcess\tBurst Time\tWaiting Time\tTurn-Around Time\tCompletion Time\n");
    int tot_wt = 0, tot_tat = 0;
    for (int i = 0 ; i < n ; i++) {
        tat[i] = bt[i] + wt[i];
        tot_wt += wt[i];
        tot_tat += tat[i];
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i],bt[i],wt[i],tat[i],ct[i]);
    }
    
    printf("Average waiting time = %.2f\n", (float)tot_wt/n);
    printf("Average turn around time = %.2f\n", (float)tot_tat/n);
	return 0;
}