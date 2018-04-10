

#include<iostream>

using namespace std;

int main()
{
	float first[1001];
	float second[1001];
	float output[1001];

	for(int i=0;i<1001;i++)
	{
		first[i] = 0;
		second[i] = 0;
		output[i] = 0;
	}

	// get input/////////////////////////////
	int current_exponent;

	int size_first;
	cin>>size_first;
	for(int i=0;i<size_first;i++)
	{
		cin>>current_exponent;
		cin>>first[current_exponent];
	}

	int size_second;
	cin>>size_second;
	for(int i=0;i<size_second;i++)
	{
		cin>>current_exponent;
		cin>>second[current_exponent];
	}

	// do addition;/////////////////////////
	int count_not_zero = 0;
	for(int i=0;i<1001;i++)
	{
		output[i] = first[i] + second[i];
		if(output[i] != 0)
		{
			count_not_zero++;
		}
	}
	// do output;/////////////////////////
	
	cout<<count_not_zero;
	if(count_not_zero != 0)
	{
		cout<<" ";
	}
	for(int i=1000;i>=0;i--)
	{
		if(output[i] != 0 && count_not_zero>=0)
		{
			cout<<i<<" ";
			printf("%.1f", output[i]);
			count_not_zero--;
			if(count_not_zero > 0)
			{
				cout<<" ";
			}
		}
	}
	

	system("pause");
	return 0;
}

