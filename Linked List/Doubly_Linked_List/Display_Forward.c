#include <stdio.h>
#include <stdlib.h>

// creating structure for every node and assigning an alias name.......
typedef struct node_structure
{
	struct node_structure* previous;
	int data;
	struct node_structure* next;
}node;

// declaring functions.......
node* createDoublyLinkedList(int n);
void displayForward(node* head);

int main()
{
	int n;
	printf("Enter How Many Nodes You Want to Create:- ");
	scanf("%d",&n);
	node* head=NULL;
	head=createDoublyLinkedList(n);
	displayForward(head);
}

node* createDoublyLinkedList(int n)
{
	node* head=NULL;
	node* temp=NULL;
	node* ptr=NULL;
	for(int i=0;i<n;i++)
	{
		// creating isolated node........
		temp=(node*)malloc(sizeof(node));
		if(temp==NULL)
		{
			printf("Memory Can't be Allocated.\n");
		}
		else
		{
			printf("Enter Data for Node %d:- ",i+1);
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

void displayForward(node* head)
{
	node* ptr=head;
	while (ptr!=NULL)
	{
		printf("%d --> ",ptr->data);
		ptr=ptr->next;
	}
	printf("NULL.");
}