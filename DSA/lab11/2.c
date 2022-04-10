#include <stdio.h>
#include <stdlib.h>
typedef struct SNode{
    int data;
    struct SNode* link;
}Stack;

void push(Stack **stack, int data){
    Stack *new = malloc(sizeof(Stack));
    new->data = data;  new->link = *stack;
    *stack = new;
}
int pop(Stack **stack){
    if (*stack){
        Stack *temp = *stack;
        int res = temp->data;
        *stack = temp->link;
        free(temp); return res;
    }
    printf("Stack Underflow\n");
}

void display(Stack *stack){
    if(stack){
        Stack *temp = stack;
        while(temp){
            printf("%d ",temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
    else  printf("Empty Stack\n");
}

void insbot(Stack **stack, int item){
    if(!*stack)
        push(stack, item);
    else{
        int temp = pop(stack);
        insbot(stack, item);
        push(stack, temp);
    }
}
void reverse(Stack **stack){
    if(*stack){
        int item = pop(stack);
        reverse(stack);
        insbot(stack, item);
    }
}

int main(){
    Stack *stack = NULL;
    printf("1. Push\n2. Pop\n3. Display\n4. Reverse\n0. Exit\n");
    while(1){
        printf("\nEnter your choice : ");
        int ch; scanf("%d",&ch);
        if(ch == 1){
            printf("Enter the value : ");
            int in; scanf("%d",&in);
            push(&stack, in);
        }
        else if(ch == 2){
            if(stack){
                int del = pop(&stack);
                printf("%d popped\n",del);
            }
            else printf("Stack Underflow\n");
        }
        else if(ch == 3) display(stack);
        else if(ch == 4) {
            if(stack) reverse(&stack);
            else printf("Stack is empty\n");
        }
        else if(ch == 0) break;
        else printf("Please Enter valid choice\n");
    }
    return 0;
}