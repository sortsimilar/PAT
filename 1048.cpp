#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

vector<int> sequence;






int main()
{
	int N; // total number of coins
	cin>>N; 

	int M; // amount of money Eva has to pay
	cin>>M;


	for(int i=0;i<N;i++)
	{
		int temp;
		cin>>temp;
		sequence.push_back(temp);
	}

	sort(sequence.begin(), sequence.end());

/*
	for(int i=0;i<N;i++)
	{
		cout<<sequence[i]<<" ";
	}
	cout<<endl;
*/

	int flag = false;
	int start;
	int end;
	for(int i=0;i<N;i++)
	{
		for(int j=i+1;j<N;j++)
		{
			if(sequence[i] + sequence[j] == M)
			{
				flag = true;
				start = i;
				end = j;
//				cout<<start<<" "<<end<<" "<<sequence[start]<<" "<<sequence[end]<<endl;
				break;
			}
		}
		if(flag==true)    break;
	}

	if(flag == false)    cout<<"No Solution";
	else    cout<<sequence[start]<<" "<<sequence[end];




	return 0;
}





