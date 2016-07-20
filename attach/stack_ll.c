#include<stdio.h>
#include<stdlib.h>
#include "ll.h"
int main()
{
	
	char ch[2];
	
	int n;
	stack* s=NULL;

	do
	{
		printf("Enter your choice :\n");
		printf("1.create empty stack\n");
		printf("2.Push\n");
		printf("3.pop\n");
		printf("4.peek\n");
		
		scanf("%d",&n);
		switch(n)
		{
			case 1:	
					s=create_empty_stack();
				break;
			case 2: push(&s);
				break;
			case 3: pop(&s);
				break;
			case 4: peek(&s);
				break;
			
 			default: printf("Wrong input!!");


		}
	printf("\t\t\tdo you want to continue?(y/n):");
	scanf("%s",ch);
	}while(ch[0]=='y');

	
	
	return 0;
}
