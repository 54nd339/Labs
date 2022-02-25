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
    head=tail=NULL; int in;
    printf("Input (-1 to exit) : ");
    while(1){
        scanf("%d",&in);
        if(in==-1) break;
        struct node* new=malloc(sizeof(struct node));
        new->data=in;
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

void remdup(){
    struct node *t1 = head;
    while (t1){
        struct node *t2 = t1;
        while (t2->next){
            if (t1->data==t2->next->data) {
                struct node *dup = t2->next;
                t2->next = dup->next;
                if(dup->next)
                dup->next->prev = t2;
                free(dup);
            }
            else t2 = t2->next;
        }
        t1 = t1->next;
    }
}

void main(){
    printf("\n1. Create a LL");
    printf("\n2. Display the LL");
    printf("\n3. Remove Duplicates");
    printf("\n0. Exit\n");
    while (1){ int in;
        printf("\nEnter choice : ");
        scanf("%d",&in);
        if(in==1) create();
        else if(in==2) display();
        else if(in==3) remdup();
        else if(in==0) break;
        else printf("Wrong choice\n");
    }
}