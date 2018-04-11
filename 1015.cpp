#include<iostream>
#include<string>
#include<sstream>
#include<cmath>
using namespace std;



bool test_prime(int number)
{	
	if(number<=1) return false;
	bool flag = true;	
	for(int i=2;i<=sqrt(number*1.0);i++)
	{
		if(number % i == 0)
		{
			flag = false;
		}
	}

	return flag;

}

int convert_system(int number, int D) 
{
	string result = ""; int current_location;
	while(number >= D)
	{
		current_location = number % D;
		char char_current_location = '0' + current_location;
		number = int (number / D);


		result = char_current_location + result;
	}
	char remain = '0' + number;
	result = remain + result;

//	return result;
	// change result to decimal;
	int decimal = 0; int weight = 1; int current_number = 0;current_location = 0;
	for(int i=0;i<result.length();i++)
	{
		current_number = result[i] - '0';
		decimal = decimal + current_number*weight;
		weight = weight*D;
	}

	return decimal;

}

int main()
{

	int first = 0;
	int second = 0;


	while(first >= 0)
	{
		cin>>first;
		if(first < 0)
		{
			break;
		}
		else
		{
			cin>>second;
			bool start = test_prime(first);
			int reversed = convert_system(first, second);
			bool final = test_prime(reversed);

			if(start&&final == true) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;

		}
	}

	system("pause");
	return 0;
}