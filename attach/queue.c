#include<stdio.h>
#include<stdlib.h>
#define MAX 5
struct queue
{
	int arr[MAX];
	int top;
	
};
typedef struct queue queue;
int enterdata();
queue* create_empty_queue();
void push(queue** s,int d);
void pop(queue** s);
int peek(queue** s);
int main()
{


	
	char ch[2];
	
	int n;
	queue* s=NULL;

	do
	{
		printf("Enter your choice :\n");
		printf("1.create empty queue\n");
		printf("2.Push\n");
		printf("3.pop\n");
		printf("4.peek\n");
		
		scanf("%d",&n);
		switch(n)
		{
			case 1:	
					s=create_empty_queue();
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
queue* create_empty_queue()
{
	queue* s=(queue*)malloc(sizeof(queue));
	s->top=-1;
	return s;
}
void push(queue** s,int d)
{
	if((*s)->top==MAX-1)
		printf("queue overflow!!\n");
	else
	{
		((*s)->top)++;
		(*s)->arr[(*s)->top]=d;
	}
}
void pop(queue** s)
{
	if((*s)->top==-1)
		printf("queue underflow!!\n");
	else
	{
		int i;	
		for(i=1;i<=(*s)->top;i++)
				(*s)->arr[i-1]=(*s)->arr[i];
		((*s)->top)--;
	
	}
}
int peek(queue** s)
{
	if((*s)->top==-1)
		printf("queue empty!!\n");
	else
	{
		printf("%d",(*s)->arr[0]);
	}
}
