#include<stdio.h>
#define SIZE 100

struct student
{
	int id;
	int age;
	int marks;
};


int main()
{
	struct student s[SIZE];
	int i,n;
	
	printf("Please enter the number of students:");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("\nEnter the student id:");
		scanf("%d",&s[i].id);
		printf("Enter the age of the student:");
		scanf("%d",&s[i].age);
		printf("Enter the marks of the student:");
		scanf("%d",&s[i].marks);
	}
	
	printf("\n\nDetails of qualified students are:");
	for(i=0;i<n;i++)
	{
		
			if(s[i].age>20&&s[i].marks>=65&&s[i].marks<=100)
			{
				printf("\n\nStudent ID:\t%d",s[i].id);
				printf("\nStudent age:\t%d",s[i].age);
				printf("\nStudent marks:\t%d",s[i].marks);
			}
			
	}
	return 0;
}
