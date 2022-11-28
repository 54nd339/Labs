#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>
    
pthread_mutex_t mutex;
sem_t barb, cust, seat;

int chair_cnt, avail_cnt;
int totcust, left = 0, x;

void *barber(void *idp) {    
    int counter = 0;
    while(1) {
        sem_wait(&cust);
        sem_wait(&seat);
        avail_cnt++;
        sem_post(&barb);
        sem_post(&seat);
        
        pthread_mutex_lock(&mutex);
        usleep((rand() % 401)*1000);
        pthread_mutex_unlock(&mutex);
        printf("Customer[pid = %d] was served.\n", x);   
        
        counter++; 
        if(counter == (totcust - left)) break;
    }
}

void *customer(void *idp) {
    sem_wait(&seat); 
    if(avail_cnt >= 1) {
        avail_cnt--;
        printf("Customer[pid = %d] is waiting.\n", *((int *)idp));
        printf("Available seats: %d\n", avail_cnt);
        sem_post(&cust);
        sem_post(&seat);
        sem_wait(&barb);
        printf("Customer[pid = %d] is being served.\n", *((int *)idp)); 
        x = *((int *)idp);
    }
    else {
        sem_post(&seat); left++;
        printf("Customer[pid = %d] left.\n", *((int *)idp));
    }
}

int main(){
    printf("Enter the number of seats : ");
    scanf("%d", &chair_cnt);
    printf("Enter the number of customers : ");
    scanf("%d", &totcust);
    pthread_t cust_id[totcust];
    pthread_t barb_id;
    pthread_mutex_init(&mutex, NULL);
    sem_init(&cust, 0, 0);
    sem_init(&barb, 0, 0);
    sem_init(&seat, 0, 1);

    avail_cnt = chair_cnt;
    int cid[totcust];
    for(int i = 0; i < totcust; i++)
        cid[i] = i;

    pthread_create(&barb_id, NULL, barber, NULL);
    for(int i = 0; i < totcust; i++)
        pthread_create(&cust_id[i], NULL, customer, &cid[i]);
    
    pthread_join(barb_id, NULL);
    for(int i = 0; i < totcust; i++)
        pthread_join(cust_id[i], NULL);

    printf("Number of customers left : %d\n", left);
    return 0;  	
}