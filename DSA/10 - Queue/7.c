#include <stdio.h>
#include <stdlib.h>
struct QNode {
	int data, priority;
    struct QNode *link;
};
struct QNode *newNode(int d, int p){
	struct QNode *temp = malloc(sizeof(struct QNode));
	temp->data = d; temp->priority = p;
	temp->link = NULL; return temp;
}

void enQueue(struct QNode **head, int d, int p){
	struct QNode *temp = newNode(d, p);
    if(*head == NULL) *head = temp;
    else if ((*head)->priority > p) {
        temp->link = (*head);
		(*head) = temp;
	}
	else {
        struct QNode *start = (*head);
        while (start->link != NULL &&
			start->link->priority < p) 
			start = start->link;
		
        temp->link = start->link;
		start->link = temp;
	}
}

void deQueue(struct QNode **head){
    if((*head) == NULL){
        printf("Queue Underflow\n"); return;
    }
	struct QNode *temp = *head;
	*head = (*head)->link;
    printf("Dequeued Element : %d\n",temp->data);
	free(temp);
}

int peek(struct QNode *head){
	return (head)->data;
}

void display(struct QNode *head){
    if (head==NULL){
        printf("Empty Q\n"); return;
    }
    struct QNode *temp = head;
    while(temp){
        printf("%d ",temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main(){
	struct QNode *q=NULL; int ch,in,p;
    printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Peek\n0. Exit\n");
    while(1){
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        if(ch==1){
            printf("Enter the value and priority : ");
            scanf("%d%d",&in,&p);
            enQueue(&q, in, p);
        }
        else if(ch==2) deQueue(&q);
        else if(ch==3) display(q);
        else if(ch==4) peek(q);
        else if(ch==0) break;
        else printf("Please Enter valid choice\n");
    }
    return 0;
}