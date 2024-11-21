#include<stdio.h>
#include<stdlib.h>

struct node
{
    char data;
    struct node *left;
    struct node *right;
};

struct node *createNode(char c)
{
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data = c;
    new->left = NULL;
    new->right = NULL;
    return new;
}

int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}



struct node* tree(char* postfix) 
{
    struct node* stack[100];
    int top = -1;
    for (int i = 0; postfix[i] != '\0'; i++) 
    { 
        if(isOperator(postfix[i])) 
        { 
            struct node* node = createNode(postfix[i]);
            node->right = stack[top--]; 
            printf("Popped element is %c\n",node->right->data); 
            node->left = stack[top--]; 
            printf("Popped element is %c\n",node->left->data);
            stack[++top] = node;
            printf("Pushed element is %c\n",node->data);
        } 
        else
        {
            stack[++top] = createNode(postfix[i]);
            printf("Pushed element is %c\n",stack[top]->data);
        }
    }
    return stack[top]; 
}

void inorder(struct node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%c ",root->data);
        inorder(root->right);
    }
}

int evaluate(struct node* root) {
    if (root->left == NULL && root->right == NULL)
        return root->data - '0';
    int left_val = evaluate(root->left);
    int right_val = evaluate(root->right);
    switch (root->data) {
        case '+':
            return left_val + right_val;
        case '-':
            return left_val - right_val;
        case '*':
            return left_val * right_val;
        case '/':
            return left_val / right_val;
        default:
            printf("Invalid operator encountered: %c\n", root->data);
            return 0;
    }
}


int main()
{
    char postfix[100];
    printf("Enter the postfix expression: ");
    scanf("%s",postfix);
    struct node *n = tree(postfix);
    printf("\nInorder: ");
    inorder(n);
    printf("\n");
    int ans = evaluate(n);
    printf("Answer to the expression is %d",ans);
    return 0;
}