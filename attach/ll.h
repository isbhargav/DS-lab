struct node
{
	int data;
	struct node *next;

};
struct stack
{
	struct node* head;

};

//linked list functions
typedef struct node node;
typedef struct stack stack;
void insertbeg(node** head);
void insertlast(node** head);
void deletebeg(node** head);
void deletelast(node** head);
void travel(node* head);
void travelreverse(node* head);
int count(node* head);
int insertdata();
void insertn(node **head,int n);
void deleten(node **head,int n);
node* createnode(int d);
//stack functions
stack* create_empty_stack();
int enterdata();
void push(stack** s); //it will take data by it self
void pop(stack** s);
int peek(stack** s);
