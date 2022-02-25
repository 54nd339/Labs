#include <stdio.h>
#include <stdlib.h>
typedef struct Tnode {
	int data;
	struct Tnode *left, *right;
}Tree;
Tree *newNode(int data){
	Tree *node = malloc(sizeof(Tree));
	node->data = data;
	node->left = node->right = NULL;
	return node;
}
void insert(Tree **root, Tree *new){
	if(*root == NULL) *root = new;
    if(new->data < (*root)->data)
		insert(&((*root)->left), new);
	if(new->data > (*root)->data)
		insert(&((*root)->right), new);
}

void printInorder(Tree *root){
	if (root == NULL) return;
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}
void printPostorder(Tree *root){
	if (root == NULL) return;
    printPostorder(root->left);
    printPostorder(root->right);
    printf("%d ", root->data);
}
void printPreorder(Tree *root){
	if (root == NULL) return;
    printf("%d ", root->data);
    printPreorder(root->left);
    printPreorder(root->right);
}

int minValueNode(Tree *node){
    if (node && node->left != NULL)
        minValueNode(node->left);
    else return node->data;
}
int maxValueNode(Tree *node){
    if (node && node->right != NULL)
        maxValueNode(node->right);
    else return node->data;
}
int countNodes(Tree *root){
    if (root == NULL) return 0;
    else
		return (countNodes(root->right) + countNodes(root->left) + 1);
}

int main(){
	Tree* root = NULL; int ch, in;
	printf("1. Insert Node\n2. In Order\n3. Pre Order\n4. Post Order\n");
    printf("5. Smallest Element\n6. Largest Element\n7. Total Nodes\n0. Exit\n");
	while(1){
		printf("\nEnter Choice : ");
		scanf("%d", &ch);
		if(ch == 1){
			printf("Enter Data to be inserted (Exits if -1 is inserted) : ");
			while(1){
				scanf("%d", &in);
				if(in == -1) break;
				insert(&root, newNode(in));
			}
		}
        else if(ch == 2){
			printf("Inorder traversal : ");
			printInorder(root); printf("\n");
		}
        else if(ch == 3){
			printf("Preorder traversal : ");
			printPreorder(root); printf("\n");
		}
		else if(ch == 4){
			printf("Postorder traversal : ");
			printPostorder(root); printf("\n");
		}
		else if(ch == 5)
			printf("Smallest Element : %d\n",minValueNode(root));
        else if(ch == 6)
			printf("Largest Element : %d\n",maxValueNode(root));
        else if(ch == 7)
			printf("Total Nodes : %d\n",countNodes(root));
		else if(ch == 0) break;
		else printf("Wrong Choice. ");
	}
	return 0;
}