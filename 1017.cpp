#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
using namespace std;

struct Person
{
	// clock;
	int arrive_time;
	int serve_time;
	int finish_time;
	int wait_time;

	// length
	int process_time;
};

int string_to_int(string time)
{
	int result;

	int hour = (time[0] - '0') * 10 + time[1] - '0';
	int minute = (time[3] - '0') * 10 + time[4] - '0';
	int second = (time[6] - '0') * 10 + time[7] - '0';

	result = 60 * 60 * hour + 60 * minute + second;


	return result;
}

vector<Person> sequence; // sequence store input;


bool compare_arrive(Person first, Person second)
{
	return first.arrive_time < second.arrive_time;
}




int main()
{
	int N; // total number of customers;
	cin >> N;
	int K; // num of windows;
	cin >> K;

	vector<int> window_finish(K);

	for (int i = 0;i < N;i++)
	{

		string arrive_time;
		cin>>arrive_time;
		int process_time;
		cin>>process_time;

		Person temp;
		temp.arrive_time =string_to_int(arrive_time);
		temp.process_time = process_time;

		sequence.push_back(temp);
	}

	// sort customers;
	sort(sequence.begin(), sequence.end(), compare_arrive);

	int start = string_to_int("08:00:00");
	int end = string_to_int("17:00:00");

	// the queue store K's finish time;
	for (int i = 0;i < K;i++)
	{
		window_finish[i] = start;
	}
	

	double wait_sum = 0; int counter = 0;
	for (int i = 0;i < N;i++)
	{	
		if (sequence[i].arrive_time > end) break;

		int min_finish = window_finish[0];
		int window = 0;
		for (int j = 0;j < K;j++)
		{
			if (min_finish >= window_finish[j]) // find the minimum window to wait;
			{
				min_finish = window_finish[j];
				window = j;
			}
		}
		

		if (sequence[i].arrive_time <= min_finish) // if arrive early, must wait;
		{
			sequence[i].serve_time = min_finish;
			sequence[i].wait_time = min_finish - sequence[i].arrive_time;
		}
		else // if arrive late, then directly;
		{
			sequence[i].serve_time = sequence[i].arrive_time;
			sequence[i].wait_time = 0;
		}

		wait_sum = sequence[i].wait_time + wait_sum;
		counter++;
		if (sequence[i].process_time <= 3600)
		{
			sequence[i].finish_time = sequence[i].serve_time + sequence[i].process_time * 60;
		}
		else
		{
			sequence[i].finish_time = sequence[i].serve_time + 3600;
		}
		window_finish[window] = sequence[i].finish_time;
	}

/*	
	for (int i = 0;i < N;i++)
	{
		cout << sequence[i].serve_time <<" "<<sequence[i].finish_time<<" "<<sequence[i].wait_time<<endl;
	}
*/

	if (counter != 0)
	{
		double result = wait_sum / (counter*60.0);
		printf("%.1f", result);
	}
	else
	{
		cout << "0.0";
	}


	return 0;
}
