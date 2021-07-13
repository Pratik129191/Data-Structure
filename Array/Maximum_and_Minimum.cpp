#include <iostream>
using namespace std;

class maximum_and_minimum
{
public:
	int maximum_element_is(int *array,int length);
	int minimum_element_is(int *array,int length);
};

int main()
{
	int length;
	cout<<"Enter Total Number of Array Elements:- ";
	cin>>length;
	int array[length];
	for(int i=0;i<length;i++)
	{
		cout<<"Element Number "<<i+1<<" is:- ";
		cin>>array[i];
	}
	maximum_and_minimum mam;
	int max,min;
	max=mam.maximum_element_is(array,length);
	min=mam.minimum_element_is(array,length);
	cout<<"Maximum Element is:- "<<max<<endl;
	cout<<"Minimum Element is:- "<<min<<endl;
}

int maximum_and_minimum::maximum_element_is(int *array, int length)
{
	int temp;
	temp=array[0];
	for(int i=0;i<length;i++)
	{
		if(array[i]>temp)
		{
			temp=array[i];
		}
	}
	return temp;
}

int maximum_and_minimum::minimum_element_is(int *array, int length)
{
	int temp;
	temp=array[0];
	for(int i=0;i<length;i++)
	{
		if(array[i]<temp)
		{
			temp=array[i];
		}
	}
	return temp;
}
