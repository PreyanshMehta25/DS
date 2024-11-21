#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void printing(struct node *ptr)
{
    struct node *p = ptr;
    while(p != NULL)
    {
        printf("%d",p->data);
        if(p->next != NULL)
        {
            printf(" -> ");
        }
        p = p->next;
    }
    printf("\n");
}

struct node *insert(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;
    if(head == NULL)
    {
        return ptr;
    }
    struct node *temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = ptr;
    return head;
}

struct node *swap(struct node *head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    struct node *temp = head;
    struct node *prev = NULL;
    head = head->next;
    while(temp != NULL && temp->next != NULL)
    {
        struct node *n = temp->next->next;
        struct node *first = temp;
        struct node *second = temp->next;
        second->next = first;
        first->next = n;
        if(prev != NULL)
        {
            prev->next = second;
        }
        prev = first;
        temp = n;
    }
    return head;
}

int main()
{
    int elements = 0, input = 1;
    struct node *head = NULL;
    printf("Enter the element: ");
    scanf("%d",&elements);
    printf("Do you want to continue\n1)Yes\n2)No\n");
    scanf("%d",&input);
    head = insert(head, elements);
    while(input == 1)
    {
        printf("Enter the element: ");
        scanf("%d",&elements);
        head = insert(head, elements);
        printf("Do you want to continue\n1)Yes\n2)No\n");
        scanf("%d",&input);
    }
    printf("Orignal list: \n");
    printing(head);
    head = swap(head);
    printf("List after sawpping: \n");
    printing(head);
    return 0;
}

