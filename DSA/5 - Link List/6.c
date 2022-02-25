#include <stdio.h>  
#include <stdlib.h>    
struct node{  
    int data;  
    struct node *link;  
}*head, *tail, *temp;  
int count=0;

void display(){  
    temp=head;
    if(head==NULL)
        printf("Empty List");
    else
        do{
            printf("%d ",temp->data);  
            temp=temp->link;  
        }while(temp!=head);
}
void create(){
    struct node *new; int in;
    printf("Input (-1 to exit) : ");
    while(1){
        scanf("%d",&in);
        if(in==-1) break;
        new=malloc(sizeof(struct node));
        new->data=in;
        if(head==NULL){
            head=new; tail=new;
        }
        else{
            tail->link=new;
            tail=new;
        }
        tail->link=head; count++;
    }
    printf("I/P : ");
    display();
}

void insbeg(){
    temp=malloc(sizeof(struct node));  
    printf("\nEnter Data : ");
    scanf("%d",&temp->data); 
    if(head==NULL){
        head=temp; tail=temp;
    }
    else{
        temp->link=head;
        head=temp;
    }
    tail->link=head;
    printf("O/P : ");
    display();
}
int main(){
    create();
    insbeg();
    return 0;
}