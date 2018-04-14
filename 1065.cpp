#include<iostream>
#include<string>
#include<vector>
using namespace std;

string add_string(string first, string second) // both are positive;
{
	string result = "";
	string temp;

	// swap, assue that first string is longer;
	if(first.length() < second.length())
	{
		temp = first;
		first = second;
		second = temp;
	}

	bool jinwei = false;
	for(int i=0;i<second.length();i++)
	{
		int sum = second[second.length()-1-i] -'0' + first[first.length()-1-i] - '0' + jinwei;

		if(sum < 10)
		{
			jinwei = false;
			char temp = sum + '0';
			result = temp + result;
		}
		else
		{
			jinwei = true;
			char temp = (sum-10) + '0';
			result = temp + result;
		}
	}

	for(int i=second.length();i<first.length();i++)
	{
		int sum = first[first.length()-1-i] - '0' + jinwei;

		if(sum < 10)
		{
			jinwei = false;
			char temp = sum + '0';
			result = temp + result;
		}
		else
		{
			jinwei = true;
			char temp = (sum-10)+'0';
			result = temp + result;
		}
	}

	if(jinwei == true) result = '1'+result;

	return result;
}

void compare(string first, string second)
{
	bool flag_left = false;
	if(first.length() > second.length())
	{
		flag_left = true;
	}
	else if(first.length() < second.length())
	{
		flag_left = false;
	}
	else
	{
		for(int i=0;i<first.length();i++)
		{
			if(first[i] > second[i])
			{
				flag_left = true;
				break;
			}
		}
	}

	if(flag_left==false) cout<<"false";
	else cout<<"true";
}


int main()
{
	int num;
	cin>>num;

	vector<string> first(num);
	vector<string> second(num);
	vector<string> third(num);

	vector<string> sum(num);

	for(int i=0;i<num;i++)
	{
		cin>>first[i];
		cin>>second[i];
		cin>>third[i];
	}

//	cout<<add_string("5", "99995");
//	cout<<compare("234", "123");

	for(int i=0;i<num;i++)
	{
		cout<<"Case #"<<(i+1)<<": ";
		
		string left = "0"; string right = "0";

		if(first[i][0] != '-')
		{
			left = add_string(left, first[i]);
			right = right;
		}
		else
		{
			left = left;
			right = add_string(right, first[i].erase(0,1));
		}

		if(second[i][0] != '-')
		{
			left = add_string(left, second[i]);
			right = right;
		}
		else
		{
			left = left;
			right = add_string(right, second[i].erase(0,1));
		}

		if(third[i][0] != '-')
		{
			left = left;
			right = add_string(right, third[i]);
		}
		else
		{
			left = add_string(left, third[i].erase(0,1));
			right = right;
		}

		compare(left, right);


		if(i != num-1) cout<<endl;

	}


	system("pause");
	return 0;
}