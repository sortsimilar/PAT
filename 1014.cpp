#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int N; // num of windows;
	int M; // max capacity of each line;
	int K; // num of customers;
	int Q; // num of queries;

	cin >> N; // N = 2;
	cin >> M; // M = 2;
	cin >> K;
	cin >> Q;

	vector<int> timer(N); // done time of each window after current customer;
	for (int i = 0;i < N;i++)
	{
		timer[i] = 0;
	}

	vector<int> process_time(K);
	for (int i = 0;i < K;i++) // K = 7;
	{
		cin >> process_time[i];
	}

	vector<int> done_time(K);
	vector<int> start_time(K);
	vector<int> query(Q);

	for (int i = 0;i < Q;i++)
	{
		cin >> query[i];
	}

	// I think calculate for each custom and store in done_time, then print;

	if (K > N * M) // consider customer can fill all;
	{
		int time_map[30][30];

		// first calculate done time in the yellow line;
		for (int j = 0;j < M;j++)
		{
			for (int i = 0;i < N;i++) // one row;
			{
				start_time[i + N * j] = timer[i];
				timer[i] = timer[i] + process_time[i + N * j];
				done_time[i + N * j] = timer[i];
				time_map[j][i] = timer[i];
			}
		}

		//	cout << done_time[3];


		int index = N * M;
		while (index < K)
		{

			int min_window = 0;
			int min_time = time_map[0][0];
			for (int i = 0;i < N;i++)
			{
				if (min_time > time_map[0][i])
				{
					min_window = i;
				}
			}

			// update time map, min_window column;
			for (int i = 0;i < M-1;i++)
			{
				time_map[i][min_window] = time_map[i + 1][min_window];
			}
			start_time[index] = time_map[M - 1][min_window];
			time_map[M - 1][min_window] = time_map[M - 1][min_window] + process_time[index];


			done_time[index] = time_map[M - 1][min_window];

			index = index + 1;
		}
	}
	else
	{
		int row = K / N; // 3 / 2
		int remain = K % N;
		for (int j = 0;j < row;j++)
		{
			for (int i = 0;i < N;i++) // one row;
			{
				start_time[i + N * j] = timer[i];
				timer[i] = timer[i] + process_time[i + N * j];
				done_time[i + N * j] = timer[i];
			}
		}

		for (int i = 0;i < remain;i++) // half one row;
		{
			start_time[i + N * row] = timer[i];
			timer[i] = timer[i] + process_time[i + N * row];
			done_time[i + N * row] = timer[i];
		}
	}





//	for (int i = 0;i < K;i++) cout << start_time[i] << " ";


	
	// print result;
	for (int i = 0;i < Q;i++)
	{
		if (start_time[query[i]-1] < 540)
		{
			int hour = done_time[query[i]-1] / 60 + 8;
			int minute = done_time[query[i]-1] % 60;

			if (hour < 10) cout << "0";

			cout << hour << ":";

			if (minute < 10)
			{
				cout << "0";
			}
			cout << minute;
		}
		else
		{
			cout << "Sorry";
		}
		
		if (i != Q - 1) cout << endl;
	}
	
	system("pause");
	return 0;
}