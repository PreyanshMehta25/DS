#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>
#define max 100

struct stack
{
    int stack[max];
    int top;
};

void initialise(struct stack *s)
{
    s->top = -1;
}

void push(struct stack *s, int data)
{
    if(s->top == max-1)
    {
        printf("Stack overflow\n");
        return;
    }
    s->top++;
    s->stack[s->top] = data;
}

int pop(struct stack *s)
{
    if(s->top == -1)
    {
        printf("Empty stack\n");
        return -1;
    }
    int data = s->stack[s->top];
    s->top--;
    return data;
}

int peek(struct stack *s)
{
    if(s->top == -1)
    {
        printf("Empty stack\n");
        return -1;
    }
    return s->stack[s->top];
}

int pow(int x, int y)
{
    int power;
    for(int i=1;i<=y;i++)
    {
        power = power*i;
    }
    return power;
}

int post_ans(char *exp)
{
    struct stack s;
    initialise(&s);
    for(int i = 0; i < strlen(exp); i++)
    {
        if(exp[i] >= '0' && exp[i] <= '9')
        {
            push(&s, exp[i] - '0');
        }
        else
        {
            int b = pop(&s);
            int a = pop(&s);
            int c = 0;
            switch(exp[i])
            {
                case '+': c = a + b; 
                          break;
                case '-': c = a - b;
                          break;
                case '/': c = a / b;
                          break;
                case '*': c = a * b;
                          break;
                case '^': c = pow(a, b);
                          break;

            }
            push(&s, c);
        }
    }
    return peek(&s);
}
    
int main()
{
    char exp[max];
    printf("Enter the postfix expression: ");
    scanf("%s", exp);
    printf("Final answer = %d\n", post_ans(exp));
    return 0;
}