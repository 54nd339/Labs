#include <stdio.h>
#include <stdlib.h>
struct Stack{
    int data;
    struct Stack* link;
};

void push(struct Stack **stack, int data){
    struct Stack *new = malloc(sizeof(struct Stack));
    new->data = data;  new->link = *stack;
    *stack = new;
}
int pop(struct Stack **stack){
    if (*stack){
        struct Stack *temp = *stack;
        int res = temp->data;
        *stack = temp->link;
        free(temp);
        return res;
    }
    printf("Stack Underflow\n");
    exit(1);
}
void display(struct Stack *stack){
    if(stack){
        struct Stack *temp = stack;
        while(temp){
            printf("%d ",temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
    else printf("Empty Stack\n");
}

struct Stack *reverse(struct Stack *stack){
	struct Stack *temp=NULL;
    while(stack)
        push(&temp,pop(&stack));
    return temp;
}

int main(){
	struct Stack *stack=NULL; int in;
    //printf("Input (-1 to exit) : ");
    while(1){
        scanf("%d",&in);
        if(in==-1) break;
        push(&stack,in);
    }
    printf("Input : ");
    display(stack);
    stack=reverse(stack);
    printf("Output : ");
	display(stack);
	return 0;
}