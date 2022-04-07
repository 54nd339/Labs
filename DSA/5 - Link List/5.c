#include <stdio.h>  
#include <stdlib.h>    
struct node{  
    int data;  
    struct node *link;  
}*head, *tail;  
int count = 0;

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
        struct node *new = malloc(sizeof(struct node));
        new->data = in; new->link = NULL;
        if(head == NULL)
            head = new;
        else
            tail->link=new;
        tail = new;
        tail->link = head; count++;
    }
    printf("I/P : ");
    display();
}
 
void delbeg(){
    struct node *temp = head;
    tail->link = temp->link;
    head = temp->link;
}
void delend(){
    struct node *prev, *temp = head;
    while(temp->link != head) {
        prev = temp;
        temp = temp->link;
    }
    prev->link = head;
    tail = prev;
}
void delete(){
    struct node *prev, *temp;
    printf("\nEnter Position : ");
    int pos; scanf("%d",&pos);
    if(pos<1 || pos>count) {
        printf("Index Not Found");
        return;
    }
    if(head == tail) head = NULL;
    else if(pos == 1) delbeg();
    else if(pos == count) delend();
    else{
        prev = head; temp = head->link;
        for(int i=2; i<count; i++) {
            if(pos == i) {
                prev->link = temp->link;
                break;
            }
            prev = temp;
            temp = temp->link;
        }
    }
    free(temp); count--;
    printf("O/P : ");
    display();
}

int main(){
    create();
    for(int i=0; i<6; i++){
        printf("\n\nTest Case %d : ",i+1);
        if (!head){
            printf("Empty List\n");
            break;
        }
        delete();
    }
    return 0;
}