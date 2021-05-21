#include<stdio.h>
#include<stdlib.h>
#define RED "\033[0;31m"
#define RESET "\033[0m"

void reverse(int* array, int start, int end);
void rotate_left(int* array, int length, int count);
void rotate_right(int* array, int length, int count);
void display_array(int* array, int length, int side);

int main()
{
	int length;
	printf("Enter the number of array elements (maximum 50):- ");
	scanf("%d", &length);

	int array[50];
	for (int i = 0; i < length; i++)
	{
		printf("Element No %d is:- ", i + 1);
		scanf("%d", &array[i]);
	}

	int count;
	printf("How many positions you want to rotate:- ");
	scanf("%d", &count);

	int side;
	printf("Which side you want to rotate the array (0: LEFT & 1: RIGHT):- ");
	scanf("%d", &side);

	if (side == 0)
	{
		rotate_left(array, length, count);
	}
	else if (side == 1)
	{
		rotate_right(array, length, count);
	}
	else
	{
		printf(RED "\n\nWRONG CHOICE\nSYSTEM TERMINATED.\n\n" RESET);
	}

	display_array(array, length, side);
}

void reverse(int* array, int start, int end)
{
	while (start < end)
	{
		int temp = array[start];
		array[start] = array[end];
		array[end] = temp;
		start++;
		end--;
	}
}

void rotate_left(int* array, int length, int count)
{
	// reverse from start to the count-1 position ----
	reverse(array, 0, count - 1);
	// reverse from count to end ----
	reverse(array, count, length - 1);
	// reverse the whole ----
	reverse(array, 0, length - 1);
}

void rotate_right(int* array, int length, int count)
{
	// reverse from length-count to end ----
	reverse(array, length - count, length - 1);
	// revrse from 0 to length-count-1 ----
	reverse(array, 0, length - count - 1);
	// revese the whole array ----
	reverse(array, 0, length - 1);
}

void display_array(int* array, int length, int side)
{
	if (side == 0)
	{
		printf(RED "\n\n==========: After LEFT-ROTATION The Array is :==========\n\n\t" RESET);
		for (int i = 0; i < length; i++)
		{
			printf("%d\t", array[i]);
		}
		printf("\n\n");
	}
	if (side == 1)
	{
		printf(RED "\n\n==========: After RIGHT-ROTATION The Array is :==========\n\n\t" RESET);
		for (int i = 0; i < length; i++)
		{
			printf("%d\t", array[i]);
		}
		printf("\n\n");
	}
}
