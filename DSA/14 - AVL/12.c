#include<stdio.h>
#include<stdlib.h>

typedef struct TNode{
	int key, height;
	struct TNode *left, *right;
}AVL;
AVL* newNode(int key){
	AVL* node = malloc(sizeof(AVL));
	node->key = key; node->height = 1;
	node->left = node->right = NULL;
	return(node);
}

int max(int a, int b){
    return a>b?a:b;
}
int height(AVL *N) {
	if (N == NULL) return 0;
	return N->height;
}
AVL *rightRotate(AVL *y) {
	AVL *x = y->left;
	AVL *T2 = x->right;

	x->right = y;
	y->left = T2;

	y->height = max(height(y->left), height(y->right))+1;
	x->height = max(height(x->left), height(x->right))+1;

	return x;
}
AVL *leftRotate(AVL *x) {
	AVL *y = x->right;
	AVL *T2 = y->left;

	y->left = x;
	x->right = T2;

	x->height = max(height(x->left), height(x->right))+1;
	y->height = max(height(y->left), height(y->right))+1;

	return y;
}
int getBalance(AVL *N) {
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}
AVL *balance(AVL *root){
    int balance = getBalance(root);
    //4 cases
    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0){
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
} 
AVL* insert(AVL* root, int key) {
	if (root == NULL)
		return(newNode(key));

	if (key < root->key)
		root->left = insert(root->left, key);
	else if (key > root->key)
		root->right = insert(root->right, key);
	else
		return root;

	root->height = 1 + max(height(root->left), height(root->right));
    root = balance(root);

	return root;
}

AVL *minValueNode(AVL *node) {
    AVL *current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}
AVL* deleteNode(AVL* root, int key) {
    if (root == NULL) return root;
 
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if(key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if((root->left == NULL) || (root->right == NULL)) {
            AVL *temp = root->left ? root->left : root->right;
 
            if (temp == NULL) {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            free(temp);
        }
        else {
            AVL *temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }
    if (root == NULL) return root;
 
    root->height = 1 + max(height(root->left), height(root->right));
    root = balance(root);
 
    return root;
}

void inOrder(AVL *root) {
	if(root == NULL) return;
    inOrder(root->left);
    printf("%d ", root->key);
    inOrder(root->right);
}

int main() {
    AVL *root = NULL; int ch, in;
    printf("\n1. Insert \n2. Display");
    printf("\n3. Delete \n0. Exit \n");
    while (1){
        printf("\nEnter Your Choice : ");
        scanf("%d", &ch);
        if (ch == 1){
            printf("Enter Data to be inserted (Exits if -1 is inserted) : ");
			while(1){
				scanf("%d", &in);
				if(in == -1) break;
				root = insert(root, in);
			}
        }
        else if (ch == 2){
            printf("inorder traversal : ");
            inOrder(root); printf("\n");
        }
        else if (ch == 3){
            printf("Enter Data to be deleted : ");
            scanf("%d", &in);
			root = deleteNode(root, in);
        }
        else if (ch == 0) break;
        else printf("Wrong Input.");
    }
    //9 5 10 0 6 11 -2 1 2
    /* The constructed AVL Tree would be
            9
           /  \
          1    10
        /  \     \
       0    5     11
      /    /  \
     -2   2    6
    */
 
    /* The AVL Tree after deletion of 10
            1
           /  \
          0    9
        /     /  \
       -2    5     11
           /  \
          2    6
    */
   return 0;
}