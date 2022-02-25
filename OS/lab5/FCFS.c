#include <stdio.h>
typedef struct {
    int id, bt, at;
}Process;
int main() {
    printf("Enter No. of processes : ");
    int n; scanf("%d",&n);
    Process p[n];int wt[n], tat[n];
    
    printf("\nEnter process IDS :\n");
    for(int i=0; i<n; i++){
        scanf("%d",&p[i].id);
        p[i].at = 0;
    }

    printf("\nEnter Burst time of all p :\n");
    for(int i=0; i<n; i++)
        scanf("%d",&p[i].bt);
    
    printf("\nEnter 0 if AT = 0 else anything : ");
    int ch; scanf("%d",&ch);
    if(ch!=0) {
        printf("Enter Arrival time of all p :\n");
        for(int i=0; i<n; i++)
            scanf("%d",&p[i].at);

        for (int i = 0; i < n-1; i++) {
            int flag = 0;
            for (int j = 0; j < n-i-1; j++) {
                if (p[j].at > p[j+1].at) {
                    Process temp = p[j];
                    p[j] = p[j+1];
                    p[j+1] = temp;
                    flag = 1;
                }
            }
            if (flag == 0) break;
        }
    }
    wt[0] = 0;
    int idle = [0].at, start = p[0].at;
    for (int i = 1; i < n ; i++) {
        start += p[i-1].bt;
        wt[i] = start - p[i].at;
        if (wt[i] < 0){
            idle = wt[i]*-1;
            wt[i] = 0; start = p[i].at;
        }
    }

    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurn-Around Time\tCompletion Time\n");
    int tot_wt = 0, tot_tat = 0, exit;
    for (int i = 0 ; i < n ; i++) {
        tat[i] = p[i].bt + wt[i];
        tot_wt += wt[i];
        tot_tat += tat[i];
        exit = tat[i] + p[i].at;
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].id,p[i].at,p[i].bt,wt[i],tat[i],exit);
    }
    printf("CPU Idle time = %d\n", idle);
    printf("Efficiency = %.2f% \n", (float)((exit-idle)*100)/exit);
    printf("Average waiting time = %.2f\n", (float)tot_wt/n);
    printf("Average turn around time = %.2f\n", (float)tot_tat/n);
    return 0;
}