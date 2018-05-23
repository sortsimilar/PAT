#include<cmath>
#include<iostream>
#include<vector>

using namespace std;

vector<int> radix; // prime numbers; 
vector<int> exponent; // number of prime numbers;

int main()
{
	long long int number;
	cin>>number;
	
	int original = number;
	int current_prime = 2; // current prime number;

	while(current_prime <= number)
	{
		if(number % current_prime != 0)
		{
			current_prime++;
		}
		else
		{
			radix.push_back(current_prime);
			exponent.push_back(1);

			number = number / current_prime;
			while(number % current_prime == 0)
			{
				exponent[exponent.size()-1]++;
				number = number / current_prime;
			}
		
			current_prime++;
		}
	}
	


	// output result;
	cout<<original<<"=";
	if(original==1)    cout<<1;
	else
	{
		for(int i=0;i<radix.size();i++)
		{		
			cout<<radix[i];
			if(exponent[i]!=1)    cout<<"^"<<exponent[i];

			if(i!=radix.size()-1)    cout<<"*";
		}
	}

	return 0;
}
