#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
typedef struct{
	int top;
	unsigned capacity;
	float *array;
}Stack;
Stack *createStack(unsigned capacity ){
	Stack *new = malloc(sizeof(Stack));
	new->top = -1; new->capacity = capacity;
	new->array = calloc(new->capacity , sizeof(float));
	if (!new->array) return NULL; return new;
}

int isEmpty(Stack *stack){
	return stack->top == -1 ;
}
float peek(Stack *stack){
	return stack->array[stack->top];
}
float pop(Stack *stack){
	if (!isEmpty(stack))
		return stack->array[stack->top--] ;
	return '$';
}
void push(Stack *stack, float op){
	stack->array[++stack->top] = op;
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
char *reverse(char *exp){
    int l = strlen(exp);
    char *out = malloc(l*sizeof(char));
    out[l] = '\0';
    for(int i=0,j=l-1; exp[i]; i++,j--){
        char ch = exp[i];
        if(ch == '(') out[j] = ')';
        else if(ch == ')') out[j] = '(';
        else out[j] = ch;
    }
    return out;
}
char *infixToPostfix(char *exp){
	int l = strlen(exp), i = 0, k = -1;;
	Stack *stack = createStack(l);
	if(!stack) return NULL ;
    char *out = malloc(l*sizeof(char));
	while(exp[i]){
		if(exp[i] == ' ') i++;
        else if (isalnum(exp[i]))
			out[++k] = exp[i++];
        else if (exp[i] == '(')
			push(stack,exp[i++]);
        else if (exp[i] == ')'){
			while (!isEmpty(stack) && peek(stack) != '(')
				out[++k] = pop(stack);
			if (!isEmpty(stack) && peek(stack) != '('){
                printf("Invalid Epression\n");
				return NULL;		
            }
            else pop(stack); i++;
		}
		else{
			while (!isEmpty(stack) && Prec(exp[i]) <= Prec(peek(stack)))
				out[++k] = pop(stack);
			push(stack,exp[i++]);
		}
	}

	while (!isEmpty(stack))
		out[++k] = pop(stack);
	out[++k] = '\0';
	return out;
}
char *infixToPrefix(char *exp){
    return reverse(infixToPostfix(reverse(exp)));
}
int main(){
	char exp[] = "(A+B)*(C-D)";
	printf("Infix expression : ");
	printf("%s\n",exp);
	printf ("Prefix Expression : %s\n", infixToPrefix(exp));
	return 0;
}