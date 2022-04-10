#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int *arr;
    int front, rear;
    unsigned size;
}Queue;
Queue *create(int size){
    Queue *queue = malloc(sizeof(Queue));
    queue->size = size;
    queue->front = queue->rear = -1;
    queue->arr = (int*)malloc(queue->size * sizeof(int));
    return queue;
}
Queue *copy(Queue *queue){
    Queue *tqueue = malloc(sizeof(Queue));
    tqueue->size = queue->size;
    tqueue->front = tqueue->rear = -1;
    tqueue->arr = (int*)malloc(queue->size * sizeof(int));
    return tqueue;
}
void enqueue(Queue *queue, int num){
    if(queue->front==-1 && queue->rear==-1)
        queue->front = 0;
    queue->arr[++queue->rear] = num;
}
int dequeue(Queue *queue){
    int val = queue->arr[queue->front++];
    if(queue->front>queue->rear)
        queue->front = queue->rear = -1;
    return val;
}
void display(Queue *queue){
    if(queue->front == -1){
        printf("Empty\n");
        return;
    }
    for(int i=queue->front; i<=queue->rear; i++)
            printf("%d ",queue->arr[i]);
    printf("\n");
}

void push(Queue *queue, int x){
    if(queue->rear == queue->size-1){
        printf("Stack overflow\n");
        return;
    }
    enqueue(queue, x);
}
int pop(Queue **queue){
    if((*queue)->front == -1){
        printf("Stack underflow\n");
        return -1;
    }
    Queue *tqueue = copy(*queue);
    while((*queue)->front < (*queue)->rear)
        enqueue(tqueue, dequeue(*queue));
    int val = dequeue(*queue);
    *queue = tqueue;
    return val;
}

void main(){
    printf("Enter size of the queue : ");
    int num; scanf("%d",&num);
    Queue *queue = create(num);
    printf("1. Push\n2. Pop\n3. Display\n0. Exit\n");  
    while(1){  
        printf("\nEnter your choice : ");
        int ch; scanf("%d",&ch);
        if(ch == 1){
            printf("Enter the value : ");
            scanf("%d",&num);
            push(queue, num);
        }
        else if (ch == 2){
            int val = pop(&queue);
            if(val != -1)
                printf("Dequeued Element : %d\n",val);
        }
        else if (ch == 3) display(queue);
        else if (ch == 0) break;
        else printf("Please Enter valid choice\n");
    }    
}