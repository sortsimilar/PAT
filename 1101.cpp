#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	int N;
	cin>>N;
	vector<string> sequence(N);
	vector<string> sequence_sort(N);

	for(int i=0;i<N;i++)
	{
		string temp;
		cin>>temp;
		int zero_need = 11 - temp.length();
		for(int j=0;j<zero_need;j++)
		{
			temp = "0" + temp;
		}
		sequence[i] = temp;
		sequence_sort[i] = temp;
	}

	sort(sequence_sort.begin(), sequence_sort.end());
	vector<string> candidate;

	for(int i=0;i<N;i++)
	{		
		if(sequence[i] == sequence_sort[i])
		{
			candidate.push_back(sequence[i]);
		}

	}


	sort(candidate.begin(), candidate.end());
	// output the result;
	cout<<candidate.size();
	if(candidate.size()>0)    cout<<endl;
	for(int i=0;i<candidate.size();i++)
	{
//		cout<<candidate[i];
		int position = 0;
		for(int j=0;j<candidate[i].length();j++)
		{
			if(candidate[i][j] != '0')
			{
				position = j;
				break;
			}
		}
		
		candidate[i].erase(0, position);
		cout<<candidate[i];

		if(i != candidate.size()-1)    cout<<" ";
	}

	return 0;
}
