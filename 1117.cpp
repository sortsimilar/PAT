#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

vector<int> distances;


bool compare(int a, int b)
{
	return a > b;
}

int main()
{
	int N;
	cin>>N;

	for(int i=0;i<N;i++)
	{
		int temp;
		cin>>temp;

		distances.push_back(temp);
	}


	sort(distances.begin(), distances.end(), compare);

	int result = 0;
	for(int i=0;i<distances.size();i++)
	{
		if(distances[i] > i+1)
		{
			result = i+1;
		}
	}


	cout<<result;

	return 0;
}


















