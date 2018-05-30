#include<iostream>
#include<vector>

using namespace std;

int maximum;
vector<int> first;
vector<int> second;
vector<int> result;

void merge_sequence()
{
	int first_index = 0;
	int second_index = 0;
	
	first.push_back(maximum);
	second.push_back(maximum);

	while((first[first_index] != maximum) || (second[second_index] != maximum))
	{
		if (first[first_index] > second[second_index])
		{
			result.push_back(second[second_index]);
			second_index++;
		}
		else if (first[first_index] < second[second_index])
		{
			result.push_back(first[first_index]);
			first_index++;
		}
		else
		{

			result.push_back(first[first_index]);
			first_index++;
			second_index++;
		}

	}
}



int main()
{
	int N1;
	cin>>N1;
	for(int i=0;i<N1;i++)
	{
		int temp;
		cin>>temp;
		first.push_back(temp);
	}

	int N2;
	cin>>N2;
	for(int i=0;i<N2;i++)
	{
		int temp;
		cin>>temp;
		second.push_back(temp);
	}

	if(first[N1-1]<second[N2-1])    maximum = second[N2-1] + 1;
	else    maximum = first[N1-1] + 1;



	merge_sequence();


	int median_index;
	if(result.size() % 2 == 0)    median_index = result.size()/2 - 1;
	else    median_index = (result.size()-1)/2;

	cout<<result[median_index];


	return 0;
}








