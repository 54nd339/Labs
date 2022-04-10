#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct node{
    int powx, powy;
    float coeff;
    struct node *link;
}Node;
void newNode(Node **ptr, int powx, int powy, float coeff){
    if(coeff == 0) return;
    Node *new = malloc(sizeof(Node));
    new->powx = powx; new->powy = powy;
    new->coeff = coeff; new->link = NULL;
    if(*ptr == NULL)
        *ptr = new;
    else{
        Node *temp = *ptr;
        while(temp->link)
            temp = temp->link;
        temp->link = new;
    }
}
void display(Node *ptr){
    if(ptr == NULL){
        printf("Empty Polynomial\n"); return;
    }
    Node *temp = ptr;
    while(temp){
        printf("%.2fx^%dy^%d",temp->coeff,temp->powx,temp->powy);
        if(temp = temp->link)
            printf((temp->coeff>=0) ? " + " : " - ");
    }
    printf("\n");
}
void remdup(Node **ptr){
    Node *t1 = *ptr;
    while (t1 && t1->link){
        Node *t2 = t1;
        while (t2->link){
            if (t1->powx == t2->link->powx && t1->powy == t2->link->powy) {
                t1->coeff = t1->coeff + t2->link->coeff;
                Node *dup = t2->link;
                t2->link = t2->link->link;
                free(dup);
            }
            else t2 = t2->link;
        }
        t1 = t1->link;
    }
}
void create(Node **ptr){
    int powx, powy, i=1; float in;
    Node *temp = *ptr = NULL;
    //printf("Enter powx, powy, coeff for each term :\n");
    //printf("Input (powx as -1 to exit) : \n");
    while(1){
        //printf("Term %d : ",i);
        scanf("%d",&powx);
        if(powx == -1) break;
        scanf("%d",&powy);
        scanf("%f",&in);
        newNode(ptr,powx,powy,in); i++;
    }
    remdup(ptr);
    display(*ptr);
}
Node *add(Node *ptr1,Node *ptr2){
    Node *sum = malloc(sizeof(Node));
    Node *t1 = ptr1, *t2 = ptr2;
    Node *temp = sum = NULL;
    while(t1!=NULL && t2!=NULL){
        if(t1->powx==t2->powx && t1->powy==t2->powy){
            newNode(&sum,t1->powx,t1->powy,t1->coeff+t2->coeff);
            t1 = t1->link;
            t2 = t2->link;
        }
        else if(t1->powx>t2->powx ||
        (t1->powy>t2->powy && t1->powx==t2->powx)){
            newNode(&sum,t1->powx,t1->powy,t1->coeff);
            t1 = t1->link;
        }
        else{
            newNode(&sum,t2->powx,t2->powy,t2->coeff);
            t2 = t2->link;
        }
    }
    while(t1 != NULL){
        newNode(&sum,t1->powx,t1->powy,t1->coeff);
        t1 = t1->link;
    }
    while(t2 != NULL){
       newNode(&sum,t2->powx,t2->powy,t2->coeff);
       t2 = t2->link;
    }
    return sum;
}
int main(){
    printf("\nPolynomial 1 :\n");
    Node *poly1; create(&poly1);
    printf("\nPolynomial 2 :\n");
    Node *poly2; create(&poly2);
    Node *sum = add(poly1, poly2);
    remdup(&sum);
    printf("\nSum : ");
    display(sum);
    return 0;
}