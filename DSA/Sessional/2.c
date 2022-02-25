#include<stdio.h>
#include<stdlib.h>
typedef struct Queue {
    int *arr, front, rear;
    unsigned size;
}Q025;
Q025 *create(int size){
    Q025 *q025 = malloc(sizeof(Q025));
    q025->size = size;
    q025->front = q025->rear = -1;
    q025->arr = (int*)malloc(q025->size * sizeof(int));
    return q025;
}
Q025 *copy(Q025 *q025){
    Q025 *tq025 = malloc(sizeof(Q025));
    tq025->size = q025->size;
    tq025->front = tq025->rear = -1;
    tq025->arr = (int*)malloc(q025->size * sizeof(int));
    return tq025;
}

void enq025(Q025 *q025, int num){
    if(q025->front==-1 && q025->rear==-1)
        q025->front = 0;
    q025->arr[++q025->rear]=num;
}
int deq025(Q025 *q025){
    int val = q025->arr[q025->front++];
    if(q025->front>q025->rear)
        q025->front=q025->rear=-1;
    return val;
}
void display(Q025 *q025){
    if(q025->front==-1){
        printf("Empty\n");
        return;
    }
    for(int i=q025->front;i<=q025->rear;i++)
            printf("%d ",q025->arr[i]);
    printf("\n");
}

void push(Q025 *q025, int x){
    if(q025->rear == q025->size-1){
        printf("Stack overflow\n");
        return;
    }
    Q025 *tq025 = copy(q025);
    while(q025->front!=-1)
        enq025(tq025, deq025(q025));
    enq025(q025, x);
    while(tq025->front!=-1)
        enq025(q025, deq025(tq025));
}
int pop(Q025 *q025){
    if(q025->front==-1){
        printf("Stack underflow\n");
        return -1;
    }
    return deq025(q025);
}

void main(){
    int ch, num;
    printf("Enter size of the Stack : ");
    scanf("%d",&num);
    Q025 *q025=create(num);
    printf("1. Push\n2. Pop\n3. Display\n0. Exit\n");  
    while(1){  
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        if(ch==1){
            printf("Enter the value : ");
            scanf("%d",&num);
            push(q025, num);
        }
        else if (ch==2){
            int val=pop(q025);
            if(val!=-1)
                printf("Deq025d Element : %d\n",val);
        }
        else if (ch==3) display(q025);
        else if (ch==0) break;
        else printf("Please Enter valid choice\n");
    }    
}