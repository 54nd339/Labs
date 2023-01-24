#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pid, at, bt, wt, tat, start, exit;
} process;

void swap(process *xp, process *yp) {
    process temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int main() {
    printf("Enter No. of processes : ");
    int n; scanf("%d",&n);
    process *p = malloc(n * sizeof(process));

    printf("\nEnter process IDS :\n");
    for(int i = 0; i < n; i++)
    scanf("%d", &p[i].pid);

    printf("\nEnter Burst time of all p :\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &p[i].bt);
        p[i].at = 0;
    }

    printf("\nEnter 0 if AT = 0 else anything : ");
    int ch; scanf("%d", &ch);
    if(ch != 0) {
        printf("Enter Arrival time of all p :\n");
        for(int i = 0; i < n; i++)
        scanf("%d", &p[i].at);

        for (int i = 0; i < n-1; i++) {
            int flag = 0;
            for (int j = 0; j < n-i-1; j++) {
                if (p[j].at > p[j+1].at) {
                    swap(&p[j], &p[j+1]);
                    flag = 1;
                }
            }
            if (flag == 0) break;
        }
    }

    p[0].start = p[0].at; p[0].wt = 0;
    for (int i = 1; i < n ; i++) {
        p[i].start = p[i-1].start + p[i-1].bt;
        p[i].wt = p[i].start - p[i].at;
        if (p[i].wt < 0){
            p[i].wt = 0;
            p[i].start = p[i].at;
        }
    };

    printf("\np\tArrival Time\tBurst Time\tWaiting Time\tTurn-Around Time\tCompletion Time\n");
    int tot_wt = 0, tot_tat = 0;
    for (int i = 0 ; i < n ; i++) {
        p[i].tat = p[i].bt + p[i].wt;
        tot_wt += p[i].wt;
        tot_tat += p[i].tat;
        p[i].exit = p[i].tat + p[i].at;
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].wt, p[i].tat, p[i].exit);
    }
    printf("Average waiting time = %f\n", (float)tot_wt/n);
    printf("Average turn around time = %f\n", (float)tot_tat/n);
    return 0;
}