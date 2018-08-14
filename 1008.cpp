#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int number;
	cin>>number;

	vector<int> stop;
	stop.resize(number);
	for(int i=0;i<stop.size();i++)
	{
		cin>>stop[i];
	}

	int time = 0;
	int current_location = 0;
	for(int i=0;i<number;i++)
	{
		if(stop[i] > current_location)
		{
			time = time + 6*(stop[i]-current_location);
		}
		else if(stop[i] < current_location)
		{
			time = time + 4*(current_location-stop[i]);
		}
		current_location = stop[i];
		time = time + 5;
	}

	cout<<time;

	return 0;
}
