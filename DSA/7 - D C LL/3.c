#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *prev, *next;
}*head,*tail;
int count=0;

int isnull(){
    if(!head){
        printf("Empty list\n");
        return 1;
    }
    return 0;
}
void disbeg(){
    struct node *temp=head;
    if(isnull()) return;
    printf("List (from start) : ");
    while(temp){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void disend(){
    struct node *temp=tail;
    if(isnull()) return;
    printf("List (from end) : ");
    while(temp){
        printf("%d ",temp->data);
        temp=temp->prev;
    }
    printf("\n");
}

int indch(int pos){
    if(pos<0 || pos>count){
        printf("Index out of bound\n");
        return 1;
    }
    return 0;
}
void insert(int pos, int info){
    if(indch(pos)) return;
    struct node *new=malloc(sizeof(struct node));
    new->prev=NULL; new->next=NULL;
    new->data=info;
    //printf("%d %d\n",pos,count);
    if(!head){
        head=new; tail=head;
    }
    else if(pos==0){
        new->next=head;
        head->prev=new;
        head=new;
    }
    else if(pos==count){
        tail->next=new;
        new->prev=tail;
        tail=new;
    }
    else{
        struct node *temp=head;
        for(int i=1;i<=pos;i++)
            temp=temp->next;
        new->next=temp;
        new->prev=temp->prev;
        temp->prev->next=new;
        temp->prev=new;
    }
    count++;
}
void delete(int pos){
    if(isnull()) return;
    if(indch(pos+1)) return;
    struct node *temp;
    if(pos==0){
        temp=head;
        head=head->next;
        head->prev=NULL;
    }
    else if(pos==count-1){
        temp=tail;
        tail=temp->prev;
        tail->next=NULL;
    }
    else{
        temp=head; 
        for(int i=1;i<=pos;i++)
            temp=temp->next;
        temp->next->prev=temp->prev;
        temp->prev->next=temp->next;
    }
    printf("Element deleted : %d\n",temp->data);
    free(temp); count--;
}

void create(){
    head=tail=NULL; int info;
    printf("Input (-1 to exit) : ");
    while(1){
        scanf("%d",&info);
        if(info==-1) break;
        insert(count,info);
    }
}
int search(int key){
    if(isnull()) return -1;
    struct node *temp=head; int i=0;
    while (temp){
        if (temp->data==key){
            printf("Value found in %d position\n",i+1);
            return i;
        }
        temp=temp->next;
        i++;
    }
    printf("%d Not Found\n",key);
    return -1;
}
void delkey(int key){
    int t=search(key);
    if(t==-1) return;
    delete(t);
}

void main(){
    int ch,pos,info,key; create();
    printf("\n1. Traverse Forward");
    printf("\n2. Traverse Backward");
    printf("\n3. Check if List is empty");
    printf("\n4. Insert a node");
    printf("\n5. Delete a node");
    printf("\n6. Delete a key");
    printf("\n7. Count total nodes");
    printf("\n8. Search a node");
    printf("\n0. Exit\n");
    while (1){
        printf("\nEnter choice : ");
        scanf("%d",&ch);
        if(ch==1) disbeg();
        else if(ch==2) disend();
        else if(ch==3) printf((isnull())?"":"Not Empty\n");
        else if(ch==4){
            printf("Enter index & info : ");
            scanf("%d%d",&pos,&info);
            insert(pos,info);
        }
        else if(ch==5){
            printf("Enter index to be deleted : ");
            scanf("%d",&pos); delete(pos);
        }
        else if(ch==6){
            printf("Enter key to be deleted : ");
            scanf("%d",&key); delkey(key);
        }
        else if(ch==7) printf("No. of nodes : %d\n", count);
        else if(ch==8){
            printf("Enter key to search : ");
            scanf("%d",&key); search(key);
        }
        else if(ch==0) break;
        else printf("Wrong choice\n");
    }
}