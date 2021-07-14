#include <stdio.h>
#include <stdlib.h>

// creating structure for every node and assigning an alias name..........
typedef struct node_Structure
{
	struct node_Structure* previous;
	int data;
	struct node_Structure* next;
}node;

// declaring functions.........
node* createDoublyLinkedList(int n);
void displayDoublyLinkedList(node* head);

int main()
{
	int n;
	printf("Enter How Many Nodes You Want to Create:- ");
	scanf("%d",&n);
	node* head=NULL;
	head=createDoublyLinkedList(n);
	displayDoublyLinkedList(head);
}

node* createDoublyLinkedList(int n)
{
	node* head=NULL;
	node* temp=NULL;
	node* ptr=NULL;
	for(int i=0;i<n;i++)
	{
		// creating isolated node.......
		temp=(node*)malloc(sizeof(node));
		if(temp==NULL)
		{
			printf("Memory Can't be Allocated.\n");
		}
		else
		{
			printf("Enter The Data for Node %d:- ",i+1);
			scanf("%d",&temp->data);
			temp->previous=NULL;
			temp->next=NULL;

			if(head==NULL)		// assigning first node to head........
			{
				head=temp;
			}
			else		// linking rest nodes with head........
			{
				ptr=head;
				while (ptr->next!=NULL)
				{
					ptr=ptr->next;
				}
				ptr->next=temp;
				temp->previous=ptr;
			}
		}
	}
	return head;
}

void displayDoublyLinkedList(node* head)
{
	node* ptr=NULL;
	ptr=head;
	while (ptr!=NULL)
	{
		printf("%d <===> ",ptr->data);
		ptr=ptr->next;
	}
	printf("NULL.");
}