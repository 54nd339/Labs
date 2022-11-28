#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
    
pthread_mutex_t mutex; //protect service from the same CPU from other threads
sem_t cpu;             //CPU ready or not
sem_t pro;             //process ready or not
int n, wait=0, done=0;

void *CPU() {   
    for(int i=0; i<n; i++) {
        //try to get a peocess or sleep if there is none
        sem_wait(&pro);
        //wake up CPU to process
        sem_post(&cpu); 

        //lock mutex to protect the CPU from other processes
        pthread_mutex_lock(&mutex);
        usleep((rand() % 401)*1000);
        wait--; done++;
        pthread_mutex_unlock(&mutex);

        printf("A process Completed.\n");
        printf("Waiting : %d\tDone : %d\n", wait, done);
    }
}

void *process() {
    printf("A process is waiting.\n");
    //set the process ready to be processed
    sem_post(&pro);
    wait++;
    //wait for the CPU to get ready 
    sem_wait(&cpu);
    printf("A process is being processed.\n");
}
void *make_process(){
    for (int i = 0; i < n; i++) {
        pthread_t p;
        pthread_create(&p, NULL, process, NULL);  
    }
}

int main(){
    printf("Enter the number of processes : ");
    scanf("%d", &n);
    pthread_t pro_id;
    pthread_t cpu_id;
    pthread_mutex_init(&mutex, NULL);
    sem_init(&pro, 0, 0);
    sem_init(&cpu, 0, 0);

    pthread_create(&cpu_id, NULL, CPU, NULL);
    pthread_create(&pro_id, NULL, make_process, NULL);
    
    pthread_join(cpu_id, NULL);
    pthread_join(pro_id, NULL);
 
    pthread_mutex_destroy(&mutex);
    sem_destroy(&cpu);
    sem_destroy(&pro);
    return 0;  	
}