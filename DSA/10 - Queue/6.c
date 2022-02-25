#include <stdio.h>
#include <stdlib.h>
struct DLLNode {
    int data;
    struct DLLNode *prev, *next;
};
struct Stack {
    int count;
    struct DLLNode *head, *mid, *tail;
};
struct Stack *create(){
    struct Stack *stack = malloc(sizeof(struct Stack));
    stack->count = 0; return stack;
};

void push(struct Stack *stack, int data){
    struct DLLNode *node = malloc(sizeof(struct DLLNode));
    node->data = data; node->prev = NULL;
    node->next = stack->head;
    stack->count += 1;
    if (stack->count == 1){
        stack->mid = node;
        stack->tail = node;
    }
    else {
        stack->head->prev = node;
        if (stack->count & 1)
            stack->mid = stack->mid->prev;
    }
    stack->head = node;
}
int pop(struct Stack *stack){
    if (stack->count == 0) {
        printf("Stack is empty\n");
        return -1;
    }
    struct DLLNode *head = stack->head;
    int item = head->data;
    stack->head = head->next;
    if (stack->head != NULL)
        stack->head->prev = NULL;
    stack->count -= 1;
    if (!((stack->count) & 1))
        stack->mid = stack->mid->next;
    free(head);
    return item;
}

int peekHighestElement(struct Stack *stack){
    if (stack->count == 0) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->head->data;
} 
int peekMiddleElement(struct Stack *stack){
    if (stack->count == 0) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->mid->data;
}
int peekLowestElement(struct Stack *stack){
    if (stack->count == 0) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->tail->data;
} 

int main(){
    struct Stack *stack = create();
    int ch,in;
    printf("1. Push\n2. Pop\n3. Top Element\n4. Middle Element\n5. Bottom Element\n0. Exit\n");
    while(1){
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        if(ch==1){
            printf("Enter the value : ");
            scanf("%d",&in);
            push(stack, in);
        }
        else if(ch==2){
            int del=pop(stack);
            printf("%d popped\n",del);
        }
        else if(ch==3) printf("Top Element: %d\n",peekHighestElement(stack));
        else if(ch==4) printf("Middle Element: %d\n",peekMiddleElement(stack));
        else if(ch==5) printf("Bottom Element: %d\n",peekLowestElement(stack));
        else if(ch==0) break;
        else printf("Please Enter valid choice\n");
    }
    return 0;
}