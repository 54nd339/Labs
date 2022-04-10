#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* link;
};

void push(struct node **root, int data){
    struct node *new = malloc(sizeof(struct node));
    new->data = data;  new->link = *root;
    *root = new;
}
int pop(struct node **root){
    if (*root){
        struct node *temp = *root;
        int res = temp->data;
        *root = temp->link;
        free(temp);
        return res;
    }
    printf("Stack Underflow\n");
    return -1;
}
void display(struct node *root){
    if(root){
        struct node *temp = root;
        while(temp){
            printf("%d ",temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
    else printf("Empty Stack\n");
}

struct node *sort(struct node *input){
    struct node *tmp = NULL;
    while (input != NULL){
        int temp = pop(&input);
        while (tmp != NULL && tmp->data > temp)
            push(&input, pop(&tmp));
        push(&tmp, temp);
    }
    return tmp;
}

int main(){
    struct node *root = NULL;
    printf("1. Push\n2. Pop\n3. Display\n4. Sort\n0. Exit\n");
    while(1){
        printf("\nEnter your choice : ");
        int ch; scanf("%d",&ch);
        if(ch == 1){
            printf("Enter the value : ");
            int in; scanf("%d",&in);
            push(&root, in);
        }
        else if(ch == 2){
            int del = pop(&root);
            printf("%d popped\n",del);
        }
        else if(ch == 3) display(root);
        else if(ch == 4) root = sort(root);
        else if(ch == 0) break;
        else printf("Please Enter valid choice\n");
    }
    return 0;
}