#include<iostream>
#include<vector>
using namespace std;

vector<int> sequence;

int part_sum(int start, int end)
{
	int result = 0;
	for(int i=start;i<=end;i++)
	{
		result = result + sequence[i];
	}

	return result;
}




int main()
{
	int N; // total number of diamonds;
	cin>>N;
	int M; // amount that have to pay;
	cin>>M;

	for(int i=0;i<N;i++)
	{
		int temp;
		cin>>temp;
		sequence.push_back(temp);
	}


	for(int i=0;i<N;i++)
	{
		for(int j=i;j<N;j++)
		{
			if(part_sum(i, j) == M)
			{
				cout<<i+1<<"-"<<j+1<<endl;
			}
		}
	}


	return 0;
}








