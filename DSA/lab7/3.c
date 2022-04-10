#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *prev, *next;
}Node;
typedef struct{
    int count;
    Node *head, *tail;
}List;

int isnull(List *l){
    if(!(l->head)){
        printf("Empty list\n");
        return 1;
    }
    return 0;
}
void disbeg(List *l){
    Node *temp = l->head;
    if(isnull(l)) return;
    printf("List (from start) : ");
    while(temp){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void disend(List *l){
    Node *temp = l->tail;
    if(isnull(l)) return;
    printf("List (from end) : ");
    while(temp){
        printf("%d ",temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int indch(List *l, int pos){
    if(pos<0 || pos>l->count){
        printf("Index out of bound\n");
        return 1;
    }
    return 0;
}
List *insert(List *l, int pos, int info){
    if(indch(l, pos)) return l;
    Node *new = malloc(sizeof(Node));
    new->prev = new->next = NULL;
    new->data = info;
    //printf("%d %d\n",pos,count);
    if(!(l->head)){
        l->head = new;
        l->tail = l->head;
    }
    else if(pos == 0){
        new->next = l->head;
        l->head->prev = new;
        l->head=new;
    }
    else if(pos == l->count){
        l->tail->next = new;
        new->prev = l->tail;
        l->tail = new;
    }
    else{
        Node *temp = l->head;
        for(int i=1; i<=pos; i++)
            temp = temp->next;
        new->next = temp;
        new->prev = temp->prev;
        temp->prev->next = new;
        temp->prev = new;
    }
    l->count++; return l;
}
List *delete(List *l, int pos){
    if(isnull(l)) return l;
    if(indch(l, pos+1)) return l;
    Node *temp;
    if(pos == 0){
        temp = l->head;
        l->head = l->head->next;
        l->head->prev = NULL;
    }
    else if(pos == l->count-1){
        temp = l->tail;
        l->tail = temp->prev;
        l->tail->next = NULL;
    }
    else{
        temp = l->head; 
        for(int i=1; i<=pos; i++)
            temp = temp->next;
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
    }
    printf("Element deleted : %d\n",temp->data);
    l->count--; return l;
}
List *create(List *l){
    printf("Input (-1 to exit) : ");
    while(1){
        int info; scanf("%d",&info);
        if(info == -1) break;
        l = insert(l, l->count, info);
    }
    return l;
}
int search(List *l, int key){
    if(isnull(l)) return -1;
    Node *temp = l->head; int i=0;
    while (temp){
        if (temp->data == key){
            printf("Value found in %d position\n",i+1);
            return i;
        }
        temp = temp->next;
        i++;
    }
    printf("%d Not Found\n",key);
    return -1;
}
List *delkey(List *l, int key){
    int t = search(l, key);
    if(t == -1) return l;
    l = delete(l, t);
    return l;
}

void main(){
    List *l = malloc(sizeof(List));
    l->head = NULL; l->tail = NULL;
    l->count = 0; l = create(l);
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
        int ch; scanf("%d",&ch);
        if(ch == 1) disbeg(l);
        else if(ch == 2) disend(l);
        else if(ch == 3) printf((isnull(l))?"":"Not Empty\n");
        else if(ch == 4){
            printf("Enter index & info : ");
            int pos, info; scanf("%d%d",&pos,&info);
            l = insert(l, pos, info);
        }
        else if(ch == 5){
            printf("Enter index to be deleted : ");
            int pos; scanf("%d",&pos);
            l = delete(l, pos);
        }
        else if(ch == 6){
            printf("Enter key to be deleted : ");
            int key; scanf("%d",&key);
            l = delkey(l, key);
        }
        else if(ch==7) printf("No. of nodes : %d\n", l->count);
        else if(ch==8){
            printf("Enter key to search : ");
            int key; scanf("%d",&key);
            search(l, key);
        }
        else if(ch == 0) break;
        else printf("Wrong choice\n");
    }
}