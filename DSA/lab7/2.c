#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *prev, *next;
}Node;
typedef struct{
    int count;
    Node *head, *tail;
}List;

void display(List *l){
    if(!(l->head)){
        printf("Empty List\n");
        return;
    }
    
    Node *temp = l->head;
    printf("List (from start) : ");
    while(temp){
        printf("%d ",temp->data);
        temp = temp->next;
    }printf("\n");

    temp = l->tail;
    printf("List (from end) : ");
    while(temp){
        printf("%d ",temp->data);
        temp = temp->prev;
    }printf("\n");
}

void create(List **l){
    printf("Input (-1 to exit) : ");
    while(1){
        int in; scanf("%d",&in);
        if(in == -1) break;
        Node *new = malloc(sizeof(Node));
        new->data = in; (*l)->count++;
        new->prev = new->next = NULL;
        if(!(*l)->head)
            (*l)->head = new;
        else{
            (*l)->tail->next = new;
            new->prev = (*l)->tail;
        }
        (*l)->tail = new;
    }
}

void reverse(List *l){
    if(l->count == 0) return;
    int n = l->count, temp;
    Node *tmph = l->head, *tmpt = l->tail;
    for(int i=0; i<n/2; i++){
        temp = tmph->data;
        tmph->data = tmpt->data;
        tmpt->data = temp;
        tmph = tmph->next;
        tmpt = tmpt->prev;
    }
}

void main(){
    List *l = malloc(sizeof(List));
    l->head = l->tail = NULL;
    l->count = 0;
    printf("\n1. Create a LL");
    printf("\n2. Display the LL");
    printf("\n3. Reverse the LL");
    printf("\n0. Exit\n");
    while (1){
        printf("\nEnter choice : ");
        int in; scanf("%d",&in);
        if(in == 1) create(&l);
        else if(in == 2) display(l);
        else if(in == 3) reverse(l);
        else if(in == 0) break;
        else printf("Wrong choice\n");
    }
}