#include <stdio.h>
#include <stdlib.h>
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int main() {
    printf("Enter No. of processes : ");
    int n; scanf("%d",&n);
    int p[n], bt[n], wt[n], tat[n], start[n];
    int *at = calloc(n, sizeof(int));

    printf("\nEnter process IDS :\n");
    for(int i=0; i<n; i++)
    scanf("%d",&p[i]);

    printf("\nEnter Burst time of all p :\n");
    for(int i=0; i<n; i++)
    scanf("%d",&bt[i]);

    printf("\nEnter 0 if AT = 0 else anything : ");
    int ch; scanf("%d",&ch);
    if(ch!=0) {
        printf("Enter Arrival time of all p :\n");
        for(int i=0; i<n; i++)
        scanf("%d",&at[i]);

        for (int i = 0; i < n-1; i++) {
            int flag = 0;
            for (int j = 0; j < n-i-1; j++) {
                if (at[j] > at[j+1]) {
                    swap(&p[j], &p[j+1]);
                    swap(&bt[j], &bt[j+1]);
                    swap(&at[j], &at[j+1]); flag = 1;
                }
            }
            if (flag == 0) break;
        }
    }

    start[0] = at[0]; wt[0] = 0;
    for (int i = 1; i < n ; i++) {
        start[i] = start[i-1] + bt[i-1];
        wt[i] = start[i] - at[i];
        if (wt[i] < 0){
            wt[i] = 0; start[i] = at[i];
        }
    };
    printf("\np\tArrival Time\tBurst Time\tWaiting Time\tTurn-Around Time\tCompletion Time\n");
    int tot_wt = 0, tot_tat = 0;
    for (int i = 0 ; i < n ; i++) {
        tat[i] = bt[i] + wt[i];
        tot_wt += wt[i];
        tot_tat += tat[i];
        int exit = tat[i] + at[i];
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i],at[i],bt[i],wt[i],tat[i],exit);
    }
    printf("Average waiting time = %f\n", (float)tot_wt/n);
    printf("Average turn around time = %f\n", (float)tot_tat/n);
    return 0;
}