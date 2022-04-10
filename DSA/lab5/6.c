#include <stdio.h>  
#include <stdlib.h>    
typedef struct node{  
    int data;  
    struct node *link;  
}Node;
typedef struct{
    Node *head, *tail;  
    int count;
}List;

Node *newNode(int data){
    Node *new = malloc(sizeof(Node));    
    new->data = data; new->link = NULL;
}
void display(List *l){  
    Node *temp = l->head;
    if(l->head == NULL)
        printf("Empty List");
    else
        do{
            printf("%d ",temp->data);  
            temp = temp->link;  
        }while(temp != l->head);
}
List *create(List *l){
    printf("Input (-1 to exit) : ");
    while(1){
        int in; scanf("%d",&in);
        if(in == -1) break;
        Node *new = newNode(in);
        if(l->head == NULL)
            l->head = new;
        else
            l->tail->link = new;
        l->tail = new;
        l->tail->link = l->head; l->count++;
    }
    printf("I/P : ");
    display(l); return l;
}

List *insbeg(List *l){
    printf("\nEnter Data : ");
    int in; scanf("%d",&in); 
    Node *temp = newNode(in);  
    if(l->head == NULL){
        l->head = l->tail = temp;
    }
    else{
        temp->link = l->head;
        l->head = temp;
    }
    l->tail->link = l->head;
    printf("O/P : ");
    display(l); return l;
}
int main(){
    List *l = malloc(sizeof(List));
    l->head = l->tail = NULL; l->count = 0;
    l = create(l); l = insbeg(l);
    return 0;
}