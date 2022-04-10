#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int top, *arr;
    unsigned size;
}Stack;

Stack *create(){
    Stack *stack = malloc(sizeof(Stack));
    printf("Enter size of the stack : ");   
    scanf("%d",&stack->size);
    stack->top = -1;
    stack->arr = (int*)malloc(stack->size * sizeof(int));
    return stack;
}
Stack *tcreate(Stack *stack){
    Stack *tstack = malloc(sizeof(Stack));
    tstack->size = stack->size;
    tstack->top = -1;
    tstack->arr = (int*)malloc(stack->size * sizeof(int));
    return tstack;
}
void push(Stack *stack, int k){
    stack->arr[++stack->top] = k;
}
int pop(Stack *stack){ 
    return stack->arr[stack->top--];
}
int display(Stack *stack){
    if(stack->top == -1) printf("Q is empty\n");
    for(int i=stack->top; i>=0; i--)  
        printf("%d ",stack->arr[i]);
    printf("\n");
}

void enQueue(Stack *stack, int x){
    if(stack->top == stack->size-1){
        printf("Overflow\n"); return;
    }
    Stack *tstack = tcreate(stack);
    while (stack->top != -1)
        push(tstack, pop(stack));
    push(stack, x);
    while (tstack->top != -1) 
        push(stack, pop(tstack));
}
int deQueue(Stack *stack){
    if (stack->top == -1) {
        printf("Q is Empty (Underflow) \n");
        return -1;
    }
    return pop(stack);
}

int main (){
    Stack *stack = create();
    printf("1. Enqueue\n2. Dequeue\n3. Display\n0. Exit\n");  
    while(1){  
        printf("\nEnter your choice : ");
        int ch; scanf("%d",&ch);  
        if(ch == 1) {
            printf("Enter the value : ");
            int val; scanf("%d",&val);
            enQueue(stack, val);
        }
        else if(ch == 2) {
            int val = deQueue(stack);
            if(val != -1) printf("%d Dequeued\n",val);
        }
        else if(ch == 3) display(stack);
        else if(ch == 0) break;
        else printf("Please Enter valid choice ");
    }
    return 0;
}