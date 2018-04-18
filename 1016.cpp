#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> rate(24);

int last_time(int start_HH, int start_MM, int end_HH, int end_MM)
{
	int result;

	if (start_HH == end_HH)
	{
		result = end_MM - start_MM;
	}
	else
	{
		result = -start_MM + end_MM;
		for (int i = start_HH;i < end_HH;i++)
		{
			result = result + 60;
		}
	}

	return result;
}

int calculate_time(string start, string end)
{
	int result;
	int start_DD, start_HH, start_MM;
	int end_DD, end_HH, end_MM;

	start_DD = (start[4] - '0') + (start[3] - '0') * 10;
	end_DD = (end[4] - '0') + (end[3] - '0') * 10;
	start_HH = (start[7] - '0') + (start[6] - '0') * 10;
	end_HH = (end[7] - '0') + (end[6] - '0') * 10;
	start_MM = (start[10] - '0') + (start[9] - '0') * 10;
	end_MM = (end[10] - '0') + (end[9] - '0') * 10;

	if (start_DD == end_DD)
	{
		result = last_time(start_HH, start_MM, end_HH, end_MM);
	}
	else // cross day;
	{
		result = -last_time(00, 00, start_HH, start_MM) + last_time(00, 00, end_HH, end_MM);
		for (int i = start_DD;i < end_DD;i++)
		{
			result = result + 60*24;
		}

	}

	return result;
}


int cross_hour(int start_HH, int start_MM, int end_HH, int end_MM)
{
	int result;


	if (start_HH == end_HH)
	{
		int current_price = rate[start_HH];
		result = current_price * (end_MM - start_MM);
	}
	else
	{
		result =  - start_MM * rate[start_HH] + end_MM * rate[end_HH];
		for (int i = start_HH;i < end_HH;i++)
		{
			result = result + rate[i] * 60;
		}
	}

	return result;
}

// calculate money; 
int calculate_money(string start, string end)
{
	int result;
	int start_DD, start_HH, start_MM;
	int end_DD, end_HH, end_MM;

	start_DD = (start[4] - '0') + (start[3] - '0') * 10;
	end_DD = (end[4] - '0') + (end[3] - '0') * 10;
	start_HH = (start[7] - '0') + (start[6] - '0') * 10;
	end_HH = (end[7] - '0') + (end[6] - '0') * 10;
	start_MM = (start[10] - '0') + (start[9] - '0') * 10;
	end_MM = (end[10] - '0') + (end[9] - '0') * 10;

	if (start_DD == end_DD)
	{
		result = cross_hour(start_HH, start_MM, end_HH, end_MM);
	}
	else // cross day;
	{
		int sum_day = 0;
		for (int i = 0;i < rate.size();i++)
		{
			sum_day = sum_day + rate[i]*60;
		}

		result = -cross_hour(00, 00, start_HH, start_MM) + cross_hour(00, 00, end_HH, end_MM);
		for (int i = start_DD;i < end_DD;i++)
		{
			result = result + sum_day;
		}

	}

	return result;
}







int main()
{	
	for (int i = 0;i < rate.size();i++)
	{
		cin >> rate[i];
	}

	int N;
	cin >> N;

	vector<string> name(N); vector<string> name_set;
	vector<string> time(N);
	vector<string> status(N);

	for (int i = 0;i < N;i++) 
	{
		cin >> name[i];
		cin >> time[i];
		cin >> status[i];
	}

	// find in the name_set where every name is unique; done;
	for (int i = 0;i < N;i++)
	{
		bool flag_exist = false;
		for (int j = 0;j < name_set.size();j++)
		{
			if (name[i] == name_set[j])
			{
				flag_exist = true;
				break;
			}
		}

		if (flag_exist == false)
		{
			name_set.push_back(name[i]);
		}
	}

	// sort name_set according to alphebet; done;
	sort(name_set.begin(), name_set.end());


	for (int j = 0;j < name_set.size();j++)
	{
		// creat on-set and off-set for one customer;
		vector<string> on_set, off_set;
		for (int i = 0;i < N;i++)
		{
			if (name[i] == name_set[j]) // add to j;///////////////////////
			{
				if (status[i] == "on-line")
				{
					on_set.push_back(time[i]);
				}
				else
				{
					off_set.push_back(time[i]);
				}
			}
		}

		// sort on-set and off-set; done;
		sort(on_set.begin(), on_set.end());
		on_set.push_back("99:99:99:99");
		sort(off_set.begin(), off_set.end());
		off_set.push_back("00:00:00:00");

		int p_on = 0;
		int p_off = 0;
		int counter = 0;
		double sum = 0;
		while (1)
		{
			if ((on_set[p_on] == "99:99:99:99") || (off_set[p_off] == "00:00:00:00"))
			{
				break;
			}

			if (on_set[p_on] >= off_set[p_off])
			{
				p_off++;
			}
			else if (on_set[p_on + 1] < off_set[p_off])
			{
				p_on++;
			}
			else
			{
				if (counter == 0)
				{
					cout << name_set[j] << " " << time[0][0] << time[0][1]<<endl; // change to j /////////////////////
				}
				counter++;

				string temp_on = on_set[p_on];
				string temp_off = off_set[p_off];
				temp_on.erase(0, 3);
				temp_off.erase(0, 3);

				cout << temp_on << " " << temp_off<<" "<<calculate_time(on_set[p_on], off_set[p_off]) <<" $";
				double one_fee = calculate_money(on_set[p_on], off_set[p_off]) / 100.0;
				sum = sum + one_fee;
				printf("%.2f", one_fee);
				cout << endl;

				p_off++;
				p_on++;
			}

		}

		if (counter > 0)
		{
			cout << "Total amount: $";
			printf("%.2f", sum);

			if (j != name_set.size() - 1) cout << endl;
		}
	}


	/*
	for (int i = 0;i < on_set.size();i++) cout << on_set[i] << " " << endl;
	cout << endl;
	for (int i = 0;i < off_set.size();i++) cout << off_set[i] << " " << endl;
	*/

//	cout << calculate_money("01:01:06:01", "01:01:06:03");
//	cout << calculate_money("01:01:06:01", "01:01:08:03") << endl;
//	cout << calculate_money("01:02:00:01", "01:04:23:59");
//	cout << calculate_money("01:01:05:59", "01:01:07:00");

	system("pause");
	return 0;
}