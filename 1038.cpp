#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

// convert from string to long long int;
long long string_to_int(string target)
{
	stringstream ss;
	ss<<target;
	long long result;
	ss>>result;

	return result;
}


bool compare(string first, string second)
{
	return string_to_int(first+second) <= string_to_int(second+first);
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






