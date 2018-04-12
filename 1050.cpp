#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	string first;
	string second;
	vector<int> charset(10001);
	for(int i=0;i<10001;i++) charset[i] = 0;
	string output = "";

	getline(cin, first);
	getline(cin, second);

//	cout<<second;

	for(int i=0;i<second.length();i++)
	{
		int temp = second[i] - 0;
		charset[temp] = 1;
	}

	for(int i=0;i<first.length();i++)
	{
		int temp = first[i] - 0;
		if(charset[temp] ==0) cout<<first[i];
	}


	system("pause");
	return 0;
}