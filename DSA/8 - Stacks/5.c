#include <stdio.h>
#include <stdlib.h>
struct Stack {
	char data;
	struct Stack *link;
}*stack=NULL;

void push(int data){
	struct Stack *new = malloc(sizeof(struct Stack));
    new->data = data; new->link = stack;
    stack = new;
}
int pop(){
	if (stack) {
		struct Stack *top = stack;
		char res = top->data;
		stack = top->link;
		free(top);
		return res;
	}
    printf("Stack Underflow\n");
    exit(1);
}

int isMatching(char ch1, char ch2){
	if (ch1 == '(' && ch2 == ')')
		return 1;
	else if (ch1 == '{' && ch2 == '}')
		return 1;
	else if (ch1 == '[' && ch2 == ']')
		return 1;
	else
		return 0;
}
int isBalanced(char *exp){
	for (int i=0; exp[i]; i++){
        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
			push(exp[i]);
        if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']') {
            if (stack == NULL)
				return 0;
            else if (!isMatching(pop(&stack), exp[i]))
				return 0;
		}
	}
	return 1;
}

int main(){
	char *exp="({[}])";
    printf(isBalanced(exp)?"%s : Balanced \n":"%s : Not Balanced \n",exp);
    exp="({[]})";
    printf(isBalanced(exp)?"%s : Balanced \n":"%s : Not Balanced \n",exp);
	return 0;
}