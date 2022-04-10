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

int isNull(List *l){
    if(!(l->head)){
        printf("Empty List\n");
        return 1;
    } return 0;
}
void display(List *l){
    if(isNull(l)) return;
    Node *temp = l->head;
    printf("List (from start) : ");
    while(temp){
        printf("%d ",temp->data);
        temp = temp->next;
    } printf("\n");
    temp = l->tail;
    printf("List (from end) : ");
    while(temp){
        printf("%d ",temp->data);
        temp = temp->prev;
    } printf("\n");
}

List *create(List *l){
    printf("Input (-1 to exit) : ");
    while(1){
        int in; scanf("%d",&in);
        if(in == -1) break;
        Node* new=malloc(sizeof(Node));
        new->data = in; l->count++;
        new->prev = new->next = NULL;
        if(!(l->head))
            l->head = new;
        else{
            l->tail->next = new;
            new->prev = l->tail;
        } l->tail = new;
    } return l;
}
List *rotate(List *l){
    if(isNull(l)) return l;
    Node *temp = l->head; 
    printf("Enter no. : ");
    int in; scanf("%d",&in);
    in %= l->count;
    if(in == 0) return l;
    for(int i=1; i<in; i++)
        temp = temp->next;
    l->head->prev = l->tail;
    l->tail->next = l->head;
    l->head = temp->next;
    l->tail = temp;
    l->head->prev = NULL;
    l->tail->next = NULL;
    return l;
}

void main(){
    List *l = malloc(sizeof(List));
    l->head = l->tail = NULL;
    l->count = 0;
    printf("\n1. Create a LL");
    printf("\n2. Display the LL");
    printf("\n3. Rotate the LL");
    printf("\n0. Exit\n");
    while (1){
        printf("\nEnter choice : ");
        int in; scanf("%d",&in);
        if(in == 1) l = create(l);
        else if(in == 2) display(l);
        else if(in == 3) l = rotate(l);
        else if(in == 0) break;
        else printf("Wrong choice\n");
    }
}