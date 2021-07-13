#include <stdio.h>
#include <stdlib.h>

// creating structure for every node and assigning an alias name...........
typedef struct node_structure
{
	int data;
	struct node_structure* next;
}node;

// declaring functions.........
node* createLinkedList(int n);
void displayLinkedList(node* head);
void insertNodeAfter(int element, node* head);

int main()
{
	int n;
	printf("Enter How Many Nodes You Want to Create:- ");
	scanf("%d",&n);
	node* head=NULL;
	head=createLinkedList(n);
	int option=1;
	while (option==1)
	{
		printf("\n1. INSERT.\n2. DISPLAY.\n3. EXIT.\n");
		int choice;
		printf("Enter Your Choice:- ");
		scanf("%d",&choice);
		int element;
		switch (choice)
		{
			case 1:
				printf("After Which Node You Want to Insert:- ");
				scanf("%d",&element);
				insertNodeAfter(element,head);
				break;
			case 2:
				displayLinkedList(head);
				break;
			case 3:
				exit(0);
			default:
				printf("\nWrong Choice.\n");
		}
		printf("\n1. YES.\n0. NO.\n");
		printf("Do You Want to Continue:- ");
		scanf("%d",&option);
	}
}

node* createLinkedList(int n)
{
	node* head=NULL;
	node* temp=NULL;
	node* ptr=NULL;
	for(int i=0;i<n;i++)
	{
		// creating isolated node........
		temp=(node*)malloc(sizeof(node));
		if (temp==NULL)
		{
			printf("\nMemory Can't be Allocated.\n");
		}
		else
		{
			// taking input for nodes.......
			printf("Enter The Data for Node %d:- ",i+1);
			scanf("%d",&temp->data);
			temp->next=NULL;

			if (head==NULL)		// assigning first node to head........
			{
				head=temp;
			}
			else
			{
				ptr=head;
				while (ptr->next!=NULL)
				{
					ptr=ptr->next;
				}
				ptr->next=temp;
			}
		}
	}
	return head;
}

void displayLinkedList(node* head)
{
	printf("\n=:Current Linked List:=\n");
	node* ptr=NULL;
	ptr=head;
	while (ptr!=NULL)
	{
		printf("%d --> ",ptr->data);
		ptr=ptr->next;
	}
	printf("NULL.");
}

void insertNodeAfter(int element, node* head)
{
	node* temp=NULL;
	temp=(node*)malloc(sizeof(node));
	if(temp==NULL)
	{
		printf("\nMemory Can't be Allocated.\n");
	}
	else
	{
		printf("Enter The Data for New Node:- ");
		scanf("%d",&temp->data);
		temp->next=NULL;

		// finding the position of element........
		node* ptr=NULL;
		ptr=head;
		while(ptr->data!=element)
		{
			ptr=ptr->next;
		}

		// finding the node after element.......
		node* n_ptr=NULL;
		n_ptr=ptr->next;

		// inserting node.......
		ptr->next=temp;
		temp->next=n_ptr;
	}
}