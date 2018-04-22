#include<iostream>
#include<string>
using namespace std;

// get reversed string;
string get_reversed(string original)
{
	string reversed = "";
	for (int i = 0;i < original.length();i++)
	{
		reversed = reversed + original[original.length() - 1 - i];
	}

	return reversed;
}

// test whether is palindromic or not;
bool test_palindromic(string test)
{
	bool flag;

	string reversed = get_reversed(test);

	if (reversed == test) flag = true;
	else flag = false;

	return flag;
}

string add_reversed(string first)
{
	string second = get_reversed(first);
	string result = "";
	bool jinwei = false;

	for (int i = 0;i < first.length();i++)
	{
		int first_number = first[first.length() - 1 - i] - '0';
		int second_number = second[second.length() - 1 - i] - '0';
		if ( first_number + second_number + jinwei < 10)
		{		
			int current = first_number + second_number + jinwei;
			char current_number = current + '0';
			result = current_number + result;
			jinwei = false;
		}
		else
		{			
			int current = first_number + second_number + jinwei - 10;
			char current_number = current + '0';
			result = current_number + result;
			jinwei = true;
		}		
	}

	if (jinwei == true) result = '1' + result;


	return result;
}



int main()
{
//	cout << test_palindromic("123"); // test not jinwei;
//	cout << add_reversed("921"); // test jinwei;

	string test;
	cin >> test;
	int K;
	cin >> K;

	bool find = false;
	for (int i = 0;i < K;i++)
	{
		if (test_palindromic(test) == true)
		{
			find = true;
			cout << test << endl;
			cout << i;
			break;
		}
		else
		{
			test = add_reversed(test);
		}
	}

	if (find == false)    cout << test << endl << K;


	system("pause");
	return 0;
}