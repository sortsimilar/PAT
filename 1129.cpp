#include<iostream>
#include<set>
#include<vector>
using namespace std;

struct Node // Node in hash table;
{
	int key;
	int freq;

	bool operator < (const Node &a) const
	{	
		if(freq != a.freq)    return freq > a.freq;
		else
		{
			return key < a.key;
		}
    }
};



vector<int> access;
vector<Node> hash_table;
set<Node> freq_set;
vector<int> frequence(50001, 0);


bool compare(Node first, Node second)
{
	if(first.freq != second.freq)    return first.freq > second.freq;
	else    return first.key < second.key;

}



int main()
{
	int N; // number of query;
	cin>>N; 

	int K; // max of recommendation;
	cin>>K;

	access.resize(N);
	for(int i=0;i<N;i++)	
	{
		cin>>access[i];
	}
	
	// calculate freq for each input;
	for(int i=0;i<N;i++)
	{

		set<Node>::iterator it;

		if(i>=1)
		{
			cout<<access[i]<<": ";
					
			int counter = 0;
	
			for(it=freq_set.begin() ;it!=freq_set.end();it++)
			{
				if(counter!=0)    cout<<" ";				
				cout<<it->key+1;		

				counter++;
				if(counter>=K)    break;
			}
		}

		int temp = access[i] - 1;
		Node current;
		current.key = temp;
		current.freq = frequence[temp];

		
		it = freq_set.find(current);
		if(it != freq_set.end())
		{
			freq_set.erase(it);
		}

		frequence[temp]++;
		current.freq++;
		freq_set.insert(current);

		if((i != N-1)&&(i>=1))    cout<<endl;

	}


	return 0;
}















