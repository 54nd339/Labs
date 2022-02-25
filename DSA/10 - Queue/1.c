#include <stdio.h>
#include <stdlib.h>
struct Snode{
    int data;
    struct Snode* link;
};
int size = 0;
void push(struct Snode **root, int data){
    struct Snode *new = malloc(sizeof(struct Snode));
    new->data = data;  new->link = *root;
    *root = new; size++;
}
int pop(struct Snode **root){
    if (*root){
        struct Snode *temp = *root;
        int res = temp->data;
        *root = temp->link;
        free(temp); return res;
    }
    printf("Stack Underflow\n");
    return -1;
}
void display(struct Snode *root){
    if(root){
        struct Snode *temp = root;
        while(temp){
            printf("%d ",temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
    else printf("Empty Stack\n");
}

void transfer(struct Snode **s1, struct Snode **s2, int n){
    for (int i = 0; i < n; i++) {
        int temp = pop(s1);
        push(s2, temp);
    }
}
void reverse(struct Snode **s, int n){
    struct Snode *s2 = NULL;
    for (int i = 0; i < n; i++) {
        int x = pop(s);
        transfer(s, &s2, n-i-1);
        push(s, x);
        transfer(&s2, s, n-i-1);
    }
}

int main(){
	struct Snode *s = NULL;
	int ch,in;
    printf("1. Push\n2. Pop\n3. Reverse\n4. Display\n0. Exit\n");
    while(1){
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        if(ch==1){
            printf("Enter the value : ");
            scanf("%d",&in); push(&s, in);
        }
        else if(ch==2) {
            in = pop(&s); if(in!=-1)
            printf("Popped Element : %d\n",in);
        }
        else if(ch==3) reverse(&s, size);
        else if(ch==4) display(s);
        else if(ch==0) break;
        else printf("Please Enter valid choice\n");
    }
    return 0;
}