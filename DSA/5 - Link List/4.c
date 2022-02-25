#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *prev, *next;
}*head,*tail;

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
    head=NULL; tail=NULL; int in;
    printf("Input (-1 to exit) : ");
    while(1){
        scanf("%d",&in);
        if(in==-1) break;
        struct node *new=malloc(sizeof(struct node));    
        new->data=in;
        new->prev=NULL; new->next=NULL;
        if(head==NULL){
            head=new; tail=head;
        }
        else{
           tail->next=new; 
           new->prev=tail;
           tail=new; 
        }
    }
    printf("I/P : ");
    display();
}

void insbeg(){
    struct node *new=malloc(sizeof(struct node));
    new->prev=NULL; new->next=NULL;
    printf("\nEnter Data : ");
    scanf("%d",&new->data);
    if(head==NULL){
        head=new; tail=head;
    }
    else{
        new->next=head;
        head->prev=new;
        head=new;
    }
    printf("O/P : ");
    display();
}
int main(){
    create();
    insbeg();
    return 0;
}