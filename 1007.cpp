#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

int main()
{
	int K;
	cin >> K;
	vector<int> sequence(K);
	for (int i = 0;i < K;i++)
	{
		cin >> sequence[i];
	}
//	cout << sequence[1];

	bool all_negative = true;
	for (int i = 0;i < K;i++)
	{
		if (sequence[i] >= 0)
		{
			all_negative = false;
			break;
		}
	}


	if (all_negative == false)
	{
		int start = 10001; int end = 10001; int max_sum = -1;
		//	int flag = 9; // add from flag, step and step till end;
		for (int flag = 0;flag < K;flag++)
		{
			int sum = sequence[flag];
			if (max_sum < sum)
			{
				max_sum = sum;
				start = flag;
				end = flag;
			}

			//	cout << start << " " <<end<< endl;

			for (int i = 1;i < K - flag;i++)
			{
				int next_sum = sum + sequence[flag + i];
				if (next_sum > max_sum)
				{
					max_sum = next_sum;
					start = flag;
					end = flag + i;
				}
				sum = next_sum;
			}
		}

		cout << max_sum << " " << sequence[start] << " " << sequence[end];
	}
	else
	{
		cout << "0" << " " << sequence[0] << " " << sequence[K - 1];
	}

	return 0;
}
