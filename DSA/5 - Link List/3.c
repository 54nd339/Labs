#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *link;
}*head, *tail;
int count=0;

void display(){
    struct node *curr = head;
    if(!head){
        printf("Empty list\n");
        return;
    }
    while(curr){
        printf("%d ",curr->data);
        curr = curr->link;
    }
}

void create(){
    printf("Input (-1 to exit) : ");
    while(1){
        int in; scanf("%d",&in);
        if(in == -1) break; count++;
        struct node *new = malloc(sizeof(struct node));    
        new->data = in; new->link = NULL;
        if(head == NULL)
            head = new;
        else
           tail->link = new;
        tail = new;
    }
    printf("I/P : ");
    display();
}

void rotate(){
    printf("\nEnter k : ");
    int k; scanf("%d",&k);
    k %= count;
    struct node *temp = head;
    for(int i=1; i<k; i++)
        temp = temp->link;
    struct node *next=temp->link;
    temp->link = NULL;
    tail->link = head;
    head = next;
    printf("O/P : ");
    display();
}

int main(){
    create();
    (!head) ? printf("Empty list\n") : rotate();
    return 0;
}