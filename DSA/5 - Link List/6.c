#include <stdio.h>  
#include <stdlib.h>    
struct node{  
    int data;  
    struct node *link;  
}*head, *tail;  
int count = 0;

struct node *newNode(int data){
    struct node *new = malloc(sizeof(struct node));    
    new->data = data; new->link = NULL;
}
void display(){  
    struct node *temp = head;
    if(head == NULL)
        printf("Empty List");
    else
        do{
            printf("%d ",temp->data);  
            temp = temp->link;  
        }while(temp != head);
}
void create(){
    printf("Input (-1 to exit) : ");
    while(1){
        int in; scanf("%d",&in);
        if(in == -1) break;
        struct node *new = newNode(in);
        if(head == NULL)
            head = new;
        else
            tail->link = new;
        tail = new;
        tail->link = head; count++;
    }
    printf("I/P : ");
    display();
}

void insbeg(){
    printf("\nEnter Data : ");
    int in; scanf("%d",&in); 
    struct node *temp = newNode(in);  
    if(head == NULL){
        head = temp; tail = temp;
    }
    else{
        temp->link = head;
        head = temp;
    }
    tail->link = head;
    printf("O/P : ");
    display();
}
int main(){
    create();
    insbeg();
    return 0;
}