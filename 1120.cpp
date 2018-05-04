#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int N;
	cin>>N;

	vector<string> sequence(N);

	for(int i=0;i<N;i++)
	{
		cin>>sequence[i];

	}

	vector<int> friend_number;

	for(int i=0;i<N;i++)
	{
		string temp = sequence[i];
		int sum = 0;
		for(int j=0;j<temp.length();j++)
		{
			int number = temp[j] - '0';
			sum = sum + number;
		}

		
		bool flag = false;
		for(int j=0;j<friend_number.size();j++)
		{
			if(sum == friend_number[j])
			{
				flag = true; // exist in the array;
				break;
			}
		}

		if(flag == false)    friend_number.push_back(sum);

	}

	sort(friend_number.begin(), friend_number.end());


	cout<<friend_number.size()<<endl;
	for(int i=0;i<friend_number.size();i++)
	{
		cout<<friend_number[i];
		if(i != friend_number.size()-1)    cout<<" ";
	}

	return 0;
}
