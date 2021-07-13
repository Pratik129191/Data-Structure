#include <stdio.h>
#include <stdlib.h>

// creating structure for every node and assigning an alias name............
typedef struct node_structure
{
	int data;
	struct node_structure* next;
}node;

// declaring functions......
node* createLinkedList(int n);
void displayLinkedList(node* head);
node* insertNode(node*head);

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
		system("cls");
		int choice;
		printf("\n1. INSERT.\n2. DISPLAY.\n3. EXIT\n");
		printf("Enter Your Choice:- ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:head=insertNode(head);
				break;
			case 2:displayLinkedList(head);
				break;
			case 3:exit(0);
			default:printf("\nWrong Choice.\n");
		}
		printf("\nDo You Want to Continue?\n");
		printf("1. YES.\n0. NO.\n");
		printf("Give Opinion:- ");
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
		// creating isolated node.......
		temp=(node*)malloc(sizeof(node));
		if (temp==NULL)
		{
			printf("Memory Can't be Allocated.");
		}
		printf("Enter The Data for Node %d:- ",i+1);
		scanf("%d",&temp->data);
		temp->next=NULL;

		if (head==NULL)		// assigning first node to head.........
		{
			head=temp;
		}
		else		// linking rest nodes with head.......
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

node* insertNode(node*head)
{
	node* temp=NULL;
	temp=(node*)malloc(sizeof(node));
	if(temp==NULL)
	{
		printf("Memory Can't be Allocated for New Node.");
	}
	else
	{
		printf("Enter Data For New Node:- ");
		scanf("%d",&temp->data);
		temp->next=NULL;

		// inserting at beginning.......
		temp->next=head;
		head=temp;
	}
	return head;
}