#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

vector<long long int> sequence;

int main()
{
	int N; // number of integers in the sequence;
	cin>>N;
	int p; // the parameter;
	cin>>p;

	for(int i=0;i<N;i++)
	{
		long long int temp;
		cin>>temp;
		sequence.push_back(temp);
	}

	sort(sequence.begin(), sequence.end());

/*
	for(int i=0;i<N;i++)
	{
		cout<<sequence[i]<<" ";
	}
*/

	int result = 1;
	for(int i=0;i<N;i++)
	{
		for(int j=i+result;j<N;j++)
		{
			if(sequence[j]<=sequence[i]*p)
			{
				if(j-i+1>=result)
				{
					result = j-i+1;
				}
			}
			else
			{
				break;
			}
		}
	}


	cout<<result;

	return 0;
}




