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

Tree* findLCA(Tree* root, int n1, int n2){
    if (root == NULL) return NULL;
    if (root->data == n1 || root->data == n2)
        return root;
 
    Tree* left_lca = findLCA(root->left, n1, n2);
    Tree* right_lca = findLCA(root->right, n1, n2);
 
    if (left_lca && right_lca) return root;
    return (left_lca != NULL) ? left_lca : right_lca;
}
int printAncestors(Tree* root, int target){
    if (root == NULL) return 0;
 
    if (root->data == target) {
        printf("%d ",root->data);
        return 1;
    }
    if (printAncestors(root->left, target) ||
        printAncestors(root->right, target)) {
        printf("%d ",root->data);
        return 1;
    }
    return 0;
}
int findCommonNodes(Tree* root, int first, int second){
    Tree* LCA = findLCA(root, first, second);
    if (LCA == NULL) return 0;
    printAncestors(root, LCA->data);
}

int main(){
	Tree* root = NULL; int ch, in;
	printf("1. Insert Node\n2. In Order\n");
    printf("3. Find Common Ancestor\n0. Exit\n");
	while(1){
		printf("\nEnter Choice : ");
		scanf("%d", &ch);
		if(ch == 1) {
			printf("Enter Data to be inserted (Exits if -1 is inserted) : ");
			while(1){
				scanf("%d", &in);
				if(in == -1) break;
				insert(&root, newNode(in));
			}
		}
		else if(ch == 2) {
			printf("Inorder traversal : ");
			printInorder(root); printf("\n");
		}
		else if(ch == 3){
            int m, n;
			printf("Enter 2 datas : ");
            scanf("%d%d",&m,&n);
            if (findCommonNodes(root, m, n) == 0)
                printf("No Common nodes");
		}
        else if(ch == 0) break;
		else printf("Wrong Choice. ");
	}
	return 0;
}