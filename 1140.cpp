#include<iostream>
#include<sstream>
#include<string>
using namespace std;

string int_to_string(int num)
{
	string result;
	stringstream ss;
	ss<<num;
	ss>>result;

	return result;
}

int string_to_int(string s)
{
	int result;
	stringstream ss;
	ss<<s;
	ss>>result;

	return result;
}

string generate_next(string current)
{
	string result = "";

	current = current + " ";

	char prev = current[0];
	int counter = 1;

	for(int i=1;i<current.length();i++)
	{
		if(current[i]==prev)
		{
			counter++;
		}
		else
		{
			result = result + prev + int_to_string(counter);
			prev = current[i];
			counter = 1;
		}
	}


	return result;
}




int main()
{
	string D;
	cin>>D;

	int N;	
	cin>>N;

//	string test = "911231";
//	string result = generate_next(test);
//	cout<<result;

	string result = D;
	for(int i=1;i<N;i++)
	{
		result = generate_next(result);
	}

	cout<<result;

	return 0;
}
