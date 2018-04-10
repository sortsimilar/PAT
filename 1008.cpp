#include<iostream>
using namespace std;

int main()
{
	int number;
	int stop[100];

	cin>>number;
	for(int i=0;i<number;i++)
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

	system("pause");
	return 0;
}