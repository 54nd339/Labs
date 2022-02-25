#include <stdio.h>
#include <stdlib.h>
struct Stack{
    int data;
    struct Stack* link;
};

void push(struct Stack **root, int data){
    struct Stack *new = malloc(sizeof(struct Stack));
    new->data = data;  new->link = *root;
    *root = new;
}
int pop(struct Stack **root){
    if (root){
        struct Stack *temp = *root;
        int res = temp->data;
        *root = temp->link;
        free(temp);
        return res;
    }
    printf("Stack Overflow\n");
    exit(1);
}
void display(struct Stack *root){
    if(root){
        struct Stack *temp = root;
        while(temp){
            printf("%d ",temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}

struct Stack *sort(struct Stack *input){
    struct Stack *temp=NULL;
    while (input!=NULL){
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
	struct Stack *stack=NULL; int in;
    //printf("Input (-1 to exit) : ");
    while(1){
        scanf("%d",&in);
        if(in==-1) break;
        push(&stack,in);
    }
    printf("Input : ");
    display(stack);
    stack=sort(stack);
    printf("Output : ");
	display(stack);
	return 0;
}