#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
	int key;
	struct Node *link;
}QNode;
typedef struct{
	QNode *front, *rear;
}Queue;

QNode* newNode(int k){
	QNode* temp = (QNode*)malloc(sizeof(QNode));
	temp->key = k; temp->link = NULL;
	return temp;
}
Queue* createQueue(){
	Queue* q = (Queue*)malloc(sizeof(Queue));
	q->front = q->rear = NULL;
	return q;
}

int isEmpty(Queue *q){
    if (q->front == NULL){
        printf("Queue is empty\n");
        return 1;
    }
    return 0;
}
void enQueue(Queue *q, int k){
    QNode* temp = newNode(k);
    if (q->front == NULL) 
		q->front = temp;
	else
        q->rear->link = temp;
	q->rear = temp;
    q->rear->link = q->front;
}
int deQueue(Queue *q){
	if(isEmpty(q)) return -1;
    QNode *temp = q->front;
    int val = temp->key;
    if (q->front == q->rear) {
        free(temp);
        q->front = q->rear = NULL;
    }
    else {
        q->front = q->front->link;
        q->rear->link = q->front;
        free(temp);
    }
    return val;
}

void display(Queue *q){
    if (isEmpty(q)) return;
    QNode *temp = q->front;
    do{
        printf("%d ",temp->key);
        temp = temp->link;
    }while(temp != q->front);
    printf("\n");
}
void peek(Queue* q){
    if (isEmpty(q)) return;
    printf("Front : %d\n",q->front->key);
    printf("Rear : %d\n",q->rear->key);
}

int main(){
	Queue* q = createQueue();
    printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Peek\n5. IsEmpty\n0. Exit\n");
    while(1){
        printf("\nEnter your choice : ");
        int ch; scanf("%d",&ch);
        if(ch == 1){
            printf("Enter the value : ");
            int in; scanf("%d",&in);
            enQueue(q, in);
        }
        else if(ch == 2) {
            int in = deQueue(q);
            if(in != -1) printf("Dequeued Element : %d\n",in);
        }
        else if(ch == 3) display(q);
        else if(ch == 4) peek(q);
        else if(ch == 5) {
            if(!isEmpty(q)) printf("Queue Not Empty\n");
        }
        else if(ch == 0) break;
        else printf("Please Enter valid choice\n");
    }
    return 0;
}