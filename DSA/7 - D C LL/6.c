#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *link;
}*head,*tail;

void display(){
    struct node *curr=head;
    int flag=0;
    if(!head){
        printf("Empty list\n");
        return;
    }
    while(curr && flag<=1){
        printf("%d ",curr->data);
        if(curr==tail){
            flag++;
            printf("\n");
        }
        curr=curr->link;
    }
}
void create(){
    head=tail=NULL; int in;
    printf("Input (-1 to exit) : ");
    while(1){
        scanf("%d",&in);
        if(in==-1) break;
        struct node *new=malloc(sizeof(struct node));    
        new->data=in; new->link=NULL;
        if(head==NULL){
            head=new; tail=head;
        }
        else{
           tail->link=new; tail=new; 
        }
    }
    printf("I/P : ");
    display();
}
void createCLL(){
    tail->link=head;
    printf("\nCirclular LL created\n");
    display();
}

int main(){
    create();
    createCLL();
    return 0;
}