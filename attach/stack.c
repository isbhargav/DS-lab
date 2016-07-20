#include<stdio.h>
#include<stdlib.h>
#define MAX 5
struct stack
{
	int arr[MAX];
	int top;
	
};
typedef struct stack stack;
int enterdata();
stack* create_empty_stack();
void push(stack** s,int d);
void pop(stack** s);
int peek(stack** s);
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
			case 2: push(&s,enterdata());
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
int enterdata()
{
	int d;
	printf("Enter data: ");
	scanf("%d",&d);
	return d;
}
stack* create_empty_stack()
{
	stack* s=(stack*)malloc(sizeof(stack));
	s->top=-1;
	return s;
}
void push(stack** s,int d)
{
	if((*s)->top==MAX-1)
		printf("Stack overflow!!\n");
	else
	{
		((*s)->top)++;
		(*s)->arr[(*s)->top]=d;
	}
}
void pop(stack** s)
{
	if((*s)->top==-1)
		printf("Stack underflow!!\n");
	else
	{
		((*s)->top)--;
	
	}
}
int peek(stack** s)
{
	if((*s)->top==-1)
		printf("Stack empty!!\n");
	else
	{
		printf("%d",(*s)->arr[(*s)->top]);
		return (*s)->arr[(*s)->top];
	}
}
