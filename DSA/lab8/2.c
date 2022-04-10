#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* link;
}*root = NULL;
int popped, count = 0;
void push(int data){
    struct node *new = malloc(sizeof(struct node));
    new->data = data;  new->link = root;
    root = new; count++;
}
int pop(){
    if (root){
        struct node *temp = root;
        int res = temp->data;
        root = temp->link;
        free(temp);
        return res;
    }
    printf("Stack Overflow\n");
    exit(1);
}
void display(){
    if(root){
        struct node *temp = root;
        while(temp){
            printf("%d ",temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}
int main(){
    printf("1. Push\n2. Pop\n3. Display\n4. isEmpty\n0. Exit\n");
    while(1){
        printf("\nEnter your choice : ");
        int ch; scanf("%d",&ch);
        if(ch == 1){
            printf("Enter the value : ");
            int in; scanf("%d",&in);
            push(in);
        }
        else if(ch == 2) printf("%d popped\n",pop());
        else if(ch == 3) display();
        else if(ch == 4) printf(root?"Not Empty\n":"Empty\n");
        else if(ch == 0) break;
        else printf("Please Enter valid choice\n");
        if(!root) printf("Empty\n");
        else printf("Top element is %d\n", root->data);
    }
    return 0;
}