#include<iostream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

int main()
{
	string num;
	getline(cin, num);


	int N = stoi(num);
	vector<string> juzi(N);
	int min_length = 258;

	
	for(int i=0;i<N;i++)
	{
		getline(cin, juzi[i]);
		if(min_length > juzi[i].length()) min_length = juzi[i].length(); // find min length;
	}

//	cout<<juzi[1];
//	cout<<min_length;

	string result = "";
	for(int i=0;i<min_length;i++)
	{
		bool flag_equal = true;
	
		for(int j=0;j<N;j++)
		{
			if(juzi[0][juzi[0].length()-1-i] != juzi[j][juzi[j].length()-1-i])
			{
				flag_equal = false;
				break;
			}
		}
	
		if(flag_equal == true) result = juzi[0][juzi[0].length()-1-i] + result;
		else break;
	}
	if(result.length()>0) cout<<result;
	else cout<<"nai";

	system("pause");
	return 0;
}