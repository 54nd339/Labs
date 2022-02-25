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
    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=head);
    printf("\n");
    
    temp=tail;
    printf("List (from end) : ");
    do{
        printf("%d ",temp->data);
        temp=temp->prev;
    }while(temp!=tail);
    printf("\n");
}

void create(){
    head=tail=NULL; int n,in;
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
        tail->next=head; head->prev=tail;
    }
}

void main(){
    int ch;
    printf("\n1. Create a LL");
    printf("\n2. Display the LL");
    printf("\n0. Exit\n");
    while (1){
        printf("\nEnter choice : ");
        scanf("%d",&ch);
        if(ch==1) create();
        else if(ch==2) display();
        else if(ch==0) break;
        else printf("\n Wrong choice");
    }
}