#include <stdio.h>
#include <stdlib.h>

// creating structure for every node and assigning an alias name........
typedef struct node_structure
{
	struct node_structure* previous;
	int data;
	struct node_structure* next;
}node;

// declaring functions........
node* createDoublyLinkedList(int n);
void displayDoublyLinkedList(node* head);
node* insertNode(node* head);

int main()
{
	int n;
	printf("Enter How Many Nodes You Want to Create:- ");
	scanf("%d",&n);
	node* head=NULL;
	head=createDoublyLinkedList(n);
	int option=1;
	while(option==1)
	{
		int choice;
		printf("\n1. INSERT.\n2. DISPLAY.\n3. EXIT.\n");
		printf("Enter Your Choice:- ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				head=insertNode(head);
				break;
			case 2:
				displayDoublyLinkedList(head);
				break;
			case 3:
				exit(0);
			default:
				printf("Wrong Choice.\n");
		}
		printf("\n1. YES.\n0. NO.\n");
		printf("Do You Want to Continue:- ");
		scanf("%d",&option);
	}
}

node* createDoublyLinkedList(int n)
{
	node* head=NULL;
	node* temp=NULL;
	node* ptr=NULL;
	for(int i=0;i<n;i++)
	{
		// creating isolated node..........
		temp=(node*)malloc(sizeof(node));
		if(temp==NULL)
		{
			printf("Memory can't be Allocated.\n");
		}
		else
		{
			printf("Enter The Data for Node %d:- ",i+1);
			scanf("%d",&temp->data);
			temp->previous=NULL;
			temp->next=NULL;

			if(head==NULL)
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
				temp->previous=ptr;
			}
		}
	}
	return head;
}

void displayDoublyLinkedList(node* head)
{
	printf("\n=:Current Status of Linked List:=\n");
	node* ptr=NULL;
	ptr=head;
	while (ptr!=NULL)
	{
		printf("%d <==> ",ptr->data);
		ptr=ptr->next;
	}
	printf("NULL.");
}

node* insertNode(node* head)
{
	// creating isolated node......
	node* temp=NULL;
	temp=(node*)malloc(sizeof(node));
	if(temp==NULL)
	{
		printf("Memory Can't be Allocated.\n");
	}
	else
	{
		printf("Enter The Data for New Node:- ");
		scanf("%d",&temp->data);
		temp->previous=NULL;
		temp->next=NULL;

		// going to the last node......
		node* ptr=NULL;
		ptr=head;
		while (ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=temp;
		temp->previous=ptr;
	}
	return head;
}