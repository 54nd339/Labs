#include <stdio.h>
#include <limits.h>
int main() {
    printf("Enter No. of processes : ");
    int n; scanf("%d",&n);
    int p[n], bt[n], at[n], wt[n], tat[n], pr[n], rt[n], ct[n];
    
    printf("\nEnter process IDS :\n");
    for(int i=0; i<n; i++)
        scanf("%d",&p[i]);

    printf("\nEnter Burst time of all p :\n");
    for(int i=0; i<n; i++){
        scanf("%d",&bt[i]);
		at[i] = 0; rt[i] = bt[i];
	}

    printf("\nEnter Priority of all p :\n");
    for(int i=0; i<n; i++)
        scanf("%d",&pr[i]);
    
    printf("\nEnter 0 if AT = 0 else anything : ");
    int ch; scanf("%d",&ch);
    if(ch!=0) {
        printf("Enter Arrival time of all p :\n");
        for(int i=0; i<n; i++)
            scanf("%d",&at[i]);
    }

	int found = 0, ind = 0, minm = INT_MAX, idle = 0;
	for (int i=0, t=0; i<n; t++) {
		for (int j = 0; j < n; j++) {
			if ((at[j] <= t) && (pr[j] < minm) && rt[j] > 0) {
				minm = pr[j]; ind = j; found = 1;
			}
		}
		if (found) {
			if (--rt[ind] == 0) {
				i++; found = 0; minm = INT_MAX;
				ct[ind] = t + 1;
				tat[ind] = ct[ind] - at[ind];
				wt[ind] = tat[ind] - bt[ind];
				if (wt[ind] < 0) wt[ind] = 0;
			}
		}
		else idle++;
	}

	int tot_wt = 0, tot_tat = 0;
	printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurn-Around Time\tCompletion Time\n");
    for (int i = 0 ; i < n ; i++) {
        tot_wt += wt[i];
        tot_tat += tat[i];
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i],at[i],bt[i],wt[i],tat[i],ct[i]);
    }
    printf("CPU Idle time = %d\n", idle);
    printf("Efficiency = %.2f% \n", (float)((ct[n-1]-idle)*100)/ct[n-1]);
    printf("Average waiting time = %.2f\n", (float)tot_wt/n);
    printf("Average turn around time = %.2f\n", (float)tot_tat/n);
	return 0;
}