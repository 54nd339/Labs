#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *prev, *next;
}Node;
typedef struct{
    Node *head, *tail;
}List;
void display(List *l){
    if(!(l->head)){
        printf("Empty List\n");
        return;
    }

    Node *temp = l->head;
    printf("List (from start) : ");
    do{
        printf("%d ",temp->data);
        temp = temp->next;
    }while(temp != l->head);
    printf("\n");
    
    temp = l->tail;
    printf("List (from end) : ");
    do{
        printf("%d ",temp->data);
        temp = temp->prev;
    }while(temp != l->tail);
    printf("\n");
}
void create(List **l){
    printf("Input (-1 to exit) : ");
    while(1){
        int in; scanf("%d",&in);
        if(in == -1) break;
        Node *new = malloc(sizeof(Node));
        new->data = in;
        new->prev = new->next = NULL;
        if(!(*l)->head)
            (*l)->head = new;
        else{
            (*l)->tail->next = new;
            new->prev = (*l)->tail;
        }
        (*l)->tail = new;
        (*l)->tail->next = (*l)->head;
        (*l)->head->prev = (*l)->tail;
    }
}
void main(){
    List *l = malloc(sizeof(List));
    l->head = l->tail = NULL;
    printf("\n1. Create a LL");
    printf("\n2. Display the LL");
    printf("\n0. Exit\n");
    while (1){
        printf("\nEnter choice : ");
        int ch; scanf("%d",&ch);
        if(ch == 1) create(&l);
        else if(ch == 2) display(l);
        else if(ch == 0) break;
        else printf("\n Wrong choice");
    }
}