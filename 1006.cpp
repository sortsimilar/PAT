#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>

using namespace std;

int main()
{
	int M;
	cin >> M;
	vector<string> id_number(M);
	vector<string> sign_in(M);
	vector<string> sign_out(M);

	string min_sign_in = "23:59:59";
	string min_in_id;
	string max_sign_out = "00:00:00";
	string max_out_id;

	for (int i = 0;i < M;i++)
	{
		cin >> id_number[i];
		cin >> sign_in[i];
		cin >> sign_out[i];

		if (sign_in[i] < min_sign_in)
		{
			min_sign_in = sign_in[i];
			min_in_id = id_number[i];
		}

		if (sign_out[i] > max_sign_out)
		{
			max_sign_out = sign_out[i];
			max_out_id = id_number[i];
		}
	}


	cout << min_in_id<<" "<<max_out_id;

	return 0;
}
