#include <stdio.h>  
#include <stdlib.h>    
typedef struct node{  
    int data;  
    struct node *link;  
}Node;
typedef struct list{
    Node *head, *tail;
}List;
void newNode(List **l, int data){
    Node *new = malloc(sizeof(Node));
    new->data = data; new->link = NULL;
    if((*l)->head == NULL)
        (*l)->head = new;
    else
        (*l)->tail->link = new;
    (*l)->tail = new;
    (*l)->tail->link = (*l)->head;
}
void display(Node *ptr){  
    Node *temp = ptr;
    if(ptr == NULL)
        printf("Empty List");
    else
        do{
            printf("%d ",temp->data);  
            temp = temp->link;  
        }while(temp != ptr);
}
void create(List **l){  
    *l = malloc(sizeof(List));
    (*l)->head = (*l)->tail = NULL; 
    printf("\nInput for 4 nos. : ");
    for(int i=0, in; i<4; i++){
        scanf("%d",&in);
        newNode(l, in);
    }
    printf("I/P : ");
    display((*l)->head);
}

List *prod(Node *ptr1, Node *ptr2){
    Node *t1 = ptr1, *t2 = ptr2;
    List *out = malloc(sizeof(List));
    out->head = out->tail = NULL; 
    do{
        newNode(&out, t1->data*t2->data);
        t1 = t1->link; t2 = t2->link;
    }while(t1 != ptr1);
    printf("\n\nProd : ");
    display(out->head);
    return out;
}
void rotate(List *out){
    Node *temp = out->head;
    printf("\nEnter roll : ");
    int k; scanf("%d",&k); k%=10;
    for(int i=1; i<k; i++)
        temp = temp->link;
    out->head = temp->link;
    out->tail = temp;
    printf("\nO/P : ");
    display(out->head);
}

int main(){
    List *l1, *l2, *l3, *out;
    create(&l1);
    create(&l2);
    create(&l3);
    out = prod(l1->head, l3->head);
    out->tail->link = l2->head;
    l2->tail->link = out->head;
    printf("\nMerge : ");
    display(out->head);
    rotate(out);
    return 0;
}