#include<stdlib.h>
#include<stdio.h>

struct node 
{
	int key;
	struct node *left;
	struct node *right;
};
struct node *root; 

struct node *create(int data)
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->key = data;
	temp->left = temp->right = NULL;
	return temp;
}

void insert(struct node *root,struct node *temp)
{
	if(temp->key < root->key)
	{
		if(root->left != NULL)
		{
			insert(root->left,temp);
		}
		else
		{
			root->left = temp;
		}
	}
	if(temp->key > root->key)
	{
		if(root->right != NULL)
		{
			insert(root->right,temp);
		}
		else
		{
			root->right = temp;
		}
	}
}

struct node *Max(struct node *root)
{
        if(root == NULL)
        {
			return NULL;
        }
        else if(root->right == NULL)
        {
			return root;
        }
        else
        {
			return Max(root->right);
		}
}

void display(struct node *root)
{
	if(root != NULL)
	{
		display(root->left);
		printf("%d\t",root->key);
		display(root->right);
	}
}

int main()
{
	char ch;
	struct node *temp;
	root = NULL;
	int choice = 0;
	int data;
	
	while(1)
	{
		printf("\n\n*****************MENU****************\n");
		printf("Choose an option from the list:");
		printf("\n[1]CREATE A TREE\n[2]FIND MAX VALUE\n[3]DISPLAY\n[4]EXIT\n");
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: do{
						printf("\nEnter the value:");
						scanf("%d",&data);
						temp = create(data);
						if(root == NULL)
						{
							root = temp;
						}
						else
						{
							insert(root,temp);
						}
						printf("\nDo you Want to Enter more(Y/N)? ");
						getchar();
						scanf("%c",&ch);
					}while(ch=='y'||ch=='Y');
					break;
			
			case 2: root = Max(root);
					if(root != NULL)
					{
						printf("\nMaximum is %d\n", root->key);
					}
					break;
			
			case 3: display(root);
					break;
					
			case 4: exit(1);
			 
			default:
				printf("\nINVALID CHOICE!!!\n");								
		}
	}
	return 0;
}

