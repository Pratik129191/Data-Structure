#include<stdio.h>
#include<stdlib.h>
#define RED "\033[0;31m"
#define RESET "\033[0m"

void rotate_left_by_one(int* array, int length);
void rotate_right_by_one(int* array, int length);
void display_after_rotating_array(int* array, int length, int side);
int main()
{
	int length;
	printf("Enter the number of array elements:- ");
	scanf("%d", &length);

	int array[50];
	for (int i = 0; i < length; i++)
	{
		printf("Element Number %d is:- ", i + 1);
		scanf("%d", &array[i]);
	}

	int blocks;
	printf("How many positions you want to rotate:- ");
	scanf("%d", &blocks);

	int side;
	printf("Which side you want to rotate the array (0: LEFT & 1: RIGHT):- ");
	scanf("%d", &side);

	if (side==0)
	{
		for (int i = 0; i < blocks; i++)
		{
			rotate_left_by_one(array, length);
		}
	}
	else if (side==1)
	{
		for (int i = 0; i < blocks; i++)
		{
			rotate_right_by_one(array, length);
		}
	}
	else
	{
		printf(RED "\n\nWRONG CHOICE.\nSYSTEM TERMINATED\n\n" RESET);
	}

	display_after_rotating_array(array, length, side);
}

void rotate_left_by_one(int* array, int length)
{
	int temp;
	temp = array[0];
	for (int i = 1; i < length; i++)
	{
		array[i - 1] = array[i];
	}
	array[length - 1] = temp;
}

void rotate_right_by_one(int* array, int length)
{
	int temp;
	temp = array[length - 1];
	for (int i = length - 2; i >= 0; i--)
	{
		array[i + 1] = array[i];
	}
	array[0] = temp;
}

void display_after_rotating_array(int* array, int length, int side)
{
	if (side==0)
	{
		printf(RED "\n\n==========: After LEFT-ROTATION The Array is :==========\n\n\t" RESET);
		for (int i = 0; i < length; i++)
		{
			printf("%d\t", array[i]);
		}
		printf("\n\n");
	}
	if (side==1)
	{
		printf(RED "\n\n==========: After RIGHT-ROTATION The Array is :==========\n\n\t" RESET);
		for (int i = 0; i < length; i++)
		{
			printf("%d\t", array[i]);
		}
		printf("\n\n");
	}
}
