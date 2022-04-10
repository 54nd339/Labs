#include <stdio.h>
#include <stdlib.h>
typedef struct QNode {
	int data, priority;
    struct QNode *link;
}Q;
Q *newNode(int d, int p){
	Q *temp = malloc(sizeof(Q));
	temp->data = d; temp->priority = p;
	temp->link = NULL; return temp;
}

void enQueue(Q **head, int d, int p){
	Q *temp = newNode(d, p);
    if(*head == NULL) *head = temp;
    else if ((*head)->priority > p) {
        temp->link = (*head);
		(*head) = temp;
	}
	else {
        Q *start = (*head);
        while (start->link != NULL &&
			start->link->priority < p) 
			start = start->link;
		
        temp->link = start->link;
		start->link = temp;
	}
}

void deQueue(Q **head){
    if((*head) == NULL){
        printf("Queue Underflow\n"); return;
    }
	Q *temp = *head;
	*head = (*head)->link;
    printf("Dequeued Element : %d\n",temp->data);
	free(temp);
}

int peek(Q *head){
	return (head)->data;
}

void display(Q *head){
    if (head == NULL){
        printf("Empty Q\n"); return;
    }
    Q *temp = head;
    while(temp){
        printf("%d ",temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main(){
	Q *q = NULL;
    printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Peek\n0. Exit\n");
    while(1){
        printf("\nEnter your choice : ");
        int ch; scanf("%d",&ch);
        if(ch == 1){
            printf("Enter the value and priority : ");
            int in, p; scanf("%d%d",&in,&p);
            enQueue(&q, in, p);
        }
        else if(ch == 2) deQueue(&q);
        else if(ch == 3) display(q);
        else if(ch == 4) peek(q);
        else if(ch == 0) break;
        else printf("Please Enter valid choice\n");
    }
    return 0;
}