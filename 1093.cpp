#include<iostream>
#include<string>
using namespace std;

int main()
{
	string pat;
	cin>>pat;

	int counter = 0;
	int count_P = 0;
	int count_T = 0;
	int mode = 1000000007;

	for(int i=0;i<pat.length();i++)
	{
		if(pat[i]=='T')
		{
			count_T++;
		}
	}

	for(int i=0;i<pat.length();i++)
	{
		if(pat[i]=='P')
		{
			count_P++;
		}

		if(pat[i]=='T')
		{
			count_T--;
		}

		if(pat[i]=='A')
		{
			counter += (count_P % mode) * (count_T % mode);
			counter = counter % mode;
		}
	}


	cout<<counter;


	return 0;
}
