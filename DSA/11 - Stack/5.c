#include <stdio.h>
#include <stdlib.h>
struct SNode{
    int data, index;
    struct SNode* link;
};
void push(struct SNode **stack, int data, int index){
    struct SNode *new = malloc(sizeof(struct SNode));
    new->data = data; new->index = index;
    new->link = *stack; *stack = new;
}
int isEmpty(struct SNode *stack){
    if(stack == NULL) return 1;
    return 0;
}
int pop(struct SNode **stack){
    if (*stack){
        struct SNode *temp = *stack;
        int res = temp->data;
        *stack = temp->link;
        free(temp);
        return res;
    }
}

void makeNext(int arr[], int n, int nextBig[]){
    struct SNode *s = NULL;
    for (int i = n-1; i >= 0; i--) {
        nextBig[i] = i;
        while (!isEmpty(s) && s->data < arr[i])
            pop(&s);
        if (!isEmpty(s))
            nextBig[i] = s->index;
        push(&s, arr[i], i);
    }
}
void makePrev(int arr[], int n, int prevBig[]){
    struct SNode *s = NULL;
    for (int i = 0; i < n; i++) {
        prevBig[i] = -1;
        while (!isEmpty(s) && s->data < arr[i])
            pop(&s);
        if (!isEmpty(s))
            prevBig[i] = s->index;
        push(&s, arr[i], i);
    }
}
int max(int a, int b) {
    return a > b ? a : b;
}
int wrapper(int arr[], int n) {
    int nextBig[106], prevBig[106];
    int *maxi = calloc(n, sizeof(int)), ans = 0;
    makePrev(arr, n, prevBig);
    makeNext(arr, n, nextBig);
    for (int i = 0; i < n; i++)
        if (nextBig[i] != i)
            maxi[nextBig[i] - i] = max(maxi[nextBig[i] - i],
                                       i - prevBig[i]);
 
    for (int i = 0; i < n; i++)
        ans += maxi[i];
    return ans;
}
 
int main(){
    printf("Enter no. of elements : ");
    int n; scanf("%d",&n);
    int *arr = malloc(n*sizeof(int));
    printf("Enter array element : ");
    for(int i = 0; i < n; i++)
        scanf("%d",&arr[i]);
    printf("Total count : %d", wrapper(arr, n));
    return 0;
}