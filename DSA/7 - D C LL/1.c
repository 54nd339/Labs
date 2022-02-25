#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *prev, *next;
}*head,*tail;

void display(){
    if(!head){
        printf("Empty List\n");
        return;
    }
    
    struct node *temp=head;
    printf("List (from start) : ");
    while(temp){
        printf("%d ",temp->data);
        temp=temp->next;
    }printf("\n");

    temp=tail;
    printf("List (from end) : ");
    while(temp){
        printf("%d ",temp->data);
        temp=temp->prev;
    }printf("\n");
}

void create(){
    head=NULL; tail=NULL; int n,in;
    printf("Enter No. of nodes : ");
    scanf("%d",&n); if(n>0)
    printf("Enter  Data : ");
    for(int i=0;i<n;i++){
        struct node* new=malloc(sizeof(struct node));
        scanf("%d",&new->data);
        new->prev=NULL; new->next=NULL;
        if(!head){
            head=new; tail=new;
        }
        else{
            tail->next=new;
            new->prev=tail;
            tail=new;
        }
    }
}

void main(){
    int ch;
    printf("1. Create a LL\n");
    printf("2. Display the LL\n");
     printf("0. Exit\n");
    while (1){
        printf("\nEnter choice : ");
        scanf("%d",&ch);
        if(ch==1) create();
        else if(ch==2) display();
        else if(ch==0) break;
        else printf("\n Wrong choice");
    }
}