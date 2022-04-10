#include <stdio.h>
#include <stdlib.h>
typedef struct Snode{
    int data;
    struct Snode* link;
}Stack;
int size = 0;
void push(Stack **root, int data){
    Stack *new = malloc(sizeof(Stack));
    new->data = data;  new->link = *root;
    *root = new; size++;
}
int pop(Stack **root){
    if (*root){
        Stack *temp = *root;
        int res = temp->data;
        *root = temp->link;
        free(temp); return res;
    }
    printf("Stack Underflow\n");
    return -1;
}
void display(Stack *root){
    if(root){
        Stack *temp = root;
        while(temp){
            printf("%d ",temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
    else printf("Empty Stack\n");
}
void transfer(Stack **s1, Stack **s2, int n){
    for (int i=0; i<n; i++) {
        int temp = pop(s1);
        push(s2, temp);
    }
}
void reverse(Stack **s, int n){
    Stack *s2 = NULL;
    for (int i = 0; i < n; i++) {
        int x = pop(s);
        transfer(s, &s2, n-i-1);
        push(s, x);
        transfer(&s2, s, n-i-1);
    }
}
int main(){
	Stack *s = NULL;
    printf("1. Push\n2. Pop\n3. Reverse\n4. Display\n0. Exit\n");
    while(1){
        printf("\nEnter your choice : ");
        int ch; scanf("%d",&ch);
        if(ch == 1){
            printf("Enter the value : ");
            int in; scanf("%d",&in);
            push(&s, in);
        }
        else if(ch == 2) {
            int in = pop(&s);
            if(in != -1) printf("Popped Element : %d\n",in);
        }
        else if(ch == 3) reverse(&s, size);
        else if(ch == 4) display(s);
        else if(ch == 0) break;
        else printf("Please Enter valid choice\n");
    }
    return 0;
}