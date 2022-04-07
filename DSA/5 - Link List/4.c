#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *prev, *next;
}*head, *tail;

struct node *newNode(int data){
    struct node *new = malloc(sizeof(struct node));    
    new->data = data; new->prev = new->next = NULL;
}
void display(){
    struct node *curr = head;
    if(!head){
        printf("Empty list\n");
        return;
    }
    while(curr){
        printf("%d ",curr->data);
        curr = curr->next;
    }
}
void create(){
    head = tail = NULL;
    printf("Input (-1 to exit) : ");
    while(1){
        int in; scanf("%d",&in);
        if(in == -1) break;
        struct node *new = newNode(in);
        if(head == NULL)
            head = new;
        else{
           tail->next = new; 
           new->prev = tail;
        }
        tail = new;
    }
    printf("I/P : ");
    display();
}
void insbeg(){
    printf("\nEnter Data : ");
    int in; scanf("%d",&in);
    struct node *new = newNode(in);
    if(head == NULL){
        head = new; tail=head;
    }
    else{
        new->next = head;
        head->prev = new;
        head = new;
    }
    printf("O/P : ");
    display();
}
int main(){
    create();
    insbeg();
    return 0;
}