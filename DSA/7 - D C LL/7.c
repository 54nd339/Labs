#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *prev, *next;
}*head,*tail,*temp;

int isNull(){
    if(!head){
        printf("Empty List\n");
        return 1;
    }
    return 0;
}
void display(){
    if(isNull()) return;
    temp=head;
    printf("List (from start) : ");
    while(temp){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
    temp=tail;
    printf("List (from end) : ");
    if(!temp->prev){
        printf("prev nodes : NULL\n");
        return;
    }
    while(temp){
        printf("%d ",temp->data);
        temp=temp->prev;
    }
    printf("\n");
}

void create(){
    head=tail=NULL; int in;
    printf("Input (-1 to exit) : ");
    while(1){
        scanf("%d",&in);
        if(in==-1) break;
        struct node *new=malloc(sizeof(struct node));    
        new->data=in; new->next=NULL; new->prev=NULL;
        if(head==NULL){
            head=new; tail=head;
        }
        else{
           tail->next=new; tail=new; 
        }
    }
    printf("I/P : ");
    display();
}
void createDLL(){
    if(isNull()) return;
    temp=head; temp->prev=NULL;
    while(temp->next){
        temp->next->prev=temp;
        temp=temp->next;
    }
    printf("\nDoubly LL created\n");
    display();
}

void main(){
    create();
    createDLL();
}