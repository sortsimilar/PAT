#include<iostream>
#include<vector>
using namespace std;

struct Edge
{
	int start;
	int end;
};

vector<Edge> store_edge;
vector<int> hash_table;



int main()
{
	int N; // number of vertices
	cin>>N;

	for(int i=0;i<N;i++)
	{
		hash_table.push_back(0);
	}

	int M; //  number of edges
	cin>>M;

	for(int i=0;i<M;i++)
	{
		Edge temp;
		cin>>temp.start;
		cin>>temp.end;
		store_edge.push_back(temp);
	}

	for(int i=0;i<M;i++)
	{
		int start = store_edge[i].start - 1;
		int end = store_edge[i].end - 1;

		hash_table[start]++;
		hash_table[end]++;
	}

// output degree of each vertex;
	int counter = 0;
	for(int i=0;i<N;i++)
	{
		cout<<hash_table[i];

		if(hash_table[i] % 2 == 1)
		{
			counter++;
		}

		if(i != N-1)    cout<<" ";
		else    cout<<endl;
	}

	if(counter==0)    cout<<"Eulerian";
	else if(counter==2)    cout<<"Semi-Eulerian";
	else    cout<<"Non-Eulerian";



	return 0;
}













