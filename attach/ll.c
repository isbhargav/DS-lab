#include<stdio.h>
#include<stdlib.h>
#include "ll.h"


int insertdata()
{
	int d;
	printf("Enter data : ");
	scanf("%d",&d);
	return d;
}
node* createnode(int d)
{
	node* p=(node*)malloc(sizeof(node));
	if(p==NULL)
	{
		printf("Low Memory!node cannot be created");
		exit(1);
	}
	p->data=d;
	p->next=NULL;
	return p;
}

void insertbeg(node** head)
{
	node* temp=createnode(insertdata());
	temp->next=(*head);
	(*head)=temp;

}
void insertlast(node** head)
{
	if((*head)==NULL)
		(*head)=createnode(insertdata());
	else
	{

		node* temp=(*head);
		while(temp->next!=NULL)
			temp=temp->next;

		temp->next=createnode(insertdata());
	}

}
void deletebeg(node** head)
{

	if((*head)==NULL)
		printf("List is empty");
	else
	{
		node *temp=(*head);
		(*head)=((*head)->next);
		free(temp);
	}

}
void deletelast(node** head)
{
	if((*head)==NULL)
		printf("List is empty");

	else if((*head)->next==NULL)
		{
			node* temp=(*head);
			(*head)=NULL;
			free(temp);
		}
	else
	{

		node* temp=(*head);
		node* prev;
		while(temp->next!=NULL)
		{
			prev=temp;
			temp=temp->next;

		}
		prev->next=NULL;
		free(temp);
	}
}
void travel(node* head)
{
	printf("\nOUTPUT\n");
	if(head==NULL)
		printf("linkedlist empty;");
	else
		while(head!=NULL)
		{
			printf(" %d ",head->data);
			head=head->next;
		}

}
void travelreverse(node *head)
{
	if(head==NULL)
		return;
	else
           {

		travelreverse(head->next);
		printf(" %d ",head->data);
        	}

}


void insertn(node **head,int n)
{

	if((*head)==NULL)
	{
		printf("List is empty");
		return;
	}
	else if(count(*head)<n)
	{
		printf("invalid value");
		return;
	}
	else if(n==1)
		insertbeg(&(*head));
	else
	{
		node* temp=(*head);
		node* prev=temp;
		while(temp->next!=NULL && --n)
			{
				prev=temp;
				temp=temp->next;

			}
		prev->next=createnode(insertdata());
		(prev->next)->next=temp;

	}
}
void deleten(node **head,int n)
{

	if((*head)==NULL)
	{
		printf("List is empty");
		return;
	}
	else if(count(*head)<n)
	{
		printf("invalid value");
		return;
	}
	else if(n==1)
		deletebeg(&(*head));
	else
	{
		node* temp=(*head);
		node* prev=temp;
		while(--n)
			{
				prev=temp;
				temp=temp->next;

			}
		prev->next=temp->next;
		free(temp);

	}
}
int count(node* head)
{
	int c=0;
	while(head!=NULL)
		{
			c++;
			head=head->next;
		}

	return c;
}

//stack functions

stack* create_empty_stack()
{
	stack* s=(stack*)malloc(sizeof(stack));
	s->head=NULL;
	return s;
}

int enterdata()
{
	int d;
	printf("Enter data: ");
	scanf("%d",&d);
	return d;
}

void push(stack** s)
{
   insertlast(&((*s)->head));
}
void pop(stack** s)
{
	deletelast(&((*s)->head));
}
int peek(stack** s)
{
	
	node* temp=(*s)->head;
	if((*s)->head==NULL)
	{
			printf("stack empty;");
		return -999;
	}
	
	else
	{
		
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		printf(" %d ",temp->data);
		return temp->data;
	}
}

