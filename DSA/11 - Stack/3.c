#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct SNode{
    int data;
    struct SNode* link;
}Stack; int min;

int isEmpty(Stack *stack){
    if(stack == NULL) return 1;
    return 0;
}
void push(Stack **stack, int data){
    Stack *new = malloc(sizeof(Stack));
    if(isEmpty(*stack)){
        new->data = data; new->link = *stack;
        *stack = new; min = data;
    }
    else if(data < min){
        new->data = 2*data - min; new->link = *stack;
        *stack = new; min = data;
    }
    else{
        new->data = data; new->link = *stack;
        *stack = new;
    }
}
int pop(Stack **stack){
    if (*stack){
        Stack *temp = *stack;
        int res = temp->data;
        *stack = temp->link;
        free(temp);
        if(res < min) min = 2*min - res;
        return res;
    }
    printf("Stack Underflow\n");
}

void getMin(Stack *stack){
    if (isEmpty(stack))
        printf("Stack is empty\n");
    else
        printf("Min Element : %d\n",min);
}
void peek(Stack *stack){
    if (isEmpty(stack)){
        printf("Stack is empty\n");
        return;
    }
    int t = stack->data;
    printf("Top Most Element is : %d\n",(t < min)? min:t);
}

int main(){
    Stack *stack = NULL;
    int ch,in;
    printf("1. Push\n2. Pop\n3. Peek\n4. GetMin\n0. Exit\n");
    while(1){
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        if(ch==1){
            printf("Enter the value : ");
            scanf("%d",&in);
            push(&stack, in);
        }
        else if(ch==2){
            if(stack){
                int del=pop(&stack);
                printf("%d popped\n",del);
            }
            else printf("Stack Underflow\n");
        }
        else if(ch==3) peek(stack);
        else if(ch==4) getMin(stack);
        else if(ch==0) break;
        else printf("Please Enter valid choice\n");
    }
    return 0;
}