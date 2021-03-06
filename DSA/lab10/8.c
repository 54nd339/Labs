#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct{
    int priority, value;
}item;
typedef struct{
    item *arr;
    int front, rear;
    unsigned size;
}Queue;
Queue *create(int size){
    Queue *queue = malloc(sizeof(Queue));
    queue->size = size; queue->front = queue->rear = -1;
    queue->arr = malloc(queue->size * sizeof(item));
    return queue;
}

int isEmpty(Queue *queue){
    if(queue->front==-1 || queue->front>queue->rear){
        printf("Queue underflow\n");
        return 1;
    }
    return 0;
}
int isFull(Queue *queue){
    if(queue->rear == queue->size-1){
        printf("Queue overflow\n");
        return 1;
    }
    return 0;
}

void enqueue(Queue *queue, int val, int prio){
    if(isFull(queue)) return;
    if(queue->front==-1 && queue->rear==-1)
        queue->front = 0;
    (queue->arr[++queue->rear]).value = val;
    (queue->arr[queue->rear]).priority = prio;
}
int peek(Queue *queue){
    if(isEmpty(queue)) return -1;
    int lp = INT_MAX, ind = -1;
    for (int i=queue->front; i<=queue->rear; i++) {
        if (lp == (queue->arr[i]).priority && ind > -1
            && (queue->arr[ind]).value < (queue->arr[i]).value) {
            lp = (queue->arr[i]).priority; ind = i;
        }
        else if (lp > (queue->arr[i]).priority) {
            lp = (queue->arr[i]).priority; ind = i;
        }
    }
    return ind;
}
int dequeue(Queue *queue){
    if(isEmpty(queue)) return -1;
    int ind = peek(queue);
    int val = (queue->arr[ind]).value;
    for (int i=ind; i<=queue->rear; i++)
        queue->arr[i] = queue->arr[i+1];
    queue->rear--;
    if(queue->front>queue->rear)
        queue->front = queue->rear = -1;
    return val;
}

void main(){
    printf("Enter size of the queue : ");
    int val; scanf("%d",&val);
    Queue *queue = create(val);
    printf("1. Enqueue\n2. Dequeue\n3. Peek\n0. Exit\n");  
    while(1){  
        printf("\nEnter your choice : ");
        int ch; scanf("%d",&ch);
        if(ch == 1){
            printf("Enter the value and priority : ");
            int prio; scanf("%d%d",&val,&prio);
            enqueue(queue, val, prio);
        }
        else if (ch == 2){
            int val = dequeue(queue);
            if(val != -1)
                printf("Dequeued Element : %d\n",val);
        }
        else if (ch == 3){
            int val = (queue->arr[peek(queue)]).value;
            printf("Peeked Element : %d\n",val);
        }
        else if (ch == 0) break;
        else printf("Please Enter valid choice\n");
    }    
}