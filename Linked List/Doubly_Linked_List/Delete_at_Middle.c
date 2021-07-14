#include <stdio.h>
#include <stdlib.h>

// creating structure for every node and assigning an alias name..........
typedef struct node_structure
{
	struct node_structure* previous;
	int data;
	struct node_structure* next;
}node;

// declaring functions.........
node* createDoublyLinkedList(int n);
void displayLinkedList(node* head);
node* deleteNode(node* head, int item);

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
		printf("\n1. DELETE.\n2. DISPLAY.\n3. EXIT.\n");
		printf("Enter Your Choice:- ");
		scanf("%d",&choice);
		int item;
		switch (choice)
		{
			case 1:
				printf("Enter The Node Which You Want to Delete:- ");
				scanf("%d",&item);
				head=deleteNode(head,item);
				break;
			case 2:
				displayLinkedList(head);
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
					printf("%d",)
				}
				ptr->next=temp;
				temp->previous=ptr;
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
		printf("%d <==> ",ptr->data);
		ptr=ptr->next;
	}
	printf("NULL.");
}

node* deleteNode(node* head, int item)
{
	// going to the specified node......
	node* ptr=NULL;
	ptr=head;
	while (ptr->data!=item)
	{
		ptr=ptr->next;
	}

	// deleting node.......
	(ptr->previous)->next = ptr->next;
	(ptr->next)->previous = ptr->previous;
	free(ptr);
	return head;
}