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

int isEmpty(Queue *queue){
    if(queue->front == -1){
        printf("Queue underflow\n");
        return 1;
    }
    return 0;
}
int isFull(Queue *queue){
    if((queue->front == 0 && queue->rear == queue->size-1) 
        || (queue->rear == queue->front-1)){
        printf("Queue overflow\n");
        return 1;
    }
    return 0;
}

void insertfront(Queue *queue, int key){
    if (isFull(queue)) return;
    else if (queue->front == -1)
        queue->front = queue->rear = 0;
	else if (queue->front == 0)
		queue->front = queue->size - 1 ;
    else 
		queue->front--;
    queue->arr[queue->front] = key ;
}
void insertrear(Queue *queue, int key){
    if(isFull(queue)) return;
    else if (queue->front == -1)
        queue->front = queue->rear = 0;
    else if (queue->rear == queue->size-1)
        queue->rear = 0;
    else
        queue->rear++;
    queue->arr[queue->rear] = key;
}

int deletefront(Queue *queue){
    if(isEmpty(queue)) return -1;
    int val = queue->arr[queue->front];
    if(queue->front == queue->rear)
        queue->front = queue->rear = -1;
    else if (queue->front == queue->size-1)
        queue->front = 0;
    else queue->front++;
    return val;
}
int deleterear(Queue *queue){
    if(isEmpty(queue)) return -1;
    int val = queue->arr[queue->rear];
    if(queue->front == queue->rear)
        queue->front = queue->rear = -1;
	else if (queue->rear == 0)
		queue->rear = queue->size-1;
	else queue->rear--;
    return val;
}

void peek(Queue *queue){
    if(isEmpty(queue)) return;
    printf("First element : %d\n",queue->arr[queue->front]);
    printf("Last element : %d\n",queue->arr[queue->rear]);
}
void display(Queue *queue){
    if(isEmpty(queue)) return;
    if(queue->rear >= queue->front)
        for(int i=queue->front; i<=queue->rear; i++)
            printf("%d ",queue->arr[i]);
    else{
        for(int i=queue->front; i<queue->size; i++)
            printf("%d ",queue->arr[i]);
        for(int i=0; i<=queue->rear; i++)
            printf("%d ",queue->arr[i]);
    }
    printf("\n");
}

void IRD(){
    printf("Enter size of the queue : ");
    int num; scanf("%d",&num);
    Queue *queue = create(num);
    printf("1. Enqueue\n2. Dequeue (front)\n3. Dequeue (rear)\n");
    printf("4. Peek\n5. Display\n6.IsEmpty\n7.IsFull\n0. Exit\n");  
    while(1){  
        printf("\nEnter your choice : ");
        int ch; scanf("%d",&ch);
        if(ch == 1){
            printf("Enter the value : ");
            scanf("%d",&num);
            insertrear(queue, num);
        }
        else if (ch == 2){
            int val = deletefront(queue);
            if(val != -1)
                printf("Dequeued Element : %d\n",val);
        }
        else if (ch == 3){
            int val = deleterear(queue);
            if(val != -1)
                printf("Dequeued Element : %d\n",val);
        }
        else if (ch == 4) peek(queue);
        else if (ch == 5) display(queue);
        else if (ch == 6) {
            if(!isEmpty(queue)) printf("Queue Not Empty\n");
        }
        else if (ch == 7) {
            if(!isFull(queue)) printf("Queue Not Full\n");
        }
        else if (ch == 0) break;
        else printf("Please Enter valid choice\n");
    }
}
void ORD(){
    printf("Enter size of the queue : ");
    int num; scanf("%d",&num);
    Queue *queue = create(num);
    printf("1. Enqueue (rear)\n2. Enqueue (front)\n3. Dequeue\n");
    printf("4. Peek\n5. Display\n6.IsEmpty\n7.IsFull\n0. Exit\n");  
    while(1){  
        printf("\nEnter your choice : ");
        int ch; scanf("%d",&ch);
        if(ch == 1){
            printf("Enter the value : ");
            scanf("%d",&num);
            insertrear(queue, num);
        }
        else if (ch == 2){
            printf("Enter the value : ");
            scanf("%d",&num);
            insertfront(queue, num);
        }
        else if (ch == 3){
            int val = deletefront(queue);
            if(val != -1)
                printf("Dequeued Element : %d\n",val);
        }
        else if (ch == 4) peek(queue);
        else if (ch == 5) display(queue);
        else if (ch == 6) {
            if(!isEmpty(queue)) printf("Queue Not Empty\n");
        }
        else if (ch == 7) {
            if(!isFull(queue)) printf("Queue Not Full\n");
        }
        else if (ch == 0) break;
        else printf("Please Enter valid choice\n");
    }
}
int main(){
    printf("1. Input Restricted Deque\n");
    printf("2. Output Restricted Deque\n");
    printf("\nEnter your choice : ");
    check:
    int ch; scanf("%d",&ch);
    if(ch == 1) IRD();
    else if(ch == 2) ORD();
    else {
        printf("Please Enter valid choice : ");
        goto check;
    }
	return 0;
}