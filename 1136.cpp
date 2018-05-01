#include<iostream>
#include<string>
using namespace std;

// test whether a string is palin or not;
bool test_palin(string test)
{
	bool flag = true;

	for(int i=0;i<test.length();i++)
	{
		if(test[i] != test[test.length()-1-i])
		{
			flag = false;
			break;
		}
	}

	return flag;
}


// inverse string;
string inverse_number(string target)
{
	string result = "";
	for(int i=0;i<target.length();i++)
	{
		result = target[i] + result;
	}

	return result;
}


// add string
string add_palin(string first)
{
	bool jinwei = false;

	string second = inverse_number(first);
	string result = "";


	int length = first.length();
	for(int i=0;i<length;i++)
	{
		int first_temp = first[length-1-i] - '0';
		int second_temp = second[length-1-i] - '0';

		int sum_temp = first_temp + second_temp + jinwei;

		if(sum_temp < 10)
		{
			char temp = sum_temp + '0';
			result = temp + result;
			jinwei = false; 
		}
		else
		{
			char temp = (sum_temp - 10) + '0';
			result = temp + result;
			jinwei = true;
		}

	}
	if(jinwei == true)    result = "1" + result;

	return result;
}

int main()
{

	string input;
	cin>>input;
	


//	cout<<test_palin(input);
//	cout<<inverse_number(input);
//	cout<<add_palin(input);

	bool flag = false;
	string temp;
	for(int i=0;i<10;i++)
	{		
		if(test_palin(input) == true)
		{
			cout<<input<<" is a palindromic number.";
			flag = true;
			break;
		}
		else
		{
			temp = add_palin(input);
			cout<<input<<" + "<<inverse_number(input)<<" = "<<temp<<endl;
			input = temp;
		}		

	}


	if(flag == false)    cout<<"Not found in 10 iterations.";


	return 0;
}
