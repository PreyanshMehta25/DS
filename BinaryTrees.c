#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *right;
    struct node *left;
};

struct node *createNode(struct node *root, int data)
{
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

struct node *insert(struct node *root, int data)
{
    if(root == NULL)
    {
        return createNode(root, data);
    }
    if(data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if(data > root->data)
    {
        root->right = insert(root->right, data);
    }
    else
    {
        printf("Same number has been given before\n");
    }
    return root;
}

void inorder(struct node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void traversal(struct node *root)
{
    printf("\nInorder: ");
    inorder(root);
    printf("\n");

    printf("Preorder: ");
    preorder(root);
    printf("\n");

    printf("Postorder: ");
    postorder(root);
    printf("\n");
}

struct node *minval(struct node *root)
{
    struct node *current = root;
    while (current != NULL && current->left != NULL) 
    {
        current = current->left;
    }
    return current;
}

struct node *delete(struct node *root, int data)
{
    if(root == NULL) 
    {
        printf("Element is not in the tree\n");
        return NULL;
    }

    if(data < root->data) 
    {
        root->left = delete(root->left, data);
    }
    else if(data > root->data)
    {
        root->right = delete(root->right, data);
    } 
    else 
    {
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if(root->left == NULL)
        {
            struct node* temp1 = root->right;
            free(root);
            return temp1;
        } 
        else if(root->right == NULL) 
        {
            struct node *temp2 = root->left;
            free(root);
            return temp2;
        }
        struct node* temp = minval(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}

int main()
{
    struct node *root = NULL;
    int c;
    int e;
    while(1)
    {
        printf("\nWhat do you want to do?\n1)Insert\n2)Delete\n3)Exit\n");
        scanf("%d", &c);
        switch(c)
        {
            case 1 : 
                printf("Enter the element: ");
                scanf("%d", &e);
                root = insert(root, e);
                traversal(root);
                break;
                    
            case 2 : 
                printf("Enter the element: ");
                scanf("%d", &e);
                root = delete(root, e);
                traversal(root);
                break;

            case 3 : 
                exit(0);

            default : 
                printf("Enter valid choice\n");
        }
    }
    return 0;
}
