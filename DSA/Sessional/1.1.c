#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    float diff;
    struct Node *link;
};
struct header {
    int n;
    float avg, max, min;
    struct Node *link;
};
struct list {
    struct header *head;
    struct Node *node;
}; 
void display(struct list *LL){
    printf("Number of nodes : %d\n", LL->head->n);
    printf("Avg value of elements : %f\n", LL->head->avg);
    printf("Max difference of node value and avg value : %f\n", LL->head->max);
    printf("Min difference of node value and avg value : %f\n", LL->head->min);
    struct Node *temp = LL->node;
    printf("List : ");
    while(temp){
        printf("%d ",temp->data);
        temp = temp->link;
    }
    printf("\n");
}
struct Node *newNode(int info){
    struct Node *new=malloc(sizeof(struct Node));
    new->data=info; new->link=NULL;
    count++; return new;
}
struct node *createList(){
    struct node *head, *temp;
    head = temp = NULL; int info;
    printf("Input (-1 to exit) : ");
    while(1){
        scanf("%d",&info);
        if(info == -1) break;
        struct node *new = newNode(info);
        if(head==NULL) head=new;
        else temp->link=new;
        temp=new;
    }
    display(head); return head;
}
int main(){

}