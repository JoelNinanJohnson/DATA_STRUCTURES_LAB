#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

void push(int);
void pop();
void display();

int S[SIZE],top=-1;

int main()
{
	int x,a;
	while(1)
	{
		printf("[1]PUSH\n[2]POP\n[3]DISPLAY\n[4]EXIT\n");
		printf("----------------------------");
		printf("\nEnter Your Choice: ");
		scanf("%d",&a);
		
		switch(a)
		{
			case 1: printf("\nEnter the value to be inserted: ");
					scanf("%d",&x);
					push(x);
					break;
					
			case 2: pop();
					break;
					
			case 3: display();
					break;
					
			case 4: exit(0);
			
			default: printf("\nWrong Selection!!!Select Again!!!\n");
		}
		
	}
}

void push(int x)
{
	if(top==SIZE-1)
		printf("\nStack is Full!!!\n\n");
	else
	{
		top++;
		S[top]=x;
		printf("\nElement successsfuly Inserted!!!\n\n");
	}
}

void pop()
{
	if(top==-1)
		printf("\nStack is Empty!!!\n\n");
	else
	{
		printf("\nDeleted: %d\n\n",S[top]);
		top--;
	}
}

void display()
{
	if (top==-1)
		printf("\nStack is Empty!!!\n\n");
	else
	{
		int i;
		printf("\nStack Elements are:\n");
		for(i=top;i>=0;i--)
			printf("%d\n",S[i]);
			printf("\n\n");
	}
}
