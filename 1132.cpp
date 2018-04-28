#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	int N;
	cin>>N;
	vector<string> cut_int(N);

	for(int i=0;i<N;i++)
	{
		cin>>cut_int[i];
	}

	for(int i=0;i<N;i++)
	{
		int length = cut_int[i].length();
		string first = "";
		string second = "";
		for(int j=0;j<length/2;j++)    first = first + cut_int[i][j];
		for(int j=length/2;j<length;j++)    second = second + cut_int[i][j];

//		cout<<first<<" "<<second<<endl;

		int shu;
		stringstream su;
		su<<cut_int[i];
		su>>shu;

		int first_int;
		stringstream ss;
		ss<<first;
		ss>>first_int;

		int second_int;
		stringstream st;
		st<<second;
		st>>second_int;

		if(first_int * second_int != 0)
		{
			if(shu%(first_int*second_int) == 0)    cout<<"Yes";
			else	cout<<"No";
		}
		else cout<<"No";


		if(i!=N-1)    cout<<endl;

	}

	return 0;
}
