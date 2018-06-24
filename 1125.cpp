#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>
using namespace std;

vector<double> save;

bool compare(double first, double second)
{
	return first < second;
}


int main()
{
	int N;
	cin>>N;

	for(int i=0;i<N;i++)
	{
		double temp;
		cin>>temp;
		save.push_back(temp);
	}

	sort(save.begin(), save.end(), compare);

	double sum = save[0];
	for(int i=1;i<save.size();i++)
	{
		sum = (sum + save[i]) / 2;
	}

	cout<<floor(sum);

	return 0;
}


