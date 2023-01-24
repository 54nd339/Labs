#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int id, bt, at, wt, tat, rt, ct;
} Process;
int main() {
    printf("Enter No. of processes : ");
    int n; scanf("%d",&n);
    Process *p = malloc(n * sizeof(Process));
    
    printf("\nEnter process IDS :\n");
    for(int i = 0; i < n; i++)
        scanf("%d",&p[i].id);

    printf("\nEnter Burst time of all p :\n");
    for(int i = 0; i < n; i++){
        scanf("%d",&p[i].bt);
        p[i].rt = p[i].bt;
        p[i].at = 0;
    }
    
    printf("\nEnter 0 if AT = 0 else anything : ");
    int ch; scanf("%d",&ch);
    if(ch != 0) {
        printf("Enter Arrival time of all p :\n");
        for(int i = 0; i < n; i++)
            scanf("%d", &p[i].at);
    }

	int found = 0, ind = 0, minm = INT_MAX, idle = 0;
	for (int i=0, t=0; i < n; t++) {
		for (int j = 0; j < n; j++) {
			if ((p[j].at <= t) && (p[j].rt < minm) && p[j].rt > 0) {
				minm = p[j].rt; ind = j; found = 1;
			}
		}
		if (found) {
			minm = --p[ind].rt;
			if (p[ind].rt == 0) {
				i++; found = 0; minm = INT_MAX;
				p[ind].ct = t + 1;
				p[ind].tat = p[ind].ct - p[ind].at;
				p[ind].wt = p[ind].tat - p[ind].bt;
				if (p[ind].wt < 0) p[ind].wt = 0;
			}
		}
		else idle++;
	}

	int tot_wt = 0, tot_tat = 0;
	printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurn-Around Time\tCompletion Time\n");
    for (int i = 0 ; i < n ; i++) {
        tot_wt += p[i].wt;
        tot_tat += p[i].tat;
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].id,p[i].at,p[i].bt,p[i].wt,p[i].tat,p[i].ct);
    }

    printf("CPU Idle time = %d\n", idle);
    printf("Efficiency = %.2f% \n", (float)((p[n-1].ct-idle)*100)/p[n-1].ct);
    printf("Average waiting time = %.2f\n", (float)tot_wt/n);
    printf("Average turn around time = %.2f\n", (float)tot_tat/n);
	return 0;
}