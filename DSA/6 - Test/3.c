#include <stdio.h>
#include <stdlib.h>
struct node{
    int row, col;
    float val;
    struct node *link;
}*t1,*t2,*temp,*new;

void new_node(struct node *ptr,int row, int col, float val){
    if(val==0) return; ptr->val++;
    new=malloc(sizeof(struct node));
    new->row=row; new->col=col;
    new->val=val; new->link=NULL;
    temp->link=new; temp=new;
}
void display(struct node *ptr){
    temp=ptr;
    while(temp){
        printf("%d %d %.2f\n", temp->row, temp->col, temp->val);
        temp=temp->link;
    }
}
void create(struct node **ptr){
    check1:
    printf("Enter total row, column & non-zero elements : ");
    *ptr=malloc(sizeof(struct node));
    scanf("%d%d%f",&(*ptr)->row,&(*ptr)->col,&(*ptr)->val);
    (*ptr)->link=NULL; 
    if((*ptr)->val>(*ptr)->row*(*ptr)->col){
        printf("Non zero elements exceeded\n");
        goto check1;
    }

    int r,c; float v,val=(*ptr)->val; 
    (*ptr)->val=0; temp=*ptr;
    printf("Enter Row, Column, Value for :\n");
    for(int i=0;i<val;i++){
        check2:
        printf("Input %d : ",i+1);
        scanf("%d%d%f",&r,&c,&v);
        if(r>(*ptr)->row || c>(*ptr)->col || r<1 || c<1){
            printf("Row or Column Exceeded\n");
            goto check2;
        }
        new_node(*ptr,r,c,v);
    }
    printf("\nINPUT :\n");
    display(*ptr);
}
void remdup(struct node **ptr){
    struct node *prev,*dup;
    t1 = (*ptr)->link;
    while (t1 && t1->link){
        t2 = t1;
        while (t2->link){
            if (t1->row==t2->link->row
            && t1->col==t2->link->col) {
                t2->link->val += t1->val;
                dup = t1;
                if(t1==(*ptr)->link)
                    (*ptr)->link=t1->link;
                else
                    prev->link=t1->link;
                t1 = t2 = t1->link;
                (*ptr)->val--;
            }
            else t2 = t2->link;
        }
        prev=t1; t1 = t1->link;
    }
}
struct node *mul(struct node *ptr1,struct node *ptr2){
    if(ptr1->col!=ptr2->row){
        printf("\nProduct Not possible\n");
        return;
    }
    struct node *prod=malloc(sizeof(struct node));
    prod->row=ptr1->row; prod->col=ptr2->col;
    prod->val=0; prod->link=NULL;
    t1=ptr1->link; temp=prod;
    while(t1!=NULL){
        t2=ptr2->link;
        while(t2!=NULL){
            if(t1->col==t2->row)
                new_node(prod,t1->row,t2->col,(t1->val)*(t2->val));
            t2=t2->link;
        }
        t1=t1->link;
    }
    printf("\nProduct :\n");
    remdup(&(prod));
    return prod;
}
int main(){
    struct node *a, *b, *c, *prod;
    printf("\nMatrix 1 :\n");
    create(&a);
    printf("\nMatrix 2 :\n");
    create(&b);
    printf("\nMatrix 3 :\n");
    create(&c);
    
    prod=mul(a,b);
    prod=mul(prod,c);
    printf("\nProduct :\n");
    display(prod);
    return 0;
}