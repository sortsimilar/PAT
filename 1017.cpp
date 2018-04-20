#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int stringtoint(string time)
{
	int result;

	int hour = (time[0] - '0') * 10 + time[1] - '0';
	int minute = (time[3] - '0') * 10 + time[4] - '0';
	int second = (time[6] - '0') * 10 + time[7] - '0';

	result = 60 * 60 * hour + 60 * minute + second;


	return result;
}


int main()
{
	int N; // total number of customers;
	cin >> N;
	int K; // num of windows;
	cin >> K;

	vector<int> arrive_time(N), arrive_sort(N), serve_time(N), finish_time(N), wait_time(N);
	vector<int> process_time(N), process_sort(N);
	vector<int> window_finish(K);

	for (int i = 0;i < N;i++)
	{
		string temp;
		cin >> temp;
		arrive_time[i] = stringtoint(temp);
		cin >> process_time[i];
	}

	int start = stringtoint("08:00:00");
	int end = stringtoint("17:00:00");

	// sort arrive time;
	for (int i = 0;i < N;i++)
	{
		arrive_sort[i] = arrive_time[i];
		process_sort[i] = process_time[i];
	}
	sort(arrive_sort.begin(), arrive_sort.end());

	// sort process time corresponding to arrive time;
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < N;j++)
		{
			if (arrive_sort[i] == arrive_time[j])
			{
				process_sort[i] = process_time[j];
			}
		}
	}

	// the queue store K's finish time;
	for (int i = 0;i < K;i++)
	{
		window_finish[i] = start;
	}
	

	// suppose no customers come before 7;
	double wait_sum = 0; int counter = 0;
	for (int i = 0;i < N;i++)
	{	
		if (arrive_sort[i] > end) break;

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
		

		if (arrive_sort[i] <= min_finish) // if arrive early, must wait;
		{
			serve_time[i] = min_finish;
			wait_time[i] = min_finish - arrive_sort[i];
		}
		else // if arrive late, then directly;
		{
			serve_time[i] = arrive_sort[i];
			wait_time[i] = 0;
		}

		wait_sum = wait_time[i] + wait_sum;
		counter++;
		if (process_sort[i] <= 3600)
		{
			finish_time[i] = serve_time[i] + process_sort[i] * 60;
		}
		else
		{
			finish_time[i] = serve_time[i] + 3600;
		}
		window_finish[window] = finish_time[i];
	}

	/*
	for (int i = 0;i < N;i++)
	{
		cout << serve_time[i] <<" "<<finish_time[i]<<" "<<wait[i]<<endl;
	}*/

	if (counter != 0)
	{
		double result = wait_sum / (counter*60.0);
		printf("%.1f", result);
	}
	else
	{
		cout << "0.0";
	}


	

	system("pause");
	return 0;
}