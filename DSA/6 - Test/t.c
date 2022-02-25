#include <stdio.h>
#include <stdlib.h>
struct node{
    int row, col;
    float val;
    struct node *link;
}*temp,*new;

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
    //printf("Enter total row, column & non-zero elements : ");
    *ptr=malloc(sizeof(struct node));
    scanf("%d%d%f",&(*ptr)->row,&(*ptr)->col,&(*ptr)->val);
    (*ptr)->link=NULL; 
    if((*ptr)->val>(*ptr)->row*(*ptr)->col){
        //printf("Non zero elements exceeded\n");
        goto check1;
    }

    int r,c; float v,val=(*ptr)->val; 
    (*ptr)->val=0; temp=*ptr;
    //printf("Enter Row, Column, Value for :\n");
    for(int i=0;i<val;i++){
        check2:
        //printf("Input %d : ",i+1);
        scanf("%d%d%f",&r,&c,&v);
        if(r>(*ptr)->row || c>(*ptr)->col || r<1 || c<1){
            printf("Row or Column Exceeded\n");
            goto check2;
        }
        new_node(*ptr,r,c,v);
    }
    //printf("\nINPUT :\n");
    display(*ptr);
}
struct node *add(struct node *ptr1,struct node *ptr2){
    if(ptr1->row!=ptr2->row && ptr1->col!=ptr2->col){
        printf("\nAddition Not possible\n");
        return NULL;
    }
    struct node *sum=malloc(sizeof(struct node));
    sum->row=ptr1->row; sum->col=ptr1->col;
    sum->val=0; sum->link=NULL;

    struct node *t1,*t2;
    t1=ptr1->link; t2=ptr2->link; temp=sum;
    while(t1!=NULL&&t2!=NULL){
        if(t1->row==t2->row && t1->col==t2->col){
            new_node(sum,t1->row,t1->col,t1->val+t2->val);
            t1=t1->link;
            t2=t2->link;
        }
        else if(t1->row<t2->row ||
        (t1->col<t2->col && t1->row<=t2->row)){
            new_node(sum,t1->row,t1->col,t1->val);
            t1=t1->link;
        }
        else{
            new_node(sum,t2->row,t2->col,t2->val);
            t2=t2->link;
        }
    }
    while(t1!=NULL){
        new_node(sum,t1->row,t1->col,t1->val);
        t1=t1->link;
    }
    while(t2!=NULL){
       new_node(sum,t2->row,t2->col,t2->val);
       t2=t2->link;
    }
    return sum;
}
int main(){
    struct node *a, *b, *c, *sum;
    printf("\nMatrix 1 :\n");
    create(&a);
    printf("\nMatrix 2 :\n");
    create(&b);
    printf("\nMatrix 3 :\n");
    create(&c);
    
    sum=add(a,b);
    sum=add(sum,c);
    printf("\nSum :\n");
    display(sum);
    return 0;
}