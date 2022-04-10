#include <stdio.h>
#include <stdlib.h>

enum marker {
    CHILD,
    THREAD
};
typedef struct tbstNode {
    int data;
    struct tbstNode *link[2];
    int marker[2];
}Tree;
Tree *createNode (int data) {
    Tree *newNode = malloc(sizeof (Tree));
    newNode->data = data;
    newNode->link[0] = newNode->link[1] = NULL;
    newNode->marker[0] = newNode->marker[1] = THREAD;
    return newNode;
}

void insertion(Tree **root, int data) {
    int path;
    if (!(*root)) {
        (*root) = createNode(data);
        return;
    }

    Tree *parent = *root;
    while (1) {
        if (data == parent->data) {
            printf("Duplicates Not Allowed\n");
            return;
        }
        path = (data > parent->data) ? 1 : 0;
        if (parent->marker[path] == THREAD)
            break;
        else
            parent = parent->link[path];
    }
    Tree *newNode = createNode(data);
    newNode->link[path] = parent->link[path];
    parent->marker[path] = CHILD;
    newNode->link[!path] = parent;
    parent->link[path] = newNode;
    return;
}

void delete(Tree **root, int data) {
    Tree *current, *parent, *temp;
    int path;

    parent = current = *root;
    while (1) {
        if (data == current->data)
            break;
        path = (data > current->data) ? 1 : 0;

        if (current->marker[path] == THREAD) {
            printf("Given data is not available!!\n");
            return;
        }

        parent = current;
        current = current->link[path];
    }

    if (current->marker[1] == THREAD) {
        if (current->marker[0] == CHILD) {
            temp = current->link[0];
            while (temp->marker[1] == CHILD) 
                temp = temp->link[1];
            temp->link[1] = current->link[1];
            if (current == (*root)) 
                (*root) = current->link[0];
            else 
                parent->link[path] = current->link[0];
        }
        else {
            if (current == (*root)) 
                (*root) = NULL;
            else {
                parent->link[path] = current->link[path];
                parent->marker[path] = THREAD;
            }
        }
    }
    else {
        temp = current->link[1];
        if (temp->marker[0] == THREAD) {
            temp->link[0] = current->link[0];
            temp->marker[0] = current->marker[0];
            if (temp->marker[0] == CHILD) {
                Tree *x = temp->link[0];
                while (x->marker[1] == CHILD)
                    x = x->link[1];
                x->link[1] = temp;
            }

            if (current == (*root))
                (*root) = temp;
            else {
                printf("path: %d data:%d\n", path, parent->data);
                parent->link[path] = temp;
            }

        }
        else {
            Tree *child;
            while (1) {
                child = temp->link[0];
                if (child->marker[0] == THREAD)
                    break;
                temp = child;
            }

            if (child->marker[1] == CHILD)
                temp->link[0] = child->link[1];
            else {
                temp->link[0] = child;
                temp->marker[0] = THREAD;
            }

            child->link[0] = current->link[0];
            if (current->marker[0] == CHILD) {
                Tree *x = current->link[0];
                while(x->marker[1] == CHILD)
                    x = x->link[1];
                x->link[1] = child;
                child->marker[0] = CHILD;
            }
            child->link[1] = current->link[1];
            child->marker[1] = CHILD;

            if (current == (*root))
                (*root) = child;
            else
                parent->link[path] = child;
        }
    }
    
    free(current);
    return;
}

void traversal(Tree *root) {
    if (!root) {
        printf("Threaded Binary Tree Not Exists!!\n");
        return;
    }

    Tree *myNode = root;
    while (1) {
        while(myNode->marker[0] == CHILD)
            myNode = myNode->link[0];
        printf("%d ", myNode->data);
        myNode = myNode->link[1];
        if (myNode) {
            printf("%d ", myNode->data);
            myNode = myNode->link[1];
        }
        if (!myNode) break;
    }
    printf("\n");
    return;
}

int main () {
    Tree *root = NULL;
    printf("1. Insertion\n2. Deletion\n");
    printf("3. Traversal\n0. Exit\n");
    int data, ch;
    while (1) {
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        if(ch == 1){
            printf("Enter your input data (-1 to exit) : ");
            while(1){
				scanf("%d", &data);
				if(data == -1) break;
				insertion(&root, data);
			}
        }
        else if(ch == 2){
            printf("Enter your input data:");
            scanf("%d", &data); delete(&root, data);
        }
        else if(ch == 3)
            traversal(root);
        else if(ch == 0) break;
        else printf("You have entered wrong option!!\n");
    }
}