#include<algorithm>
#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct Entry
{
	string name;
	string time;
	string status;
};

struct User
{
	string name;
	string month;
	vector<string> start_time;
	vector<string> end_time;
};



vector<Entry> entries;
vector<int> rate(24);
vector<int> rate_sum(25);
vector<User> result;
vector<User> result_other;



int calculate_time(string start, string end)
{
	int result;
	int start_DD, start_HH, start_MM;
	int end_DD, end_HH, end_MM;

	start_DD = (start[0]-'0')*10 + (start[1]-'0');
	end_DD = (end[0]-'0')*10 + (end[1]-'0');
	start_HH = (start[3]-'0')*10 + (start[4]-'0');
	end_HH = (end[3]-'0')*10 + (end[4]-'0');
	start_MM = (start[6]-'0')*10 + (start[7]-'0');
	end_MM = (end[6]-'0')*10 + (end[7]-'0');

	result = (end_DD*24*60 + end_HH*60 + end_MM) - (start_DD*24*60 + start_HH*60 + start_MM);

	return result;
}


// calculate money; 
int calculate_money(string start, string end)
{
	int result;
	int start_DD, start_HH, start_MM;
	int end_DD, end_HH, end_MM;

	start_DD = (start[0]-'0')*10 + (start[1]-'0');
	end_DD = (end[0]-'0')*10 + (end[1]-'0');
	start_HH = (start[3]-'0')*10 + (start[4]-'0');
	end_HH = (end[3]-'0')*10 + (end[4]-'0');
	start_MM = (start[6]-'0')*10 + (start[7]-'0');
	end_MM = (end[6]-'0')*10 + (end[7]-'0');

	int start_money = (start_DD-1)*rate_sum[24]*60 + rate_sum[start_HH]*60 + start_MM*rate[start_HH];
	int end_money = (end_DD-1)*rate_sum[24]*60 + rate_sum[end_HH]*60 + end_MM*rate[end_HH];

	result = end_money - start_money;

	return result;
}


bool compare(Entry a, Entry b)
{
	if(a.name != b.name)    return a.name < b.name;
	else    return a.time < b.time;
}



int main()
{	
	for(int i=0;i<rate.size();i++)
	{
		cin>>rate[i];
		rate_sum[i] = 0;
	}

	for(int i=0;i<rate.size();i++)
	{
		for(int j=i+1;j<rate_sum.size();j++)
		{
			rate_sum[j] = rate_sum[j] + rate[i];
		}
	}

	int N;
	cin>>N;
	entries.resize(N);
	
	for(int i=0;i<entries.size();i++)
	{
		cin>>entries[i].name;
		cin>>entries[i].time;
		cin>>entries[i].status;
	}

	sort(entries.begin(), entries.end(), compare);


	User temp;
	temp.name = entries[0].name;
	temp.month = entries[0].time.substr(0, 2);
	result.push_back(temp);

	for(int i=1;i<entries.size();i++)
	{
//		cout<<entries[i].name<<" "<<entries[i].time<<" "<<entries[i].status<<endl;
		
		if(entries[i].name != entries[i-1].name)
		{
			User temp;
			temp.name = entries[i].name;
			temp.month = entries[i].time.substr(0, 2);
			result.push_back(temp);
		}

		if(entries[i].name==entries[i-1].name && entries[i-1].status=="on-line" && entries[i].status=="off-line")
		{
			entries[i-1].time.erase(0, 3);
			entries[i].time.erase(0, 3);		

			result[result.size()-1].start_time.push_back(entries[i-1].time);
			result[result.size()-1].end_time.push_back(entries[i].time);
		}
	}

	for(int i=0;i<result.size();i++)
	{
		if(result[i].start_time.size() != 0)
		{
			result_other.push_back(result[i]);
		}
	}

	for(int i=0;i<result_other.size();i++)
	{
		cout<<result_other[i].name<<" "<<result_other[i].month<<endl;

		double sum = 0;

		for(int j=0;j<result_other[i].start_time.size();j++)
		{
			cout<<result_other[i].start_time[j]<<" "<<result_other[i].end_time[j]<<" ";

			cout<<calculate_time(result_other[i].start_time[j], result_other[i].end_time[j])<<" $";

			double current_fee = calculate_money(result_other[i].start_time[j], result_other[i].end_time[j]);

			printf("%.2f\n", current_fee/100.0);

			sum = sum + calculate_money(result_other[i].start_time[j], result_other[i].end_time[j]);
		}


		cout<<"Total amount: $";
		printf("%.2f", sum/100.0);

		if(i!=result_other.size()-1)    cout<<endl;
	}

/*
	for(int i=0;i<rate_sum.size();i++)
	{
		cout<<rate_sum[i]<<" ";
	}
*/

	return 0;
}


/*

10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
10
CYLL 01:01:06:01 on-line
CYLL 01:28:16:05 off-line
CYJJ 01:01:07:00 off-line
CYLL 01:01:08:03 off-line
CYJJ 01:01:05:59 on-line
aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
CYLL 01:28:15:41 on-line
aaa 01:05:02:24 on-line
aaa 01:04:23:59 off-line

*/
