#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;	

};

typedef struct node node;

void insertbeg(node** head);
void insertlast(node** head);
void deletebeg(node** head);
void deletelast(node** head);
void travel(node* head);
void travelreverse(node* head);
int insertdata();
node* createnode(int d);


main()
{
	char ch[2];
	int n;
	node* head=NULL;
	
	do
	{
		printf("Enter your choice :\n");
		printf("1.create empty linked list\n");
		printf("2.Insert first\n");
		printf("3.Insert last\n");
		printf("4.Delete first\n");
		printf("5.Delete last\n");
		printf("6.travel\n");
		printf("7.travel in reverse order \n");
		scanf("%d",&n);
		switch(n)
		{
			case 1:	head=NULL;
				break;
			case 2: insertbeg(&head);
				break;
			case 3: insertlast(&head);
				break;
			case 4: deletebeg(&head);
				break;
			case 5:deletelast(&head);
				break;
			case 6:travel(head);
				break;
			case 7:travelreverse(head);
				break;
			default: printf("Wrong input!!");


		}
	printf("\t\t\tdo you want to continue?(y/n):");
	scanf("%s",ch);	
	}while(ch[0]=='y');

}
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
			(*head)==NULL;
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
			
	else if(n==1)
		deletebeg(&(*head));
	else
	{
		node* temp=(*head);
		node* prev=temp;	
		while(--n)
			{	
				while(temp->next!=NULL) 
					{
						prev=temp;
						temp=temp->next;
					}
			}
		prev->next=createnode(insertdata());
		(prev->next)->next=temp;

	}
}
