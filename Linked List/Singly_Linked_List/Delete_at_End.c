#include <stdio.h>
#include <stdlib.h>

// creating structure for every node and assigning an alias name........
typedef struct node_structure
{
	int data;
	struct node_structure* next;
}node;

// declaring functions........
node* createLinkedList(int n);
void displayLinkedList(node* head);
node* deleteNode(node* head);

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
		int choice;
		printf("\n1. DELETE.\n2. DISPLAY.\n3. EXIT.\n");
		printf("Enter Your Choice:- ");
		scanf("%d",&choice);

		switch (choice)
		{
			case 1:
				head=deleteNode(head);
				break;
			case 2:
				displayLinkedList(head);
				break;
			case 3:
				exit(0);
			default:
				printf("Wrong Choice.\n");
		}
		printf("\n1. YES.\n2. NO.\n");
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
		// creating isolated node......
		temp=(node*)malloc(sizeof(node));
		if (temp==NULL)
		{
			printf("Memory Can't be Allocated.\n");
		}
		else
		{
			printf("Enter Data for Node %d:- ",i+1);
			scanf("%d",&temp->data);
			temp->next=NULL;

			if(head==NULL)		// assigning first node to head.........
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
			}
		}
	}
	return head;
}

void displayLinkedList(node* head)
{
	printf("\n=:Current Status of Linked List:=\n");
	node* ptr=NULL;
	ptr=head;
	while (ptr!=NULL)
	{
		printf("%d --> ",ptr->data);
		ptr=ptr->next;
	}
	printf("NULL.");
}

node* deleteNode(node* head)
{
	if(head==NULL)
	{
		printf("List is Empty.\n");
	}
	else
	{
		node* ptr=NULL;

		// get previous node.......
		node* pre=NULL;
		ptr=head;
		while ((ptr->next)->next!=NULL)
		{
			ptr=ptr->next;
		}
		pre=ptr;

		// deleting last node......
		node* temp=NULL;
		temp=pre->next;
		free(temp);
		pre->next=NULL;
	}
	return head;
}