#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *prev, *next;
}Node;

Node *newNode(int data){
    Node *new = malloc(sizeof(Node));    
    new->data = data;
    new->prev = new->next = NULL;
}
void display(Node *head){
    Node *curr = head;
    if(!head){
        printf("Empty list\n");
        return;
    }
    while(curr){
        printf("%d ",curr->data);
        curr = curr->next;
    }
}
Node *create(Node *head){
    Node *temp = head = NULL;
    printf("Input (-1 to exit) : ");
    while(1){
        int in; scanf("%d",&in);
        if(in == -1) break;
        Node *new = newNode(in);
        if(head == NULL)
            head = new;
        else{
           temp->next = new; 
           new->prev = temp;
        }
        temp = new;
    }
    printf("I/P : ");
    display(head); return head;
}
Node *insbeg(Node *head){
    printf("\nEnter Data : ");
    int in; scanf("%d",&in);
    Node *new = newNode(in);
    if(head == NULL)
        head = new;
    else{
        new->next = head;
        head->prev = new;
        head = new;
    }
    printf("O/P : ");
    display(head); return head;
}
int main(){
    Node *l = malloc(sizeof(Node));
    l = NULL; l = create(l);
    l = insbeg(l);
    return 0;
}