#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;

bool compare(int a, int b)
{
	return a>b;
}

int main()
{
	string original, smalltobig, bigtosmall;
	cin>>original;

	while(original.length() < 4) original = "0" + original;

	
	string result_other;

	if((original[0] == original[1])&&(original[1] == original[2])&&(original[2] == original[3])) 
	{
		cout<<original<<" - "<<original<<" = 0000";
	}
	else
	{
		while(result_other != "6174")
		{
			smalltobig = original;
			bigtosmall = original;
			sort(smalltobig.begin(), smalltobig.end());
			sort(bigtosmall.begin(), bigtosmall.end(),compare);

			int small = stoi(smalltobig);
			int big = stoi(bigtosmall);

			int result = big - small;		
			stringstream sa;
			sa<<result;
			sa>>result_other;

			while(result_other.length()<4) result_other = "0" + result_other;

	
			cout<<bigtosmall<<" - "<<smalltobig<<" = ";
			cout<<result_other;
			if(result_other != "6174") cout<<endl;


			original = result_other;
		}
	}
	

	system("pause");
	return 0;
}