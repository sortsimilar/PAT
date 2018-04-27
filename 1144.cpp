#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int N;
	cin>>N;
	vector<int> sequence(N);
	for(int i=0;i<N;i++)
	{
		cin >> sequence[i];
	}

	sort(sequence.begin(), sequence.end());
	
	int result = 0;
	bool flag_one = false;
	int position = 0;
	for(int i=0;i<N;i++)
	{
		if(sequence[i] == 1)
		{
			flag_one = true;
			position = i;
			break;
		}
	}

	if(flag_one == false) result = 1;
	else
	{
		bool miss_middle = false;
		for(int i=position;i<N-1;i++)
		{
			if(sequence[i+1] - sequence[i] > 1)
			{
				result = sequence[i] + 1;
				miss_middle = true;
				break;
			}			
		}

		if(miss_middle == false)    result = sequence[N-1]+1;


	}



	cout<<result;

	return 0;
}
