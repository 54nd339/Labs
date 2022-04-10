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

Node *reverse(Node *temp, int k){
    int n = 0; if(k == 1) return temp;
    Node *curr, *next, *prev;
    curr = temp, next = prev = NULL;
    while (curr!=NULL && n<k){
        next = curr->link;
        curr->link = prev;
        prev = curr; curr = next;
        n++;
    }
    if(next) temp->link = reverse(next,k);
    return prev;
}
int main(){
    List *l = malloc(sizeof(List));
    l->count = 0; l = create(l);
    if(l->head == NULL)
        printf("Empty List\n");
    else
        for(int i=0; i<3; i++){
            printf("\n\nTest Case %d :",i+1);
            printf("\nEnter k : ");
            int k; scanf("%d",&k);
            if(k<0 || k>l->count)
                printf("Index out of bound");
            else{
                l->head = reverse(l->head,k);
                printf("O/P : ");
                display(l);
            }
        }
    return 0;
}