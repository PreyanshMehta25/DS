#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
    struct node* prev;
};

struct node *insert(struct node *head, int data) 
{
    struct node *p = head;
    while (p->next != NULL) 
    {
        p = p->next;
    }
    struct node* ptr = (struct node*)malloc(sizeof(struct node*));
    ptr->data = data;
    p->next = ptr;
    ptr->prev = p;
    return head;
}



struct node* reverse(struct node* head)
{
    struct node* temp = NULL;
    struct node* current = head;
    while(current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if(current == NULL)
    {
        head = temp->prev;
    }
    return head;
}



void printing(struct node *ptr) 
{
    struct node *p = ptr;
    while (p != NULL) 
    {
        printf("%d", p->data);
        if (p->next != NULL) 
        {
            printf(" <-> ");
        }
        p = p->next;
    }
    printf("\n");
}


int main()
{
    struct node* head = (struct node*)malloc(sizeof(struct node*));
    head->prev = NULL;
    int a = 0;
    int input;
    printf("Enter the element: ");
    scanf("%d",&input);
    printf("Current list: ");
    head->data = input;
    printing(head);
    printf("Do you want to continue?\n1)Yes\n2)No\n");
    scanf("%d",&a);
    if(a != 1)
    {
        printf("Reversed list:\n");
        printing(head);
        return 0;
    }
    do
    {
        printf("Enter the element: ");
        scanf("%d",&input);
        head = insert(head,input);
        printing(head);
        printf("Do you want to continue?\n1)Yes\n2)No\n");
        scanf("%d",&a);
    } while (a == 1);

    printf("Orignal list:\n");
    printing(head);

    head = reverse(head);

    printf("Reversed list:\n");
    printing(head);
    return 0;
}