#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *prev, *next;
}*head,*tail,*temp;
int in,count;

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
    while(temp){
        printf("%d ",temp->data);
        temp=temp->prev;
    }
    printf("\n");
}

void create(){
    head=tail=NULL; count=0;
    printf("Input (-1 to exit) : ");
    while(1){
        scanf("%d",&in);
        if(in==-1) break;
        struct node* new=malloc(sizeof(struct node));
        new->data=in; count++;
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

void rotate(){
    if(isNull()) return;
    temp=head; 
    printf("Enter no. : ");
    scanf("%d",&in); in%=count;
    if(in==0) return;
    for(int i=1;i<in;i++)
        temp=temp->next;
    head->prev=tail;
    tail->next=head;
    head=temp->next;
    tail=temp;
    head->prev=NULL;
    tail->next=NULL;
}

void main(){
    printf("\n1. Create a LL");
    printf("\n2. Display the LL");
    printf("\n3. Rotate the LL");
    printf("\n0. Exit\n");
    while (1){
        printf("\nEnter choice : ");
        scanf("%d",&in);
        if(in==1) create();
        else if(in==2) display();
        else if(in==3) rotate();
        else if(in==0) break;
        else printf("Wrong choice\n");
    }
}