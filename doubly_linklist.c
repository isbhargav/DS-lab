#include<stdio.h>
#include<stdlib.h>
struct node 
{
				int data;
				struct node* r,l;
};
typedef struct node node;
struct head
{
				node* start,end;
};
void insertbeg(struct head** h);
node* enterdata();
int main()
{
				struct head h;
				h.start=NULL;
				h.end=NULL;



				return 0;

}
node* enterdata()
{
				node* temp=(node*)malloc(size(node));
				printf("Enter data : ");
				scanf("%d",&temp->data);
				temp->l=NULL;
				temp->r=NULL;
				return temp;

}
void insertbeg(struct head** h)
{
				node* temp=enterdata();
				if(*h->start==NULL)
								printf("Linked list is empty!!");
				else
				{
								temp->r=*h->start;
												
				}
}
