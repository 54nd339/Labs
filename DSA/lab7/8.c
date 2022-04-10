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

int isNull(List *l){
    if(!(l->head)){
        printf("Empty List\n");
        return 1;
    }
    return 0;
}
void display(List *l){
    if(isNull(l)) return;
    Node *temp = l->head;
    printf("List (from start) : ");
    while(temp){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
    temp = l->tail;
    printf("List (from end) : ");
    while(temp){
        printf("%d ",temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

List *create(List *l){
    printf("Input (-1 to exit) : ");
    while(1){
        int in; scanf("%d",&in);
        if(in == -1) break;
        Node *new = malloc(sizeof(Node));
        new->data = in; l->count++;
        new->prev = new->next = NULL;
        if(!(l->head))
            l->head = new;
        else{
            l->tail->next = new;
            new->prev = l->tail;
        }
        l->tail = new;
    } return l;
}

void mid(List *l){
    if(isNull(l)) return;
    Node *tmph = l->head;
    Node *tmpt = l->tail;
    while(tmph){
        if(l->count%2==1 && tmph->data==tmpt->data){
            printf("Middle Element : %d\n",tmph->data);
            break;
        }
        if(l->count%2==0 && tmph->next==tmpt){
            printf("Middle Elements : %d %d\n",tmph->data,tmpt->data);
            break;
        }
        tmph = tmph->next;
        tmpt = tmpt->prev;
    }
}

void main(){
    List *l = malloc(sizeof(List));
    l->head = l->tail = NULL;
    l->count = 0;
    printf("\n1. Create a LL");
    printf("\n2. Display the LL");
    printf("\n3. Mid of the LL");
    printf("\n0. Exit\n");
    while (1){
        printf("\nEnter choice : ");
        int in; scanf("%d",&in);
        if(in == 1) l = create(l);
        else if(in == 2) display(l);
        else if(in == 3) mid(l);
        else if(in == 0) break;
        else printf("Wrong choice\n");
    }
}