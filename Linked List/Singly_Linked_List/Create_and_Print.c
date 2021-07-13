#include <stdio.h>
#include <stdlib.h>

// creating structure for every node and assigning an alias name............
typedef struct node_structure
{
	int data;
	struct node_structure* next;
}node;

// declaring functions.........
node* createLinkedList(int n);
void display(node* head);

int main()
{
	int n;
	printf("Enter How Many Node You Want to Create:- ");
	scanf("%d",&n);

	node* head=NULL;
	head=createLinkedList(n);
	display(head);
}

node* createLinkedList(int n)
{
	node* head=NULL;
	node* temp=NULL;
	node* ptr=NULL;
	for(int i=0;i<n;i++)
	{
		// creating isolated node..........
		temp=(node*)malloc(sizeof(node));
		if (temp==NULL)
		{
			printf("Memory Can't be Allocated.");
		}
		printf("Enter The Data for Node %d:- ",i+1);
		scanf("%d",&temp->data);
		temp->next=NULL;

		if(head==NULL)	// assigning first node to head.......
		{
			head=temp;
		}
		else	// linking rest nodes to head........
		{
			ptr=head;
			while (ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			ptr->next=temp;
		}
	}
	return head;
}

void display(node* head)
{
	node* ptr=NULL;
	ptr=head;
	while (ptr!=NULL)
	{
		printf("%d --> ",ptr->data);
		ptr=ptr->next;
	}
	printf("NULL.");
}