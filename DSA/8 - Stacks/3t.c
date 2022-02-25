#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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

int Prec(char ch){
	switch (ch){
	case '+':
	case '-':
		return 1;

	case '*':
	case '/':
		return 2;

	case '^':
		return 3;
	}
	return -1;
}

char *infixToPostfix(char *exp){
	int l = strlen(exp), i=0, k=-1;;
	struct Stack *stack = NULL;
	char *out=malloc(l*sizeof(char));
	while(exp[i]){
		if(exp[i]==' ') i++;
        else if (isalnum(exp[i]))
			out[++k] = exp[i++];
        else if (exp[i] == '(')
			push(&stack,exp[i++]);
        else if (exp[i] == ')'){
			while (stack && stack->data != '(')
				out[++k] = pop(&stack);
			if (stack && stack->data != '('){
                printf("Invalid Epression\n");
				return NULL;		
            }
            else pop(&stack); i++;
		}
		else{
			while (stack && Prec(exp[i]) <= Prec(stack->data))
				out[++k] = pop(&stack);
			push(&stack,exp[i++]);
		}
	}
	while (stack) out[++k] = pop(&stack);
	out[++k] = '\0';
	return out;
}

int main(){
	char exp[] = "(A+B)*(C-D)";
	printf("Infix expression : ");
	printf("%s\n",exp);
	printf ("Postfix Expression : %s\n", infixToPostfix(exp));
	return 0;
}