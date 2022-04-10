#include <stdio.h>
#include <stdlib.h>
typedef struct SNode{
    int data;
    struct SNode *link;
}Stack;
void push(Stack **root, int data){
    Stack *new = malloc(sizeof(Stack));
    new->data = data;  new->link = *root;
    *root = new;
}
int pop(Stack **root){
    if (root){
        Stack *temp = *root;
        int res = temp->data;
        *root = temp->link;
        free(temp);
        return res;
    }
    printf("Stack Overflow\n");
    exit(1);
}
void display(Stack *root){
    if(root){
        Stack *temp = root;
        while(temp){
            printf("%d ",temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}

Stack *sort(Stack *input){
    Stack *temp = NULL;
    while (input != NULL){
        int tmp = pop(&input);
        while (temp!=NULL && temp->data > tmp){
            push(&input,temp->data);
            pop(&temp);
        }
        push(&temp,tmp);
    }
    return temp;
}
int main(){
	Stack *stack = NULL; int in;
    //printf("Input (-1 to exit) : ");
    while(1){
        scanf("%d",&in);
        if(in == -1) break;
        push(&stack,in);
    }
    printf("Input : ");
    display(stack);
    stack = sort(stack);
    printf("Output : ");
	display(stack);
	return 0;
}