#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *prev, *next;
}Node;
typedef struct{
    Node *head, *tail;
}List;

int isNull(List *l){
    if(!(l->head)){
        printf("Empty List\n");
        return 1;
    }
    return 0;
}
void display(List *l){
    if(isNull(l)) return;
    Node *temp = l->head;
    printf("List (from start) : ");
    while(temp){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
    temp = l->tail;
    printf("List (from end) : ");
    if(!temp->prev){
        printf("prev nodes : NULL\n");
        return;
    }
    while(temp){
        printf("%d ",temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

List *create(List *l){
    printf("Input (-1 to exit) : ");
    while(1){
        int in; scanf("%d",&in);
        if(in == -1) break;
        Node *new = malloc(sizeof(Node));    
        new->data = in;
        new->next = new->prev = NULL;
        if(l->head == NULL)
            l->head = new;
        else
           l->tail->next = new;
           l->tail = new; 
    }
    printf("I/P : ");
    display(l); return l;
}
List *createDLL(List *l) {
    if(isNull(l)) return l;
    Node *temp = l->head;
    while(temp->next){
        temp->next->prev = temp;
        temp = temp->next;
    }
    printf("\nDoubly LL created\n");
    display(l); return l;
}

int main(){
    List *l = malloc(sizeof(List));
    l->head = l->tail = NULL;
    l = create(l);
    l = createDLL(l);
    return 0;
}