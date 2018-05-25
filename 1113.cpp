#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;


vector<int> sequence;

bool compare(int a, int b)
{
	return a>b;
}

int absolute(int number)
{
	if(number>0)    return number;
	else    return (0-number);
}




int main()
{
	int N;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		int temp;
		cin>>temp;
		sequence.push_back(temp);
	}	

	sort(sequence.begin(), sequence.end(), compare);

	int sum_first = 0;
	int counter_first = 0;
	int sum_second = 0;
	int counter_second = 0;

	if(N%2==0)
	{		
		for(int i=0;i<N/2;i++)    sum_first += sequence[i];
		for(int i=N/2;i<N;i++)    sum_second += sequence[i];

		cout<<"0"<<" "<<absolute(sum_first - sum_second);

	}
	else
	{		
		for(int i=0;i<(N+1)/2;i++)    sum_first += sequence[i];
		for(int i=(N+1)/2;i<N;i++)    sum_second += sequence[i];

		cout<<"1"<<" "<<absolute(sum_first - sum_second);

	}	


	return 0;
}
