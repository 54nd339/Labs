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
void display(List *l){
    Node *curr = l->head;
    if(!(l->head)){
        printf("Empty list\n");
        return;
    }
    while(curr){
        printf("%d ",curr->data);
        curr = curr->next;
    }
}
List *create(List *l){
    printf("Input (-1 to exit) : ");
    while(1){
        int in; scanf("%d",&in);
        if(in == -1) break; l->count++;
        struct node *new = malloc(sizeof(struct node));    
        new->data = in;
        new->prev = new->next = NULL;
        if(l->head == NULL)
            l->head = new;
        else{
           l->tail->next = new; 
           new->prev = l->tail;
        }
        l->tail = new;
    }
    printf("I/P : ");
    display(l); return l;
}
int isPalin(List *l){
    Node *tmph = l->head, *tmpt = l->tail;
    for(int i=1; i<=l->count/2; i++){
        if(tmph->data != tmpt->data) return 0;
        tmph = tmph->next;
        tmpt = tmpt->prev;
    }
    return 1;
}
int main(){
    List *l = malloc(sizeof(List));
    l->head = l->tail = NULL;
    l->count = 0;
    for(int i=0; i<3; i++){
        printf("\nTest Case %d :\n",i+1);
        l = create(l);
        if(!(l->head))
            printf("Empty list\n");
        else
            printf(isPalin(l) ? "\nPalindrome\n" : "\nNot Palindrome\n");
    }
    return 0;
}