#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main()
{
	string test;
	cin>>test;

	int sum = 0;

	for(int i=0;i<test.length();i++)
	{
		int temp = test[i] - '0';
		sum = sum + temp;
	}

	stringstream ss;
	ss<<sum;
	string target = ss.str();


	for(int i=0;i<target.length();i++)
	{
		if(target[i] == '0')
		{
			cout<<"zero";
		}
		else if(target[i] == '1')
		{
			cout<<"one";
		}
		else if(target[i] == '2')
		{
			cout<<"two";
		}
		else if(target[i] == '3')
		{
			cout<<"three";
		}
		else if(target[i] == '4')
		{
			cout<<"four";
		}
		else if(target[i] == '5')
		{
			cout<<"five";
		}
		else if(target[i] == '6')
		{
			cout<<"six";
		}
		else if(target[i] == '7')
		{
			cout<<"seven";
		}
		else if(target[i] == '8')
		{
			cout<<"eight";
		}
		else if(target[i] == '9')
		{
			cout<<"nine";
		}

		if(i != target.length()-1)
		{
			cout<<" ";
		}
	}

	system("pause");
	return 0;
}