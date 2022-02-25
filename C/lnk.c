#include<stdio.h>
#include<stdlib.h>
struct node{                                             //struct having 2 fields 
    int data;
    struct node *link;
}*head,*tail=NULL;
int main(){
    int n,i,max=0;
    printf("Enter The number of nodes : ");
    scanf("%d",&n);
    struct node *new;
    for(i=1;i<=n;i++){                                       //creating n nodes and storing data
        new = (struct node *)malloc(sizeof(struct node));
        printf("Enter Data at node %d : ",i);
        scanf("%d",&new->data);                              //takes data field from next nodes
        new->link = NULL;                                    //stores link field as null
        if(head==NULL){
            head = new; tail = new;
        }
        else{
            tail->link=new;                                  //stores the address of new at link field
            tail=new;                                        //stores new in tail
        }
    }
    printf("\nEntered data at nodes :\n");
    for(i=1;head;i++){
        printf("Data at node %d : %d\n",i,head->data);
        if(max<head->data)
        max=head->data;
        head=head->link;                                     //increment the position of node
    }
    printf("Largest Data in the list : %d\n",max);
    return 0;
}
