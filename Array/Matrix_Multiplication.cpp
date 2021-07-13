#include <iostream>
using namespace std;
int main()
{
	cout<<"\nThe number of COLUMN's of the first matrix must be equal to the number of ROW's of the second matrix.\n"<<endl;
	cout<<"\nFor First Matrix...........\n"<<endl;
	int row1;
	cout<<"Enter The Number of ROW's:- ";
	cin>>row1;
	int column1;
	cout<<"Enter The Number of COLUMN's:- ";
	cin>>column1;
	int first_matrix[row1][column1];
	cout<<"\nEnter Matrix Elements..........\n"<<endl;
	for(int i=0;i<row1;i++)
	{
		for(int j=0;j<column1;j++)
		{
			cout<<"Enter Element at Index "<<"("<<i<<","<<j<<") :- ";
			cin>>first_matrix[i][j];
		}
	}

	cout<<"\nFor Second Matrix...........\n"<<endl;
	int row2;
	cout<<"Enter The Number of ROW's:- ";
	cin>>row2;
	int column2;
	cout<<"Enter The Number of COLUMN's:- ";
	cin>>column2;
	int second_matrix[row2][column2];
	cout<<"\nEnter Matrix Elements..........\n"<<endl;
	for(int i=0;i<row2;i++)
	{
		for(int j=0;j<column2;j++)
		{
			cout<<"Enter Element at Index "<<"("<<i<<","<<j<<") :- ";
			cin>>second_matrix[i][j];
		}
	}

	// operation..........
	int mul[row1][column2];
	int out_row=0,out_column=0;

	for(int i=0;i<row1;i++)
	{
		for(int j=0;j<column1;j++)
		{
			int temp=0;
			for(int k=0;k<column2;k++)
			{
				temp=temp+(first_matrix[i][k] * second_matrix[k][j]);
			}
			mul[out_row][out_column]=temp;
			out_column++;
		}
		out_row++;
	}

	// output.........
	for (int i = 0; i <row1 ; ++i)
	{
		for (int j = 0; j <column2 ; ++j)
		{
			cout<<mul[i][j]<<"\t";
		}
		cout<<endl;
	}
}