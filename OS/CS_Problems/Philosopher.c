#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define THINKING 2
#define HUNGRY 1
#define EATING 0
#define LEFT (phnum + n-1) % n
#define RIGHT (phnum + 1) % n

sem_t *S;
pthread_mutex_t mutex;
int *state, *phil, n;

void check(int phnum) {
	if (state[phnum] == HUNGRY
		&& state[LEFT] != EATING
		&& state[RIGHT] != EATING) {
        state[phnum] = EATING;

		printf("Philosopher %d takes fork %d and %d\n", phnum + 1, LEFT + 1, phnum + 1);
		printf("Philosopher %d is Eating\n", phnum + 1);

		sem_post(&S[phnum]); //only for put()
	}
}

void lift(int phnum) {
    pthread_mutex_lock(&mutex);
    state[phnum] = HUNGRY;
    printf("Philosopher %d is Hungry\n", phnum + 1);
	check(phnum);
	pthread_mutex_unlock(&mutex);
	sem_wait(&S[phnum]);
}

void put(int phnum) {
    pthread_mutex_lock(&mutex);
    state[phnum] = THINKING;
    printf("Philosopher %d putting fork %d and %d down\n", phnum + 1, LEFT + 1, phnum + 1);
	printf("Philosopher %d is thinking\n", phnum + 1);
	check(LEFT); check(RIGHT);
    pthread_mutex_unlock(&mutex);
}

void* philosopher(void* num) {
	for (int i = 0; i < n; i++) {
        lift(*((int *)num));
        put(*((int *)num));
        printf("\n");
	}
}

int main() {
    printf("Enter No. of philosophers : ");
    scanf("%d",&n);
    pthread_t pid[n];
    pthread_mutex_init(&mutex, NULL);

    S = malloc(n*sizeof(sem_t));
    state = malloc(n*sizeof(int));
    phil = malloc(n*sizeof(int));

    for(int i = 0; i < n; i++){
        phil[i] = i;
        sem_init(&S[i], 0, 0);
    }

	for (int i = 0; i < n; i++) {
        pthread_create(&pid[i], NULL, philosopher, &phil[i]);
        printf("Philosopher %d is thinking\n", i + 1);
	}

	for (int i = 0; i < n; i++)
        pthread_join(pid[i], NULL);

    pthread_mutex_destroy(&mutex);
    for (int i = 0; i < n; i++)
        sem_destroy(&S[i]);
    return 0;
}