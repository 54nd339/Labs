#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *link;
}Node;
typedef struct{
    int count;
    Node *head;
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
    Node *temp = l->head = NULL;
    printf("Input (-1 to exit) : ");
    while(1){
        int in; scanf("%d",&in);
        if(in == -1) break; l->count++;
        Node *new = malloc(sizeof(Node));    
        new->data = in; new->link = NULL;
        if(l->head == NULL)
            l->head = new;
        else
           temp->link = new;
        temp = new;
    }
    printf("I/P : ");
    display(l); return l;
}

List *swap(List *l){
    printf("\nEnter k : ");
    int k; scanf("%d",&k);
    if(k<1 || k>l->count){
        printf("Index out of bound");
        return l;
    }
    if(2*k-1 == l->count) return l;
    Node *k1 = l->head, *k1p = NULL;
    for(int i=1; i<k; i++){
        k1p = k1; k1 = k1->link;
    }
    Node *k2 = l->head, *k2p = NULL;
    for(int i=1; i<l->count-k+1; i++){
        k2p = k2; k2 = k2->link;
    }
    if(k1p) k1p->link = k2;
    if(k2p) k2p->link = k1;
    Node *temp = k1->link;
    k1->link = k2->link; k2->link = temp;
    if(k == 1) l->head = k2;
    if(k == l->count) l->head = k1;
    printf("O/P : ");
    display(l); return l;
}
int main(){
    List *l = malloc(sizeof(List));
    l->count = 0; l = create(l);
    if(l->head == NULL)
        printf("Empty List\n");
    else
        for(int i=0; i<4; i++){
            printf("\n\nTest Case %d :",i+1);
            l = swap(l);
        }
    return 0;
}