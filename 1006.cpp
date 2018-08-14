#include<iostream>
#include<string>
using namespace std;


int main()
{
	int M;
	cin >> M;	

	string min_sign_in = "23:59:59";
	string min_in_id;
	string max_sign_out = "00:00:00";
	string max_out_id;

	for (int i = 0;i < M;i++)
	{
		string id_number;
		string sign_in;
		string sign_out;

		cin >> id_number;
		cin >> sign_in;
		cin >> sign_out;

		if (sign_in < min_sign_in)
		{
			min_sign_in = sign_in;
			min_in_id = id_number;
		}

		if (sign_out > max_sign_out)
		{
			max_sign_out = sign_out;
			max_out_id = id_number;
		}
	}


	cout << min_in_id<<" "<<max_out_id;

	return 0;
}
