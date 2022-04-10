#include <stdio.h>
#include <stdlib.h>
typedef struct SNode{
    int data;
    struct SNode *link;
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
        free(temp);
        return res;
    }
    printf("Stack Underflow\n");
    exit(1);
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

Stack *reverse(Stack *stack){
	Stack *temp = NULL;
    while(stack)
        push(&temp,pop(&stack));
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
    stack = reverse(stack);
    printf("Output : ");
	display(stack);
	return 0;
}