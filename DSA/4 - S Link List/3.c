#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
}*head;
    
void display(){
    if(head==NULL){
        printf("Empty List\n");return;
    }
    struct node *temp=head;
    printf("List : ");
    while(temp){
        printf("%d ",temp->data);
        temp=temp->link;
    }
}
void create(){
    struct node *temp,*new; int in;
    printf("Input (-1 to exit) : ");
    while(1){
        scanf("%d",&in);
        if(in==-1) break;
        new=(struct node *)malloc(sizeof(struct node));    
        new->data = in; new->link = NULL;
        if(head == NULL) {
            head = new; temp = new;
        }
        else{
            temp->link = new; temp = new;
        }
    }
    display();
}
void isnull(){
    printf(head==NULL?"null":"not empty");
}
void insbeg(){
	struct node* new = malloc(sizeof(struct node));
	printf("Enter data : ");
	scanf("%d",&new->data);
	new->link = head;
	head = new;
    display();
}
void insend(){
	struct node *temp, *new = malloc(sizeof(struct node));
	printf("Enter data : ");
	scanf("%d", &new->data);
    new->link=NULL; temp=head;
	while(temp->link) temp=temp->link;
	temp->link=new;
    display();
}
void delbeg(){
	struct node* temp;
	if (head==NULL)
		printf("\nList is empty\n");
	else {
		temp=head;
		head=head->link;
		free(temp);
	}
    display();
}
void delend(){
	struct node *temp, *prev;
	if (head == NULL)
		printf("\nList is Empty\n");
	else {
		temp=head;
		while (temp->link) {
			prev=temp;
			temp=temp->link;
		}
		free(temp);
		prev->link = NULL;
	}
    display();
}
void count(){
    int c=0;
    struct node *temp=head;
    while(temp){
        c++;
        temp=temp->link;
    }
    printf("Count : %d",c);
}
void oddeve(){
    int co=0,ce=0;
    struct node *temp=head;
    while(temp){
        int n=temp->data;
        (n%2)? co++ : ce++;
        temp=temp->link;
    }
    printf("No. of odd elements : %d", co);
    printf("\nNo. of even elements : %d", ce);
}
int isPrime(int n,int i){
    if(n==2 || i*i>n) return 1;
    if(n>1 && n%i) return 0;
    return isPrime(n,i+1);
}
void prime(){
    int c=0;
    struct node *temp=head;
    while(temp){
        if(isPrime(temp->data,2))
            c++;
        temp=temp->link;
    }
    printf("No. of prime elements : %d", c);
}
int isPalin(struct node **left, struct node *right){
    if (right==NULL) return 1;
    int result=isPalin(left, right->link) && ((*left)->data==right->data);
    (*left)=(*left)->link; 
    return result;
}
int main(){
    int n=0,ch;
    printf("\n1. Create link list");
    printf("\n2. Traverse the list");
    printf("\n3. Check if list is empty");
    printf("\n4. Insert a node at beginning");
    printf("\n5. Delete a node at beginning");
    printf("\n6. Insert a node at end");
    printf("\n7. Delete a node at end");
    printf("\n8. Count no. of elements");
    printf("\n9. Count no. of odd & even element");
    printf("\n10. Count Prime Nos.");
    printf("\n11. Check Palindrome");
    printf("\n0. Exit");
    while(1){
        printf("\n\nEnter your choice : ");
        scanf("%d",&ch);
        if(ch==1) create();
        else if(ch==2) display();
        else if(ch==3) isnull();
        else if(ch==4) insbeg();
        else if(ch==5) delbeg();
        else if(ch==6) insend();
        else if(ch==7) delend();
        else if(ch==8) count();
        else if(ch==9) oddeve();
        else if(ch==10) prime();
        else if(ch==11) printf(isPalin(&head,head)?"Palindrome":"Not Palindrome");
        else if(ch==0) break;
        else printf("Wrong Input\n");
    }
    return 0;
}//Sandeep 20051025