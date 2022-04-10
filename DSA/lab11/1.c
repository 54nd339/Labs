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
    else printf("Empty Stack\n");
}

void sortIns(Stack **stack, int item){
    if(!(*stack) || item>(*stack)->data)
        push(stack, item);
    else{
        int temp = pop(stack);
        sortIns(stack, item);
        push(stack, temp);
    }
}
void sort(Stack **stack){
    if(*stack){
        int x = pop(stack);
        sort(stack);
        sortIns(stack, x);
    }
}

int main(){
    Stack *stack = NULL;
    printf("1. Push\n2. Pop\n3. Display\n4. Sort\n0. Exit\n");
    while(1){
        printf("\nEnter your choice : ");
        int ch; scanf("%d",&ch);
        if(ch == 1){
            printf("Enter the value : ");
            int in; scanf("%d",&in);
            push(&stack, in);
        }
        else if(ch == 2){
            if(!stack) printf("Empty\n");
            else{
                int del = pop(&stack);
                printf("%d popped\n",del);
            }
        }
        else if(ch == 3) display(stack);
        else if(ch == 4){
            if(stack) sort(&stack);
            else printf("Empty stack");
        }
        else if(ch == 0) break;
        else printf("Please Enter valid choice\n");
    }
    return 0;
}