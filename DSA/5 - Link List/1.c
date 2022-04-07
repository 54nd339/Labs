#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *link;
}*head, *tail;
int count = 0;

void display(){
    struct node *curr = head;
    if(!head){
        printf("Empty list\n");
        return;
    }
    while(curr){
        printf("%d ",curr->data);
        curr = curr->link;
    }
}
void create(){
    printf("Input (-1 to exit) : ");
    while(1){
        int in; scanf("%d",&in);
        if(in==-1) break; count++;
        struct node *new = malloc(sizeof(struct node));    
        new->data = in; new->link = NULL;
        if(head == NULL)
            head = new;
        else
           tail->link=new;
        tail=new;
    }
    printf("I/P : ");
    display();
}

void swap(){
    printf("\nEnter k : ");
    int k; scanf("%d",&k);
    if(k<1 || k>count){
        printf("Index out of bound");
        return;
    }
    if(2*k-1==count) return;
    struct node *k1 = head, *k1p = NULL;
    for(int i=1; i<k; i++){
        k1p = k1; k1 = k1->link;
    }
    struct node *k2 = head, *k2p = NULL;
    for(int i=1; i<count-k+1; i++){
        k2p = k2; k2 = k2->link;
    }
    if(k1p) k1p->link = k2;
    if(k2p) k2p->link = k1;
    struct node *temp = k1->link;
    k1->link = k2->link; k2->link = temp;
    if(k == 1) head = k2;
    if(k == count) head = k1;
    printf("O/P : ");
    display();
}
int main(){
    create();
    if(!head) printf("Empty List\n");
    else
        for(int i=0; i<4; i++){
            printf("\n\nTest Case %d :",i+1);
            swap();
        }
    return 0;
}