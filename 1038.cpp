#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;


bool compare(string first, string second)
{
	return (first+second) <= (second+first);
}


int main()
{
	int N;
	cin>>N;

	vector<string> save;
	for(int i=0;i<N;i++)
	{
		string temp;
		cin>>temp;
		save.push_back(temp);
	}

	sort(save.begin(), save.end(), compare);

	string result = "";
	for(int i=0;i<save.size();i++)    result = result + save[i];

	while((result[0]=='0')&&(result.size()>1))    result.erase(0, 1);

	cout<<result;

	return 0;
}






