#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
    int height;
};

struct node *createNode(int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct node *node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

int getBalance(struct node *node) {
    if (node == NULL) {
        return 0;
    }
    return height(node->left) - height(node->right);
}

struct node* rightRotate(struct node *y) {
    struct node *x = y->left;
    struct node *z = x->right;

    x->right = y;
    y->left = z;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

struct node* leftRotate(struct node *x) {
    struct node *y = x->right;
    struct node *z = y->left;

    y->left = x;
    x->right = z;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

struct node *insert(struct node *n, int data) {
    if (n == NULL) {
        return createNode(data);
    }

    if (data < n->data) {
        n->left = insert(n->left, data);
    } 
    else if (data > n->data) {
        n->right = insert(n->right, data);
    }
    else {
        return n;
    }
    n->height = 1 + max(height(n->left), height(n->right));
    int bal = getBalance(n);
    if (bal > 1 && getBalance(n->left) >= 0) {
        printf("LL rotation\n");
        return rightRotate(n);
    }
    if (bal > 1 && getBalance(n->left) < 0) {
        printf("LR rotation\n");
        n->left = leftRotate(n->left);
        return rightRotate(n);
    }
    if (bal < -1 && getBalance(n->right) <= 0) {
        printf("RR rotation\n");
        return leftRotate(n);
    }
    if (bal < -1 && getBalance(n->right) > 0) {
        printf("RL rotation\n");
        n->right = rightRotate(n->right);
        return leftRotate(n);
    }

    return n;
}

void printing(struct node *n) {
    if (n != NULL) {
        printf("%d, ", n->data);
        printing(n->left);
        printing(n->right);
    }
}

int main() {
    struct node *n = NULL;
    int data;
    printf("Enter the initial root: ");
    scanf("%d", &data);
    n = createNode(data);

    int exit = 1;
    while (exit == 1) {
        printf("\nEnter the element: ");
        scanf("%d", &data);
        n = insert(n, data);
        
        printf("\nPreorder: ");
        printing(n);
        
        printf("\nDo you want to continue?\n1) yes\n2) no\n");
        scanf("%d", &exit);
    }

    return 0;
}
