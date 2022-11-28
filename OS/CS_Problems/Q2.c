#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

pthread_mutex_t mutex;  //to make sure 1 player at a time
sem_t *S; int n;        //n semaphores for n players

int next(int pid, int val) {
    int next;
    if(val!=6) {
        next = (pid + 1) % n;
        printf("Player %d passed the die to %d\n", pid + 1, next + 1);
    }
    else next = pid;
    return next;
}
void *player() {
    int pid = 0;
	do {
        pthread_mutex_lock(&mutex);     //Enters CS
        sem_post(&S[pid]);              //signals player is going to roll
        int val = (rand() % 6) + 1;
        printf("Player %d rolled and got %d\n", pid + 1, val);
        pthread_mutex_unlock(&mutex);   //exits CS
        sem_wait(&S[pid]);              //player waits for the next turn
        pid = next (pid, val);
	} while(1);
}

int main() {
    printf("Enter No. of players : ");
    input:
    scanf("%d",&n);
    if(n>4 || n<1){
        printf("Enter between 1 & 4 : ");
        goto input;
    }
    pthread_t pid;
    pthread_mutex_init(&mutex, NULL);

    S = malloc(n*sizeof(sem_t));
    for(int i = 0; i < n; i++)
        sem_init(&S[i], 0, 0);

	pthread_create(&pid, NULL, player, NULL);
    pthread_join(pid, NULL);

    pthread_mutex_destroy(&mutex);
    for (int i = 0; i < n; i++)
        sem_destroy(&S[i]);
    return 0;
}