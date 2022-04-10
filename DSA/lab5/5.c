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
    struct node *temp = l->head;
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
        Node *new = malloc(sizeof(Node));
        new->data = in; new->link = NULL;
        if(l->head == NULL)
            l->head = new;
        else
            l->tail->link = new;
        l->tail = new; l->count++;
        l->tail->link = l->head;
    }
    printf("I/P : ");
    display(l); return l;
}
 
List *delbeg(List *l){
    Node *temp = l->head;
    l->tail->link = temp->link;
    l->head = temp->link;
    return l;
}
List *delend(List *l){
    Node *prev, *temp = l->head;
    while(temp->link != l->head) {
        prev = temp;
        temp = temp->link;
    }
    prev->link = l->head;
    l->tail = prev;
    return l;
}
List *delete(List *l){
    Node *prev, *temp;
    printf("\nEnter Position : ");
    int pos; scanf("%d",&pos);
    if(pos<1 || pos>l->count) {
        printf("Index Not Found");
        return;
    }
    if(l->head == l->tail)
        l->head = NULL;
    else if(pos == 1)
        l = delbeg(l);
    else if(pos == l->count)
        l = delend(l);
    else{
        prev = l->head; temp = l->head->link;
        for(int i=2; i<l->count; i++) {
            if(pos == i) {
                prev->link = temp->link;
                break;
            }
            prev = temp;
            temp = temp->link;
        }
    }
    free(temp); l->count--;
    printf("O/P : ");
    display(l); return l;
}

int main(){
    List *l = malloc(sizeof(List));
    l->head = l->tail = NULL;
    l->count = 0; l = create(l);
    for(int i=0; i<6; i++){
        printf("\n\nTest Case %d : ",i+1);
        if (l->head == NULL){
            printf("Empty List\n");
            break;
        }
        l = delete(l);
    }
    return 0;
}