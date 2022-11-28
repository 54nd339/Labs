#include <stdio.h>
typedef struct {
    int id, bt, at;
}Process;
void update(Process *p, int t, int n, int MPI, int queue[]){
	if(t <= p[n-1].at){
        int new = 0;
        for(int j = (MPI+1); j < n; j++){
            if(p[j].at <= t){
                if(MPI < j){
                    MPI = j; new = 1;
                }
            }
        }
        if(new){
            int ind0;
            for(int i = 0; i < n; i++){
                if(queue[i] == 0){
                    ind0 = i; break;
                }
            }
            queue[ind0] = MPI + 1;
        }
	}
}

int main(){
    int n, tq, t = 0, idle = 0;
    printf("Enter No. of processes : ");
	scanf("%d",&n);
	printf("Enter the time quanta : ");
	scanf("%d",&tq);
	Process p[n]; int wt[n], tat[n], ct[n];
    int queue[n], check[n], rem_bt[n], MPI = 0;

    printf("\nEnter process IDS :\n");
    for(int i=0; i<n; i++)
        scanf("%d",&p[i].id);

	printf("\nEnter Burst time of all p :\n");
	for(int i = 0; i < n; i++){
		scanf("%d",&p[i].bt);
		rem_bt[i] = p[i].bt;
        check[i] = 0;
		queue[i] = 0;
	}

	printf("\nEnter Arrival time of all p :\n");
	for(int i = 0; i < n; i++)
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
	t = p[0].at, queue[0] = 1;
	
	while(1){
		int done = 1;
		for(int i = 0; i < n; i++){
			if(rem_bt[i] != 0){
				done = 0; break;
			}
		}
		if(done) break;

		for(int i = 0; (i < n) && (queue[i] != 0); i++){
			int ctr = 0;
			//makes the queue till all process arrives
			while((ctr < tq) && (rem_bt[queue[0]-1] > 0)){
				rem_bt[queue[0]-1] --; ctr++;
                update(p, ++t, n, MPI, queue);
			} 
			//check if a process is done
            if((rem_bt[queue[0]-1] == 0) && (check[queue[0]-1] == 0)){
                ct[queue[0]-1] = t;		
				check[queue[0]-1] = 1;
			}
			//checks CPU idling
			int flag = 1;
			if(queue[n-1] == 0){
				for(int i = 0; i < n && queue[i] != 0; i++){
					if(check[queue[i]-1] == 0){
						flag = 0;
					}
				}
			}
			else flag = 0;
			if(flag){
				idle++;
				update(p, ++t, n, MPI, queue);
			}
			//Maintain the queue
			for(int i = 0; (i < n-1) && (queue[i+1] != 0) ; i++){
                int temp = queue[i];
                queue[i] = queue[i+1];
                queue[i+1] = temp;
            }
		}
	}

	printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurn-Around Time\tCompletion Time\n");
    int tot_wt = 0, tot_tat = 0;
    for (int i = 0 ; i < n ; i++) {
		tat[i] = ct[i] - p[i].at;
		wt[i] = tat[i] - p[i].bt;
        tot_wt += wt[i];
        tot_tat += tat[i];
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].id,p[i].at,p[i].bt,wt[i],tat[i],ct[i]);
    }
	printf("CPU Idle time = %d\n", idle);
    printf("Efficiency = %.2f% \n", (float)((t-idle)*100)/t);
	printf("Average waiting time = %.2f\n", (float)tot_wt/n);
    printf("Average tat around time = %.2f\n", (float)tot_tat/n);
	return 0;
}