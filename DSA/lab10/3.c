#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
};

void push(struct node **root, int data){
    struct node *new = malloc(sizeof(struct node));
    new->data = data;  new->link = *root;
    *root = new;;
}
int pop(struct node **root){
    if (*root){
        struct node *temp = *root;
        int res = temp->data;
        *root = temp->link;
        free(temp);
        return res;
    }
    printf("Stack Underflow\n");
}
struct node *sortStack(struct node *input){
    struct node *tmp = NULL;
    while (input != NULL){
        int temp = pop(&input);
        while (tmp != NULL && tmp->data > temp)
            push(&input, pop(&tmp));
        push(&tmp, temp);
    }
    return tmp;
}

int *create(int *ar, int n){
    printf("Enter elements : ");
    for(int i=0; i<n; i++)
        scanf("%d",ar+i);
    return ar;
}
void print(int *ar, int n){
    for(int i=0; i<n; i++)
        printf("%d ",*(ar+i));
    printf("\n");
}
void sort(int *ar, int n){
    struct node *input = NULL;
    for (int i=0; i<n; i++)
       push(&input, *(ar+i));
    input = sortStack(input);
 
    for (int i=0; i<n; i++)
        ar[i] = pop(&input);
}
int main(){
    printf("Enter no. of elements : ");
    int n; scanf("%d",&n);
    int *arr = malloc(n*sizeof(int));
    arr = create(arr,n);
    printf("Input : ");
    print(arr,n);
    sort(arr,n);
    printf("Sorted List : ");
    print(arr,n);
    return 0;
}