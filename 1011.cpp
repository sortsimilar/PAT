#include<iostream>
using namespace std;

int main()
{
	double first[3]; double first_big = 0; char first_type = 0;
	double second[3]; double second_big = 0; char second_type = 0;
	double third[3]; double third_big = 0; char third_type = 0;

	for(int i=0;i<3;i++)
	{
		cin>>first[i];
		if(first[i] > first_big)
		{
			first_big = first[i];

			if(i==0) first_type = 'W';
			else if(i==1) first_type = 'T';
			else if(i==2) first_type = 'L';


		}
	}

	for(int i=0;i<3;i++)
	{
		cin>>second[i];
		if(second[i] > second_big)
		{
			second_big = second[i];

			if(i==0) second_type = 'W';
			else if(i==1) second_type = 'T';
			else if(i==2) second_type = 'L';
		}
	}

	for(int i=0;i<3;i++)
	{
		cin>>third[i];
		if(third[i] > third_big)
		{
			third_big = third[i];

			if(i==0) third_type = 'W';
			else if(i==1) third_type = 'T';
			else if(i==2) third_type = 'L';
		}
	}

	double result = (first_big*second_big*third_big*0.65-1)*2;
	
	cout<<first_type<<" "<<second_type<<" "<<third_type<<" ";
	printf("%.2f", result);

	system("pause");
	return 0;
}