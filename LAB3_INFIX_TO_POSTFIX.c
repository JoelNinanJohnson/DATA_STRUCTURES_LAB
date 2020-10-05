#include<stdio.h>
#include<ctype.h>

#define SIZE 50

char stack[SIZE];
int top=-1;

push(char a)
{
	stack[++top]=a;
}

char pop()
{
	return(stack[top--]);
}

int operator(char symbol)
{
	if(symbol=='^')
	{
		return(3);
	}
	else if(symbol=='*'||symbol=='/')
	{
		return(2);
	}
	else if(symbol=='+'||symbol=='-')
	{
		return (1);
	}
	else
	{
		return(0);
	}
}

int main()
{
	char infix[50],postfix[50],x,elem;
	int i=0,k=0;
	
	printf("Conversion of Infix expression to Postfix:\n\n");
	printf("Enter the infix expression: ");
	scanf("%s",infix);
	
	push('#');
	
	while((x=infix[i++])!='\0')
	{
		if(x=='(')push(x);
		else 
			if(isalnum(x))postfix[k++]=x;
			else
				if(x==')')
				{
					while(stack[top]!='(')
					{
						postfix[k++]=pop();
					}
					elem=pop();
				}
				else
				{
					while(operator(stack[top])>=operator(x))
					{	
						postfix[k++]=pop();
					}	
					push(x);
				}
	}
	while(stack[top]!='#')
		{
			postfix[k++]=pop();
		}	
	postfix[k]='\0';
	printf("\nPostfix Expression=%s\n",postfix);
	return 0;
}
