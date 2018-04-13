#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int string_to_number(string target)
{
	int number = 0;

	stringstream ss;
	ss<<target;
	ss>>number;

	return number;
}


int main()
{


	string A, A_first, A_second, A_third;
	int A_first_number, A_second_number, A_third_number;
	string B, B_first, B_second, B_third;
	int B_first_number, B_second_number, B_third_number;
	int output_first, output_second, output_third;

	cin>>A; 
	cin>>B;

	int dot_counter = 0;
	for(int i=0;i<A.length();i++)
	{
		if(A[i] == '.')
		{
			dot_counter++;
		}
		else
		{
			if(dot_counter == 0)
			{
				A_first = A_first + A[i];
			}
			else if(dot_counter == 1)
			{
				A_second = A_second + A[i];
			}
			else
			{
				A_third = A_third + A[i];
			}
		}
	}


	dot_counter = 0;	
	for(int i=0;i<B.length();i++)
	{
		if(B[i] == '.')
		{
			dot_counter++;
		}
		else
		{
			if(dot_counter == 0)
			{
				B_first = B_first + B[i];
			}
			else if(dot_counter == 1)
			{
				B_second = B_second + B[i];
			}
			else
			{
				B_third = B_third + B[i];
			}
		}
	}


//	cout<<A_first<<" "<<A_second<<" "<<A_third;
//	cout<<B_first<<" "<<B_second<<" "<<B_third;
	bool jinwei = false;
	if(string_to_number(A_third)+string_to_number(B_third) < 29)
	{
		output_third = string_to_number(A_third)+string_to_number(B_third)+jinwei;
		jinwei = false;		
	}
	else
	{
		output_third = string_to_number(A_third)+string_to_number(B_third)+jinwei-29;
		jinwei = true;		
	}
//	cout<<output_third;

	if(string_to_number(A_second)+string_to_number(B_second)+jinwei < 17)
	{
		output_second = string_to_number(A_second)+string_to_number(B_second)+jinwei;
		jinwei = false;		
	}
	else
	{
		output_second = string_to_number(A_second)+string_to_number(B_second)+jinwei-17;
		jinwei = true;		
	}

//	cout<<output_second;

	output_first = string_to_number(A_first)+string_to_number(B_first)+jinwei;

	cout<<output_first<<"."<<output_second<<"."<<output_third;

	system("pause");
	return 0;
}