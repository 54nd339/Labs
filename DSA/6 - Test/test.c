#include <stdio.h>  
#include <stdlib.h>    
struct node{  
    int data;  
    struct node *link;  
}*new,*temp,*out,*outt;

void new_node(struct node **head, struct node **tail, int data){
    struct node *new=malloc(sizeof(struct node));
    new->data=data; new->link=NULL;
    if(*head==NULL){
        *head=new; *tail=new;
    }
    else{
        (*tail)->link=new; *tail=new;
    }
    (*tail)->link=*head;
}
void display(struct node *ptr){  
    temp=ptr;
    if(ptr==NULL)
        printf("Empty List");
    else
        do{
            printf("%d ",temp->data);  
            temp=temp->link;  
        }while(temp!=ptr);
}
void create(struct node **head, struct node **tail){  
    printf("\nInput for 12 nos. : ");
    for(int i=0,in;i<12;i++){
        scanf("%d",&in);
        new_node(head,tail,in);
    }
    printf("I/P : ");
    display(*head);
}

void prod(struct node *ptr1,struct node *ptr2){
    struct node *t1=ptr1, *t2=ptr2;
    do{
        new_node(&out,&outt,t1->data*t2->data);
        t1=t1->link; t2=t2->link;
    }while(t1!=ptr1);
    printf("\n\nProd : ");
    display(out); 
}
void rotate(){
    int k,i; temp=out;
    printf("\nEnter roll : ");
    scanf("%d",&k); k%=10;
    for(i=1;i<k;i++)
        temp=temp->link;
    out=temp->link;
    outt=temp;
    printf("\nO/P : ");
    display(out);
}

int main(){
    struct node *h1,*t1,*h2,*t2,*h3,*t3;
    h1=t1=h2=t2=h3=t3=NULL;
    create(&h1,&t1);
    create(&h2,&t2);
    create(&h3,&t3);
    prod(h1,h3);
    outt->link=h2;
    t2->link=out;
    printf("\nMerge : ");
    display(out);
    rotate();
    return 0;
}