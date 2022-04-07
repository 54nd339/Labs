#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *prev, *next;
}*head, *tail;
void display(){
    struct node *curr=head;
    if(!head){
        printf("Empty list\n");
        return;
    }
    while(curr){
        printf("%d ",curr->data);
        curr=curr->next;
    }
}
void create(){
    head = tail = NULL;
    printf("Input (-1 to exit) : ");
    while(1){
        int in; scanf("%d",&in);
        if(in == -1) break;
        struct node *new = malloc(sizeof(struct node));    
        new->data = in;
        new->prev = new->next = NULL;
        if(head == NULL)
            head = new;
        else{
           tail->next = new; 
           new->prev = tail;
        }
        tail = new;
    }
    printf("I/P : ");
    display();
}
void delNode(struct node *del){
    if(head==NULL || del==NULL) return;
    if(head == del) head = del->next;
    if(del->next) del->next->prev = del->prev;
    if(del->prev) del->prev->next = del->next;
    free(del);
}
void remDup(){
    struct node *temp = head;
    while (temp->next) {
        if (temp->data == temp->next->data)
            delNode(temp->next);
        else temp = temp->next;
    }
    printf("\nO/P : ");
    display();
}
int main(){
    create();
    (!head)?printf("Empty list\n"):remDup();
    return 0;
}