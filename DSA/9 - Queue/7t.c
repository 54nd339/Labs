#include<stdio.h>
#include<stdlib.h>
struct Queue {
    int *arr;
    int front, rear;
    unsigned size;
};
struct Queue *create(int size){
    struct Queue *queue = malloc(sizeof(struct Queue));
    queue->size = size;
    queue->front = queue->rear = -1;
    queue->arr = (int*)malloc(queue->size * sizeof(int));
    return queue;
}
struct Queue *copy(struct Queue *queue){
    struct Queue *tqueue = malloc(sizeof(struct Queue));
    tqueue->size = queue->size;
    tqueue->front = tqueue->rear = -1;
    tqueue->arr = (int*)malloc(queue->size * sizeof(int));
    return tqueue;
}

void enqueue(struct Queue *queue, int num){
    if(queue->front==-1 && queue->rear==-1)
        queue->front = 0;
    queue->arr[++queue->rear]=num;
}
int dequeue(struct Queue *queue){
    int val = queue->arr[queue->front++];
    if(queue->front>queue->rear)
        queue->front=queue->rear=-1;
    return val;
}
void display(struct Queue *queue){
    if(queue->front==-1){
        printf("Empty\n");
        return;
    }
    for(int i=queue->front;i<=queue->rear;i++)
            printf("%d ",queue->arr[i]);
    printf("\n");
}

void push(struct Queue *queue, int x){
    if(queue->rear == queue->size-1){
        printf("Stack overflow\n");
        return;
    }
    struct Queue *tqueue = copy(queue);
    while(queue->front!=-1)
        enqueue(tqueue, dequeue(queue));
    enqueue(queue, x);
    while(tqueue->front!=-1)
        enqueue(queue, dequeue(tqueue));
}
int pop(struct Queue *queue){
    if(queue->front==-1){
        printf("Stack underflow\n");
        return -1;
    }
    return dequeue(queue);
}

void main(){
    int ch, num;
    printf("Enter size of the queue : ");
    scanf("%d",&num);
    struct Queue *queue=create(num);
    printf("1. Push\n2. Pop\n3. Display\n0. Exit\n");  
    while(1){  
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        if(ch==1){
            printf("Enter the value : ");
            scanf("%d",&num);
            push(queue, num);
        }
        else if (ch==2){
            int val=pop(queue);
            if(val!=-1)
                printf("Dequeued Element : %d\n",val);
        }
        else if (ch==3) display(queue);
        else if (ch==0) break;
        else printf("Please Enter valid choice\n");
    }    
}