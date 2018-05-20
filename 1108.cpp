#include<iostream>
#include<sstream>
#include<string.h>
#include<stdio.h>
#include<vector>
using namespace std;

int test_string(string test) // test whether a string is legal or not;
{
	bool negative = false;
	if(test[0] == '-')
	{
		negative = true;
		test.erase(0, 1);
	}

	if(test == "1000")    return -1;
	if(test == "1000.0")    return -1;
	if(test == "1000.00")    return -1;

	// check whether there is more minus;
	for(int i=0;i<test.length();i++)
	{
		if(test[i] == '-')    return 1; // 1 means there is more than 1 minus;
	}

	// check whether there is non-digit;	
	for(int i=0;i<test.length();i++)
	{
		if((isdigit(test[i]) == false) && (test[i] != '.'))    return 2; // 2 means there is non-digit;
		break;
	}

	// check whether dot at the beginning;
	if(test[0]=='.')    return 3; // 3 means dot at the beginning;

	// check whether there is more than one dot;
	int counter = 0;
	for(int i=0;i<test.length();i++)
	{
		if(test[i] == '.')    counter++;
	}
	if(counter>1)    return 4; // 4 means there is more than one dot;

	// check whether there are more than two precision;
	counter = 0;
	int position = -1;
	for(int i=0;i<test.length();i++)
	{
		if(test[i] == '.')    
		{
			position = i;
			break;
		}
	}
	if(test.length()-position-1 > 2)    return 5; // 5 means precision not correct;
	if(position == test.length()-1)    return 6; // 6 means dot at the end;


	// check whether number is beyond scope;
	double number;
	stringstream ss;
	ss<<test;
	ss>>number;
	if(number > 1000)    return 7; // 7 means number is beyond scope;



	return -1; // -1 means correct;

}


int main()
{
	int N;
	cin>>N;

	vector<string> sequence(N);
	vector<bool> legal(N);
	for(int i=0;i<N;i++)
	{
		cin>>sequence[i];
	}

//	cout<<test_string("5");	
//	cout<<test_string("aaaa"); // check whether there exist non-digit;
//	cout<<test_string("11.2.3"); // check whether there exist non-digit;	
//	cout<<test_string("11.234"); // check whether there are more than two precision;

	double sum = 0; int counter = 0;
	for(int i=0;i<N;i++)
	{
		if(test_string(sequence[i]) != -1)
		{
			cout<<"ERROR: "<<sequence[i]<<" is not a legal number"<<endl;
		}
		else
		{
			counter++;
			int signal = 1;
			if(sequence[i][0]	== '-')
			{
				signal = -1;
				sequence[i].erase(0, 1);
			}		

			double number;
			stringstream st;
			st<<sequence[i];
			st>>number;
			sum = sum + number*signal;
		}
	}

	if(counter==0) cout<<"The average of 0 numbers is Undefined";
	else if(counter == 1)
	{
		double average = sum;
		cout<<"The average of 1 number is ";
		printf("%.2f", average);
	}
	else
	{
		double average = sum / counter;
		cout<<"The average of "<<counter<<" numbers is ";
		printf("%.2f", average);
	}


	return 0;
}
