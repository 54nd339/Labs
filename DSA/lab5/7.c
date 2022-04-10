#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *prev, *next;
}Node;
void display(Node *root){
    Node *curr = root;
    if(root == NULL){
        printf("Empty list\n");
        return;
    }
    while(curr){
        printf("%d ",curr->data);
        curr = curr->next;
    }
}
Node *create(Node *root){
    printf("Input (-1 to exit) : ");
    Node *temp = NULL;
    while(1){
        int in; scanf("%d",&in);
        if(in == -1) break;
        Node *new = malloc(sizeof(Node));    
        new->data = in;
        new->prev = new->next = NULL;
        if(root == NULL)
            root = new;
        else{
           temp->next = new; 
           new->prev = temp;
        }
        temp = new;
    }
    printf("I/P : ");
    display(root); return root;
}
void delNode(Node *root, Node *del){
    if(root==NULL || del==NULL) return;
    if(root == del) root = del->next;
    if(del->next) del->next->prev = del->prev;
    if(del->prev) del->prev->next = del->next;
    free(del);
}
void remDup(Node *root){
    Node *temp = root;
    while (temp->next) {
        if (temp->data == temp->next->data)
            delNode(root, temp->next);
        else temp = temp->next;
    }
    printf("\nO/P : ");
    display(root);
}
int main(){
    Node *root = malloc(sizeof(Node));
    root = NULL; root = create(root);
    (root==NULL) ? printf("Empty list\n") : remDup(root);
    return 0;
}