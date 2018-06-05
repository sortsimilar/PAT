#include<iostream>
#include<vector>
using namespace std;

vector<int> hash_table(1003);
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

// initialize hash table;
	for(int i=0;i<hash_table.size();i++)
	{
		hash_table[i] = 0;
	}

// move data from sequence to hash table;
	for(int i=0;i<N;i++)
	{
		hash_table[sequence[i]]++;
	}


	int v1 = 1; 
	int v2 = M - v1;
	int flag = false;
	while(v1<=v2)
	{
		if(hash_table[v1]>0)
		{
			hash_table[v1]--;
			if(hash_table[v2]>0)
			{
				flag = true;
				cout<<v1<<" "<<v2;
				break;
			}
		}


		v1++;
		v2--;
	}

	if(flag==false)    cout<<"No Solution";

	return 0;
}





