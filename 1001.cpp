#include<iostream>
#include<sstream>
#include<string>
using namespace std;


string int_to_string(int num)
{
	string result;
	stringstream ss;
	ss<<num;
	ss>>result;

	return result;
}


int main()
{
	int a;
	int b;
	cin>>a>>b;
	int sum = a+b;
	int abs = 0;
	if (sum>=0)
	{
		abs = sum;
	}
	else
	{
		abs = -sum;
		cout<<"-";
	}

	string s = int_to_string(abs);

//	cout<<s;

	string result = "";
	int counter = 0;
	for(int i=s.length()-1;i>=0;i--)
	{
		if((counter % 3 !=0) || counter==0)    result = s[i] + result;
		else  
		{
			result = "," + result;
			result = s[i] + result;
		}

		counter++;
	}

	cout<<result;

	
	return 0;
}
