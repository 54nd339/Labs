#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *link;
}Node;
typedef struct{
    int count;
    Node *head, *tail;
}List;

void display(List *l){
    Node *curr = l->head;
    if(l->head == NULL){
        printf("Empty list\n");
        return;
    }
    while(curr){
        printf("%d ",curr->data);
        curr = curr->link;
    }
}

List *create(List *l){
    printf("Input (-1 to exit) : ");
    while(1){
        int in; scanf("%d",&in);
        if(in == -1) break; l->count++;
        Node *new = malloc(sizeof(Node));    
        new->data = in; new->link = NULL;
        if(l->head == NULL)
            l->head = new;
        else
           l->tail->link = new;
        l->tail = new;
    }
    printf("I/P : ");
    display(l); return l;
}

List *rotate(List *l){
    printf("\nEnter k : ");
    int k; scanf("%d",&k);
    k %= l->count;
    Node *temp = l->head;
    for(int i=1; i<k; i++)
        temp = temp->link;
    Node *next = temp->link;
    temp->link = NULL;
    l->tail->link = l->head;
    l->head = next;
    printf("O/P : ");
    display(l); return l;
}

int main(){
    List *l = malloc(sizeof(List));
    l->head = l->tail = NULL;
    l->count = 0; l = create(l);
    if (l->head == NULL) printf("Empty list\n");
    else l = rotate(l);
    return 0;
}