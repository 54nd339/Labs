#include <stdlib.h>
#include <stdio.h>
typedef struct PKT {
    int seqNo;
    char msg[100];
}pkt;

// implement queue using array of packets with size = window size
typedef struct QUEUE {
    pkt *arr;
    int front, rear, size;
}queue;
// initialize queue
queue *init(int size) {
    queue *q = (queue *)malloc(sizeof(queue));
    q->arr = (pkt *)malloc(sizeof(pkt) * size);
    q->front = q->rear = -1;
    q->size = size;
    return q;
}
// check if queue is empty
int isEmpty(queue *q) {
    return q->front == -1;
}
// check if queue is full
int isFull(queue *q) {
    return (q->rear + 1) % q->size == q->front;
}
// add packet to queue
void enqueue(queue *q, pkt p) {
    if (isFull(q)) {
        printf("Queue is full.\n");
        return;
    }
    if (isEmpty(q)) q->front = 0;
    q->rear = (q->rear + 1) % q->size;
    q->arr[q->rear] = p;
}
// remove packet from queue
pkt dequeue(queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return (pkt){-1, ""};
    }
    pkt p = q->arr[q->front];
    if (q->front == q->rear) q->front = q->rear = -1;
    else q->front = (q->front + 1) % q->size;
    return p;
}
// get front packet from queue
pkt front(queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return (pkt){-1, ""};
    }
    return q->arr[q->front];
}