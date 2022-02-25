#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node{
    int powx,powy;
    float coeff;
    struct node *link;
}*temp,*new;

void new_node(struct node **ptr,int powx, int powy, float coeff){
    if(coeff==0) return;
    new=malloc(sizeof(struct node));
    new->powx=powx; new->powy=powy;
    new->coeff=coeff; new->link=NULL;
    if(*ptr==NULL){
        *ptr=new;temp=new;
    }else{
        temp->link=new; temp=new;
    }
}
void display(struct node *ptr){
    if(ptr==NULL){
        printf("Empty Polynomial\n");return;
    }
    temp=ptr;
    while(temp){
        float coeff=(temp==ptr)?temp->coeff:fabs(temp->coeff);
        if(temp->powx==0){
            if(temp->powy==0) printf("%.2f",coeff);
            else if(temp->powy==1) 
                printf((coeff==1)?"y":"%.2fy",coeff);
            else
                if(coeff==1) printf("y^%d",temp->powy);
                else printf("%.2fy^%d",coeff,temp->powy);  
        }
        else if(temp->powx==1){
            if(temp->powy==0)
                 printf((coeff==1)?"x":"%.2fx",coeff);
            else if(temp->powy==1)
                printf((coeff==1)?"xy":"%.2fxy",coeff);
            else
                if(coeff==1) printf("xy^%d",temp->powy);
                else printf("%.2fxy^%d",coeff,temp->powy);
        }
        else{
            if(temp->powy==0)
                 printf((coeff==1)?"x^%d":"%.2fx^%d",coeff,temp->powx);
            else if(temp->powy==1)
                printf((coeff==1)?"x^%dy":"%.2fx^%dy",coeff,temp->powx);
            else
                if(coeff==1) printf("x^%dy^%d",temp->powx,temp->powy);
                else printf("%.2fx^%dy^%d",coeff,temp->powx,temp->powy);
        }
        if(temp=temp->link)
            printf((temp->coeff>=0)?" + ":" - ");
    }
    printf("\n");
}
void create(struct node **ptr){
    int powx,powy,i=1; float in; temp=*ptr=NULL;
    //printf("Enter powx, powy, coeff for each term :\n");
    //printf("Input (powx as -1 to exit) : \n");
    while(1){
        //printf("Term %d : ",i);
        scanf("%d",&powx);
        if(powx==-1) break;
        scanf("%d",&powy);
        scanf("%f",&in);
        new_node(ptr,powx,powy,in); i++;
    }
    display(*ptr);
}

struct node *add(struct node *ptr1,struct node *ptr2){
    struct node *sum=malloc(sizeof(struct node));
    struct node *t1,*t2;
    t1=ptr1; t2=ptr2; temp=sum=NULL;
    while(t1!=NULL&&t2!=NULL){
        if(t1->powx==t2->powx && t1->powy==t2->powy){
            new_node(&sum,t1->powx,t1->powy,t1->coeff+t2->coeff);
            t1=t1->link;
            t2=t2->link;
        }
        else if(t1->powx>t2->powx ||
        (t1->powy>t2->powy && t1->powx==t2->powx)){
            new_node(&sum,t1->powx,t1->powy,t1->coeff);
            t1=t1->link;
        }
        else{
            new_node(&sum,t2->powx,t2->powy,t2->coeff);
            t2=t2->link;
        }
    }
    while(t1!=NULL){
        new_node(&sum,t1->powx,t1->powy,t1->coeff);
        t1=t1->link;
    }
    while(t2!=NULL){
       new_node(&sum,t2->powx,t2->powy,t2->coeff);
       t2=t2->link;
    }
    return sum;
}

int main(){
    struct node *poly1, *poly2;
    struct node *sum, *sub, *prod; 
    printf("\nPolynomial 1 :\n");
    create(&poly1);
    printf("\nPolynomial 2 :\n");
    create(&poly2);
    
    sum=add(poly1, poly2);
    printf("\nSum : ");
    display(sum);
    
    return 0;
}