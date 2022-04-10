#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *link;
}Node;
typedef struct{
    Node *head, *tail;
}List;

void display(List *l){
    Node *curr = l->head;
    int flag = 0;
    if(!(l->head)){
        printf("Empty list\n");
        return;
    }
    while(curr && flag<=1){
        printf("%d ",curr->data);
        if(curr == l->tail){
            flag++;
            printf("\n");
        }
        curr = curr->link;
    }
}
List *create(List *l){
    printf("Input (-1 to exit) : ");
    while(1){
        int in; scanf("%d",&in);
        if(in == -1) break;
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
List *createCLL(List *l){
    l->tail->link = l->head;
    printf("\nCirclular LL created\n");
    display(l); return l;
}

int main(){
    List *l = malloc(sizeof(List));
    l->head = l->tail = NULL;
    l = create(l);
    l = createCLL(l);
    return 0;
}