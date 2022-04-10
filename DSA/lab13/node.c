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
//1
int LeafCount(Tree *root){
    if(root== NULL) return 0;
    if(root->left == NULL && root->right==NULL)
        return 1;           
    else
        return LeafCount(root->left)+LeafCount(root->right);     
}
//3
int countNodes(Tree *root){
    if (root == NULL) return 0;
    else
		return (countNodes(root->right) + countNodes(root->left) + 1);
}
//4
int sumNodes(Tree *root){
    if (root == NULL) return 0;
    else
		return (sumNodes(root->right) + sumNodes(root->left) + root->data);
}
//5
int depth(Tree *node){
    if (node == NULL) return 0;
	int lheight = depth(node->left);
	int rheight = depth(node->right);
	return (lheight > rheight)? (lheight + 1) : (rheight + 1);
}
//7
void printLevel(Tree *root, int level){
    if (root == NULL) return;
    if (level == 1) printf("%d ", root->data);
    else if (level > 1) {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

int main(){
	Tree* root = NULL; int ch, in;
	printf("1. Insert Node\n2. In Order\n3. Leaf Node Count\n");
    printf("4. Non Leaf node count\n5. Count Nodes\n6. Sum of Nodes\n");
    printf("7. Depth of tree\n8. Nodes at max depth\n");
    printf("9. kth level elements\n0. Exit\n");
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
        else if(ch == 3)
            printf("Total Leaf Nodes : %d\n",LeafCount(root));
		else if(ch == 4)
            printf("Total Non-Leaf Nodes : %d\n",countNodes(root) - LeafCount(root));
		else if(ch == 5)
            printf("Total Nodes : %d\n",countNodes(root));
        else if(ch == 6)
            printf("Sum of Nodes : %d\n",sumNodes(root));
		else if(ch == 7)
            printf("Depth of the tree : %d\n",depth(root));
		else if(ch == 8){
            printf("Nodes at max depth : ");
            printLevel(root, depth(root)); printf("\n");
        }
		else if(ch == 9){
            printf("Enter a level : "); scanf("%d",&in);
            printf("Nodes at %d level : ",in);
            printLevel(root, in); printf("\n");
        }
        else if(ch == 0) break;
		else printf("Wrong Choice. ");
	}
	return 0;
}