#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t empty, full;
pthread_mutex_t mutex;
int *buffer, Size, x = 0;

void *producer(void *pno) {
    for(int i = 0; i < Size; i++) {
        int item = (rand() % Size) + 1;
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        buffer[x] = item;
        printf("Producer %d Inserted %d at %d\n", *((int *)pno),item,++x);
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
}
void *consumer(void *cno) { 
    for(int i = 0; i < Size; i++) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        int item = buffer[x-1];
        printf("Consumer %d Removed %d from %d\n",*((int *)cno),item,x--);
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
}

int main() {
    printf("Enter Size of buffer : ");
    scanf("%d",&Size);
    pthread_t pro[Size],con[Size];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty,0,Size);
    sem_init(&full,0,0);

    int a[Size]; buffer = malloc(Size*sizeof(int));
    for(int i = 0; i < Size; i++)
        a[i] = i+1;

    for(int i = 0; i < Size; i++)
        pthread_create(&pro[i], NULL, (void *)producer, (void *)&a[i]);

    for(int i = 0; i < Size; i++)
        pthread_create(&con[i], NULL, (void *)consumer, (void *)&a[i]);

    for(int i = 0; i < Size; i++)
        pthread_join(pro[i], NULL);

    for(int i = 0; i < Size; i++)
        pthread_join(con[i], NULL);

    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
    return 0;
}