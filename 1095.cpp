#include<algorithm>
#include<iostream>
#include<map>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

struct One
{
	string plate_number;
	string time;
	string status;
};

struct Record
{
	string plate_number;
	string in_time;
	string out_time;
	string length;
};

vector<One> car_sequence;
vector<string> query_sequence;
map<string, string> cars;
vector<Record> pairs;

bool compare(One first, One second)
{
	return first.time < second.time;
}

bool compare_in(Record first, Record second)
{
	return first.in_time < second.in_time;
}

bool compare_length(Record first, Record second)
{
	if(first.length != second.length)
	{
		return first.length > second.length;
	}
	else
	{
		return first.plate_number < second.plate_number;
	}
}


void print_map()
{
	map<string, string>::iterator iter;
	iter = cars.begin();
	for(iter = cars.begin(); iter != cars.end(); iter++) {
        cout << iter->first << " : " << iter->second << endl;
    }
}

int time_to_number(string time)
{
// 18：00：01
	int hour = ((time[0]-'0')*10 + time[1]-'0')*3600;
	int minute = ((time[3]-'0')*10 + time[4]-'0')*60;
	int second = (time[6]-'0')*10 + time[7]-'0';
	int result = hour + minute + second;

	return result;
}

string number_to_time(int number)
{
	int hour = number / 3600;
	int minute = (number % 3600) / 60;
	int second = number % 60;

	string shour;
	string sminute;
	string ssecond;

	stringstream ss;
	ss<<hour;
	ss>>shour;

	stringstream st;
	st<<minute;
	st>>sminute;

	stringstream su;
	su<<second;
	su>>ssecond;

	while(shour.length()<2)    shour = "0" + shour;
	while(sminute.length()<2)    sminute = "0" + sminute;
	while(ssecond.length()<2)    ssecond = "0" + ssecond;

	string result = shour + ":" + sminute + ":" + ssecond;

	return result;
}

string time_minus(string in_time, string out_time)
{
	int chazhi = time_to_number(out_time) - time_to_number(in_time);
	string result = number_to_time(chazhi);

	return result;
}

int count_car(string time)
{
	int counter = 0;
	for(int i=0;i<pairs.size();i++)
	{
		if((pairs[i].in_time <= time)&&(pairs[i].out_time > time))
		{
			counter++;
		}
	}

	return counter;
}

int main()
{
// input process ------------------------------------------
	int N; // number of records;
	cin>>N;
	int K; // num of queries;
	cin>>K;

	for(int i=0;i<N;i++)
	{
		One temp;
		cin>>temp.plate_number;
		cin>>temp.time;
		cin>>temp.status;
		car_sequence.push_back(temp);
	}

	for(int i=0;i<K;i++)
	{
		string temp;
		cin>>temp;
		query_sequence.push_back(temp);
	}

////////////////////////////////////////////////////////////////
	sort(car_sequence.begin(), car_sequence.end(), compare);

/*
	for(int i=0;i<N;i++)
	{
		cout<<car_sequence[i].plate_number<<" "<<car_sequence[i].time<<" "<<car_sequence[i].status<<endl;
	}
*/
	
	for(int i=0;i<N;i++)
	{
		if(car_sequence[i].status=="in")
		{
			cars[car_sequence[i].plate_number] = car_sequence[i].time;
		}
		else if(car_sequence[i].status=="out")
		{
			map<string,string>::iterator it;
			it = cars.find(car_sequence[i].plate_number);

			if (it != cars.end())
			{
				Record temp;
				temp.plate_number = car_sequence[i].plate_number;
				temp.in_time = cars[car_sequence[i].plate_number];
				temp.out_time = car_sequence[i].time;
				temp.length = time_minus(temp.in_time, temp.out_time);

				pairs.push_back(temp);

    			cars.erase (it); // b被成功删除
			}
		}

//		cout<<endl;
//		print_map();
	}

/*
	for(int i=0;i<pairs.size();i++)
	{
		cout<<pairs[i].plate_number<<" "<<pairs[i].in_time<<" "<<pairs[i].out_time<<" "<<pairs[i].length<<endl;
	}
*/
//	cout<<time_to_number("01:01:01")<<endl;
//	cout<<number_to_time(3661)<<endl;
//	cout<<time_minus("01:01:01", "02:02:02");

	sort(pairs.begin(), pairs.end(), compare_in);


	// output car number in the campus;
	for(int i=0;i<K;i++)
	{
		cout<<count_car(query_sequence[i])<<endl;
	}

	// output longest car;

	sort(pairs.begin(), pairs.end(), compare_length);

	vector<Record> max;
	max.push_back(pairs[0]);
	int i=1;
	while(pairs[i].length==pairs[0].length)
	{
		max.push_back(pairs[i]);
		i++;
	}

/*
	for(int i=0;i<pairs.size();i++)
	{
		cout<<pairs[i].plate_number<<" "<<pairs[i].in_time<<" "<<pairs[i].out_time<<" "<<pairs[i].length<<endl;
	}
*/


	for(int i=0;i<max.size();i++)
	{
		cout<<max[i].plate_number<<" ";
	}
	cout<<max[0].length;

	return 0;
}










