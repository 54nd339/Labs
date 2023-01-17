#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct {
    int task;
    int machine;
    int time;
} Result;

int main(){
    //number of tasks , number of machines
    printf("\nEnter number of machines and tasks: ");
    int nT, nM; scanf("%d%d", &nM, &nT);
    /* Data :
          T1   T2   T3
    M1 | 140 | 20 | 60 |
    M2 | 100 | 100 | 70 |
    */
    int **maxMin = malloc(nM * sizeof(int*));
    for(int i = 0; i < nM; i++){
        maxMin[i] = malloc(nT * sizeof(int));
    }
    int **temp = malloc(nM * sizeof(int*));
    for(int i = 0; i < nM; i++){
        temp[i] = malloc(nT * sizeof(int));
    }
    int spantime = 0;
    printf("Fill Data :\n");
    for(int i = 0; i < nM; i++)
        for(int j = 0; j < nT; j++) {
            scanf("%d", &maxMin[i][j]);
            temp[i][j] = maxMin[i][j];
        }
    printf("\nOriginal Data\n");
    for(int i = 0; i < nM; i++) {
        for(int j = 0; j < nT; j++)
            printf("%d ",maxMin[i][j]);
        printf("\n");
    }

    Result *res = malloc(nT * sizeof(Result));
    int ptr = -1; //Indicates if result set is full or not

    while(ptr < nT-1) {
        int *time = malloc(nT * sizeof(int));
        int *machine = malloc(nT * sizeof(int));

        // Find minimum time for each task
        for(int j = 0; j < nT; j++){
            int mintime = INT_MAX;
            int pos = -1;
            for(int i = 0; i < nM; i++){
                if(maxMin[i][j] < mintime){
                    mintime = maxMin[i][j];
                    pos = i;
                }
            }
            time[j] = mintime;
            machine[j] = pos;
        }
        // Now we find task with maximum time
        int maxtime = INT_MIN;
        int pos = -1;
        for(int j = 0; j < nT; j++){
            if(time[j] > maxtime && time[j] != INT_MAX){
                maxtime = time[j];
                pos = j;
            }
        }

        res[++ptr].task = pos;
        res[ptr].machine = machine[pos];
        res[ptr].time = temp[machine[pos]][pos];
        if(maxtime > spantime)
            spantime = maxtime;
        // resetting states
        for(int i = 0; i < nM; i++){
            for(int j = 0; j < nT; j++){
                if(j == res[ptr].task)
                    maxMin[i][j] = INT_MAX;
                else if(i == res[ptr].machine && maxMin[i][j] != INT_MAX)
                    maxMin[i][j] += maxtime;
                else
                    continue;
            }
        }
    }

    printf("\nScheduled Task are :\n");
    for(int i = 0; i < nT; i++){
        printf("\nTask %d Runs on Machine %d with Time %d units\n", res[i].task+1, res[i].machine+1, res[i].time);
    }
    printf("\nTotal elapsed time : %d units\n", spantime);
    return 0;
}