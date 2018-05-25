#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

struct Node // Node in hash table;
{
	int name;
	int freq;
};

vector<int> access;
vector<Node> hash_table;


bool compare(Node first, Node second)
{
	if(first.freq != second.freq)    return first.freq > second.freq;
	else    return first.name < second.name;

}



int main()
{
	int N; // number of query;
	cin>>N; 

	int K; // max of recommendation;
	cin>>K;

	for(int i=0;i<N;i++)	
	{
		int temp;
		cin>>temp;
		access.push_back(temp);
	}

	// create hash table;
	for(int i=0;i<N;i++)
	{
		Node temp;
		temp.name = i + 1;
		temp.freq = 0;

		hash_table.push_back(temp);		
	}
	
//	for(int i=0;i<N;i++)    cout<<hash_table[i].name<<" ";
	
	// calculate freq for each input;
	for(int i=0;i<N;i++)
	{
		
		vector<Node> hash_sorted(N);
		for(int j=0;j<N;j++)
		{
			hash_sorted[j] = hash_table[j];
		}

		sort(hash_sorted.begin(), hash_sorted.end(), compare);


		if(i>=K)
		{
			cout<<access[i]<<": ";
			for(int j=0;j<K;j++)
			{
				cout<<hash_sorted[j].name;
				if(j != K-1)    cout<<" ";
			}
		}
		else if((i>=1)&&(i<K))
		{
			cout<<access[i]<<": ";
			for(int j=0;j<i;j++)
			{
				cout<<hash_sorted[j].name;
				if(j != i-1)    cout<<" ";
			}
		}		




		if((i != N-1)&&(i>=1))    cout<<endl;

		int temp = access[i] - 1;
		(hash_table[temp].freq)++;


	}


	





	return 0;
}















