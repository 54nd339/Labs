#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t wrt;
pthread_mutex_t mutex;
int data = 1;
int readcnt = 0;

void *writer(void *wno) {  
    sem_wait(&wrt);
    data *= 2;
    printf("Writer %d modified data to %d\n",*((int *)wno),data);
    sem_post(&wrt);
}

void *reader(void *rno) {
    pthread_mutex_lock(&mutex);
    if(++readcnt == 1) sem_wait(&wrt);
    pthread_mutex_unlock(&mutex);
    
    printf("Reader %d read data as %d\n",*((int *)rno),data);
    
    pthread_mutex_lock(&mutex);
    if(--readcnt == 0) sem_post(&wrt);
    pthread_mutex_unlock(&mutex);
}

int main() { 
    printf("Enter No. of reader : ");
    int rc; scanf("%d",&rc);
    printf("Enter No. of writer : ");
    int wc; scanf("%d",&wc);
    pthread_t read[rc],write[wc];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&wrt,0,1);

    int r[rc], w[wc];
    for(int i = 0; i < rc; i++)
        r[i] = i+1;
    for(int i = 0; i < wc; i++)
        w[i] = i+1;

    for(int i = 0; i < rc; i++)
        pthread_create(&read[i], NULL, reader, &r[i]);

    for(int i = 0; i < wc; i++) 
        pthread_create(&write[i], NULL, writer, &w[i]);

    for(int i = 0; i < rc; i++)
        pthread_join(read[i], NULL);

    for(int i = 0; i < wc; i++)
        pthread_join(write[i], NULL);

    pthread_mutex_destroy(&mutex);
    sem_destroy(&wrt);
    return 0;
}