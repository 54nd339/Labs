#include <stdio.h>
#include <stdlib.h>
typedef struct DLLNode {
    int data;
    struct DLLNode *prev, *next;
}DLL;
typedef struct {
    int count;
    DLL *head, *mid, *tail;
}Stack;
Stack *create(){
    Stack *stack = malloc(sizeof(Stack));
    stack->count = 0; return stack;
};

void push(Stack *stack, int data){
    DLL *node = malloc(sizeof(DLL));
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
int pop(Stack *stack){
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

int peekHighestElement(Stack *stack){
    if (stack->count == 0) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->head->data;
} 
int peekMiddleElement(Stack *stack){
    if (stack->count == 0) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->mid->data;
}
int peekLowestElement(Stack *stack){
    if (stack->count == 0) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->tail->data;
} 

int main(){
    Stack *stack = create();
    printf("1. Push\n2. Pop\n3. Top Element\n4. Middle Element\n5. Bottom Element\n0. Exit\n");
    while(1){
        printf("\nEnter your choice : ");
        int ch; scanf("%d",&ch);
        if(ch == 1){
            printf("Enter the value : ");
            int in; scanf("%d",&in);
            push(stack, in);
        }
        else if(ch == 2){
            int del = pop(stack);
            printf("%d popped\n",del);
        }
        else if(ch == 3) printf("Top Element: %d\n",peekHighestElement(stack));
        else if(ch == 4) printf("Middle Element: %d\n",peekMiddleElement(stack));
        else if(ch == 5) printf("Bottom Element: %d\n",peekLowestElement(stack));
        else if(ch == 0) break;
        else printf("Please Enter valid choice\n");
    }
    return 0;
}