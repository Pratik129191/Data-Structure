#include <iostream>
using namespace std;

int main()
{
	int row,column;
	cout<<"Enter How Many Rows are There:- ";
	cin>>row;
	cout<<"Enter How Many Columns are There:- ";
	cin>>column;
	int first_matrix[row][column];
	cout<<"\nEnter Matrix Elements..........\n"<<endl;
	cout<<"\nFor First Matrix...........\n"<<endl;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<column;j++)
		{
			cout<<"Enter Element at Index "<<"("<<i<<","<<j<<") :- ";
			cin>>first_matrix[i][j];
		}
	}
	cout<<"\nFor Second Matrix...........\n"<<endl;
	int second_matrix[row][column];
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<column;j++)
		{
			cout<<"Enter Element at Index "<<"("<<i<<","<<j<<") :- ";
			cin>>second_matrix[i][j];
		}
	}

	//doing sum...........
	int sum[row][column];
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<column;j++)
		{
			sum[i][j]=first_matrix[i][j]+second_matrix[i][j];
		}
	}

	//printing output...........
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<column;j++)
		{
			cout<<sum[i][j]<<"\t";
		}
		cout<<"\n"<<endl;
	}
}