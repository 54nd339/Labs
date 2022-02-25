#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *prev, *next;
}*head,*tail,*tmph,*tmpt;
int in,count=0;

int isNull(){
    if(!head){
        printf("Empty List\n");
        return 1;
    }
    return 0;
}
void display(){
    if(isNull()) return;
    tmph=head;
    printf("List (from start) : ");
    while(tmph){
        printf("%d ",tmph->data);
        tmph=tmph->next;
    }
    printf("\n");
    tmpt=tail;
    printf("List (from end) : ");
    while(tmpt){
        printf("%d ",tmpt->data);
        tmpt=tmpt->prev;
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

void mid(){
    if(isNull()) return;
    tmph=head; tmpt=tail;
    while(tmph){
        if(count%2==1 && tmph->data==tmpt->data){
            printf("Middle Element : %d\n",tmph->data); break;
        }
        if(count%2==0 && tmph->next==tmpt){
            printf("Middle Elements : %d %d\n",tmph->data,tmpt->data); break;
        }
        tmph=tmph->next;
        tmpt=tmpt->prev;
    }
}

void main(){
    printf("\n1. Create a LL");
    printf("\n2. Display the LL");
    printf("\n3. Mid of the LL");
    printf("\n0. Exit\n");
    while (1){
        printf("\nEnter choice : ");
        scanf("%d",&in);
        if(in==1) create();
        else if(in==2) display();
        else if(in==3) mid();
        else if(in==0) break;
        else printf("Wrong choice\n");
    }
}