#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *prev, *next;
}*head,*tail;

int count=0;
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
        if(in==-1) break; count++;
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

int isPalin(){
    struct node *tmph=head, *tmpt=tail;
    for(int i=1;i<=count/2;i++){
        if(tmph->data!=tmpt->data) return 0;
        tmph=tmph->next;
        tmpt=tmpt->prev;
    }
    return 1;
}
int main(){
    for(int i=0;i<3;i++){
        printf("\nTest Case %d :\n",i+1);
        create();
        if(!head)
            printf("Empty list\n");
        else
            printf(isPalin()?"\nPalindrome\n":"\nNot Palindrome\n");
    }
    return 0;
}