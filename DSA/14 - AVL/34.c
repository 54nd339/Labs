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

int isIdentical(Tree *root1, Tree *root2){
    if (root1 == NULL && root2 == NULL)
        return 1;
    else if (root1 != NULL && root2 == NULL)
        return 0;
    else if (root1 == NULL && root2 != NULL)
        return 0;
    else {
        if (root1->data == root2->data && isIdentical(root1->left, root2->left)
            && isIdentical(root1->right, root2->right))
            return 1;
        else
            return 0;
    }
}

void merge(Tree* root1, Tree* root2) {
    if (!root1 && !root2) return;
    if (!root1) {
        printInorder(root2);
        return;
    }
    if (!root2) {
        printInorder(root1);
        return;
    }

    Tree *temp1 = root1, *prev1 = NULL;
    while (temp1->left) {
        prev1 = temp1;
        temp1 = temp1->left;
    }
    Tree *temp2 = root2, *prev2 = NULL;
    while (temp2->left) {
        prev2 = temp2;
        temp2 = temp2->left;
    }

    if (temp1->data <= temp2->data) {
        printf("%d ",temp1->data);
        if (prev1 == NULL)
            merge(root1->right, root2);
        else {
            prev1->left = temp1->right;
            merge(root1, root2);
        }
    }
    else {
        printf("%d ",temp2->data);
        if (prev2 == NULL)
            merge(root1, root2->right);
        else {
            prev2->left = temp2->right;
            merge(root1, root2);
        }
    }
}

int main(){
	Tree *root1 = NULL, *root2 = NULL; int ch, in;
	printf("1. Insert Node at tree 1\n2. Insert Node at tree 2\n");
    printf("3. Display Trees\n4. Check Similarity\n5. Merge BSTs\n0. Exit\n");
	while(1){
		printf("\nEnter Choice : ");
		scanf("%d", &ch);
		if(ch == 1){
			printf("Enter Data to be inserted (Exits if -1 is inserted) : ");
			while(1){
				scanf("%d", &in);
				if(in == -1) break;
				insert(&root1, newNode(in));
			}
		}
        else if(ch == 2){
			printf("Enter Data to be inserted (Exits if -1 is inserted) : ");
			while(1){
				scanf("%d", &in);
				if(in == -1) break;
				insert(&root2, newNode(in));
			}
		}
        else if(ch == 3){
			printf("Inorder traversal of Tree 1 : ");
			printInorder(root1); printf("\n");
            printf("Inorder traversal of Tree 2 : ");
			printInorder(root2); printf("\n");
		}
        else if(ch == 4){
            if (isIdentical(root1, root2))
                printf("Both BSTs are identical\n");
            else
                printf("BSTs are not identical\n");
		}
        else if(ch == 5){
            merge(root1, root2);
        }
        else if(ch == 0) break;
		else printf("Wrong Choice. ");
	}
	return 0;
}