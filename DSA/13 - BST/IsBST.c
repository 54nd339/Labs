#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
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

int isBSTUtil(Tree* node, int min, int max) {
    if (node==NULL) return 1;
        
    if (node->data < min || node->data > max) 
        return 0; 

    return 
        isBSTUtil(node->left, min, node->data-1) &&
        isBSTUtil(node->right, node->data+1, max);
}
int main() { 
    int a, b, c, d, e;
    //4, 2, 5, 1, 3
    //1, 2, 3, 4, 5
    printf("Enter 5 ints : ");
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
    Tree *root = newNode(a); 
    root->left = newNode(b); 
    root->right = newNode(c); 
    root->left->left = newNode(d); 
    root->left->right = newNode(e); 
    
    printf(isBSTUtil(root, INT_MIN, INT_MAX)?"BST\n":"Not a BST\n");
    return 0; 
} 