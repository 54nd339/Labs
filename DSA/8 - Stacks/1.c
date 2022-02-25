#include <stdio.h>
#include <stdlib.h>
struct Stack {
    int top, *arr;
    unsigned capacity;
}*stack;
 
void create(){
    stack = malloc(sizeof(struct Stack));
    printf("Enter capacity of the stack : ");   
    scanf("%d",&stack->capacity);
    stack->top = -1;
    stack->arr = (int*)malloc(stack->capacity * sizeof(int));
}
void push(){
    if(stack->top == stack->capacity-1)
        printf("Overflow\n");
    else{  
        printf("Enter the value : ");
        scanf("%d",&stack->arr[++stack->top]);
    }
}
void pop(){ 
    if(stack->top == -1)  printf("Underflow\n");
    else printf("%d popped\n",stack->arr[stack->top--]);
}
void display(){  
    for(int i=stack->top;i>=0;i--)  
        printf("%d ",stack->arr[i]);
    printf("\n");
    if(stack->top == -1)
        printf("Stack is empty");
}

int main (){
    create(); int ch;
    printf("1. Push\n2. Pop\n3. Display\n4. IsEmpty\n0. Exit\n");  
    while(1){  
        printf("\nEnter your choice : ");
        scanf("%d",&ch);  
        if(ch==1) push();
        else if(ch==2) pop();
        else if(ch==3) display();
        else if(ch==4) printf(stack->top == -1?"Empty\n":"Not empty\n");
        else if(ch==0) break;
        else printf("Please Enter valid choice ");
        printf((stack->top!=-1)?"Element at top : %d\n"
            :"Empty\n",stack->arr[stack->top]);
    }
    return 0;
}