#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id, bt, at, wt, tat, start, exit;
} Process;
void swap(Process *xp, Process *yp) {
    Process temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void Sort(Process *arr, int n, int f) {
    for (int i = 0; i < n-1; i++) {
        int flag = 0;
        for (int j = 0; j < n-i-1; j++) {
			if (f==1 && arr[j].bt > arr[j+1].bt) {
                swap(&arr[j], &arr[j+1]);
                flag = 1;
            }
            if (f==2 && arr[j].at > arr[j+1].at) {
                swap(&arr[j], &arr[j+1]);
                flag = 1;
            }
        }
        if (flag == 0) break;
    }
}
int ind(Process *p, int n, int ele){
    for(int i = 0; i < n; i++)
        if(ele == p[i].id)
            return i;
}

int main() {
    printf("Enter No. of processes : ");
    int n; scanf("%d",&n);
    Process *p = malloc(n * sizeof(Process));
    Process *wait = malloc(n * sizeof(Process));
    
    printf("\nEnter process IDS :\n");
    for(int i = 0; i < n; i++){
        scanf("%d",&p[i].id);
        p[i].at = 0;
    }

    printf("\nEnter Burst time of all p :\n");
    for(int i = 0; i < n; i++)
        scanf("%d",&p[i].bt);
    
    printf("\nEnter 0 if AT = 0 else anything : ");
    int ch; scanf("%d",&ch);
    if(ch != 0) {
        printf("Enter Arrival time of all p :\n");
        for(int i = 0; i < n; i++)
            scanf("%d", &p[i].at);
        Sort(p, n, 2);

		int sum = p[0].at + p[0].bt;
		for(int i=1, j; i < n; i++){
			int count = 0;
			for(j = i; j < n; j++){
				if(p[j].at > sum){
                    last:
					Sort(wait, count, 1);
                    int in = ind(p, n, wait[0].id);
                    swap(&p[i], &p[in]);
					break;
				}
                wait[count++] = p[j];
                if(j == n-1) goto last;
			}
            if(j == n) break;
			sum += p[i].bt;
		}
    }
	else
		Sort(p, n, 1);
        
    p[0].start = p[0].at; p[0].wt = 0;
    for (int i = 1; i < n ; i++) {
        p[i].start = p[i-1].start+ p[i-1].bt;
        p[i].wt = p[i].start - p[i].at;
        if (p[i].wt < 0){
            p[i].wt = 0;
            p[i].start = p[i].at;
        }
    };

    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurn-Around Time\tCompletion Time\n");
    int tot_wt = 0, tot_tat = 0;
    for (int i = 0 ; i < n ; i++) {
        p[i].tat = p[i].bt + p[i].wt;
        tot_wt += p[i].wt;
        tot_tat += p[i].tat;
        p[i].exit = p[i].tat + p[i].at;
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].id,p[i].at,p[i].bt,p[i].wt,p[i].tat,p[i].exit);
    }
 
    printf("Average waiting time = %.2f\n", (float)tot_wt/(float)n);
    printf("Average turn around time = %.2f\n", (float)tot_tat/(float)n);
    return 0;
}