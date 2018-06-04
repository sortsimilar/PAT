#include<iostream>
#include<sstream>
#include<string>
using namespace std;

long long int N;

long long int count_one(int position) // the position count from right;
{
// calculate divisor;
	long long int divisor = 1;
	for(int i=0;i<position+1;i++)
	{
		divisor = divisor * 10;
	}

	long long int quotient = N / divisor;
	long long int remain = N % divisor;

	long long int quotient_part = quotient * divisor / 10;
	long long int remain_part;
	if(remain < divisor/10)
	{
		remain_part = 0;
	}
	else if((remain>=divisor/10)&&(remain<divisor/5))
	{
		remain_part = remain - divisor/10 + 1;
	}
	else
	{
		remain_part = divisor/10;
	}


	long long int result = quotient_part + remain_part;

	return result;
}




int main()
{
	cin>>N;
	
	string number_string;
	stringstream ss;
	ss<<N;
	ss>>number_string;

//	cout<<count_one(1)<<endl;

	long long int sum = 0;
	for(int i=0;i<number_string.length();i++)
	{
		sum = sum + count_one(i);
	}

	cout<<sum;

	return 0;
}







