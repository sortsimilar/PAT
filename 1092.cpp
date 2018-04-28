#include<iostream>
#include<string>
using namespace std;

int main()
{

	string owner;
	string eva;

	cin>>owner;
	cin>>eva;

	int hash_eva[1000];	
	int hash_owner[1000];
	for(int i=0;i<1000;i++) // initialize owner;
	{
		hash_eva[i] = 0;
		hash_owner[i] = 0;
	}

	// store hash table of eva and owner;	
	for(int i=0;i<eva.length();i++)
	{
		int temp = eva[i] - '0';
		hash_eva[temp]++;

	}

	for(int i=0;i<owner.length();i++)
	{
		int temp = owner[i] - '0';
		hash_owner[temp]++;
	}

	int sum = 0;
	for(int i=0;i<1000;i++)
	{
		if(hash_eva[i] > hash_owner[i])    sum = sum + hash_eva[i] - hash_owner[i];
	}

	if(sum != 0)    cout<<"No "<<sum;
	else
	{
		cout<<"Yes "<<owner.length() - eva.length();
	}


	return 0;
}
