#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    char data;
    struct node* link;
}List;
void add(List **head, char data){
    List *new = malloc(sizeof(List));
    new->data = data; new->link = NULL;
    if(*head == NULL)
        *head = new;
    else{
        List *temp = *head;
        while(temp->link)
            temp = temp->link;
        temp->link = new;
    }
}
char poll(List **head){
    List *temp = *head;
    char data = temp->data;
    *head = temp->link;
    free(temp); return data;
}

typedef struct SNode{
    char data;
    struct SNode* link;
}Stack;
void push(Stack **stack, char data){
    Stack *new = malloc(sizeof(Stack));
    new->data = data;  new->link = *stack;
    *stack = new;
}
char pop(Stack **stack){
    if (*stack){
        Stack *temp = *stack;
        char res = temp->data;
        *stack = temp->link;
        free(temp); return res;
    }
}

char *arrange(char *string){
    int length = strlen(string);
    Stack *stack = NULL;
    for(int i = 0; i < length; i++){
        if(stack == NULL) push(&stack, string[i]);
        else{
            if(string[i] == '\\'){
                List *Q = NULL;
                while(stack!=NULL && stack->data!='/')
                    add(&Q, pop(&stack));
                if(stack!=NULL && stack->data=='/')
                    pop(&stack);
                while(Q!=NULL)
                    push(&stack, poll(&Q));
            }
            else push(&stack, string[i]);
        }
    }
    int i=0;
    char *out = malloc(sizeof(char));
    while(stack)
        out[i++] = pop(&stack);
    return strrev(out);
}
int main(){
    char in[20];
    printf("Input : "); //test case : "/u/love\i\"
    scanf("%s",in);
    printf("Output : %s\n", arrange(in));
    return 0;
}