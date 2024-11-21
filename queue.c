#include<stdio.h>
#include<stdlib.h>
#define max 15


int front1=0,rear1=-1;
int front2=5,rear2=4;
int front3=10,rear3=9;
int array[max];

void enqueue(int val, int q)
{
	int* rear;
	int* front;
	if(q == 1)
	{
		rear = &rear1;
		front = &front1;
	}
	else if(q == 2)
	{
		rear = &rear2;
		front = &front2;
	}
	else if(q == 3)
	{
		rear = &rear3;
		front = &front3;
	}
	if(*rear == (q*5-1))
	{
		printf("Queue is full");
	}
	else
	{
		*rear+=1;
		array[*rear] = val;
		printf("Element inserted = %d",array[*rear]);
	}
}

void dequeue(int q)
{
	int* rear;
	int* front;
	if(q == 1)
	{
		rear = &rear1;
		front = &front1;
	}
	else if(q == 2)
	{
		rear = &rear2;
		front = &front2;
	}
	else if(q == 3)
	{
		rear = &rear3;
		front = &front3;
	}
	if(*front > *rear)
	{
		printf("Queue is empty\n");
	}
	else
	{
		printf("Element removed = %d\n", array[*front]);
		*front += 1;
	}
}

void display()
{
	printf("The elements of the array are:");
	for(int i=0;i<max;i++)
	{
		printf("%d, ",array[i]);
	}
}

int main()
{
	int a = 1;
	while(a == 1)
	{
		int choice;
		printf("\nWhat do you want to do?\n1)queue1\n2)queue2\n3)queue3\n4)dislay\n5)exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 : 
					 printf("\nWhat do you want to do?\n1)enqueue\n2)dequeue\n");
					 int c1;
					 scanf("%d",&c1);
					 if(c1 == 1)
					 {
					 	int enq1;
					 	printf("Input value: ");
					 	scanf("%d",&enq1);
					 	enqueue(enq1,1);
					 }
					 else if(c1 == 2)
					 {
					 	dequeue(1);
					 }
					 break;
					 
			case 2 : 
					 printf("\nWhat do you want to do?\n1)enqueue\n2)dequeue\n");
					 int c2;
					 scanf("%d",&c2);
					 if(c2 == 1)
					 {
					 	int enq2;
					 	printf("Input value: ");
					 	scanf("%d",&enq2);
					 	enqueue(enq2,2);
					 }
					 else if(c2 == 2)
					 {
					 	dequeue(2);
					 }
					 break;
					 
			case 3 : 
					 printf("\nWhat do you want to do?\n1)enqueue\n2)dequeue\n");
					 int c3;
					 scanf("%d",&c3);
					 if(c3 == 1)
					 {
					 	int enq3;
					 	printf("Input value: ");
					 	scanf("%d",&enq3);
					 	enqueue(enq3,3);
					 }
					 else if(c3 == 2)
					 {
					 	dequeue(3);
					 }
					 break;
					 
			case 4 : display();
					 break;
		
			case 5 : printf("Thank you");
					 a++;
		}
	}
	return 0;
}