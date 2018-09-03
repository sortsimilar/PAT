#include<iostream>
#include<vector>
using namespace std;


struct Node
{
	int key;
	int indegree;
	int current_degree;
	vector<int> next;
};


int num_v;
vector<Node> nodes;
vector<int> query;
vector<int> result;



int main()
{
	int N; // number of vertices in the graph;
	int M; // number of directed edges;	
	cin>>N;	
	num_v = N;
	cin>>M;


	nodes.resize(N);
	for(int i=0;i<nodes.size();i++)
	{
		nodes[i].key = i;
		nodes[i].indegree = 0;
		nodes[i].current_degree = 0;
	}


	// save current amp in adjacency matrix;
	for(int i=0;i<M;i++)
	{
		int start;
		cin>>start;
		int end;
		cin>>end;

		nodes[start-1].next.push_back(end-1);
		nodes[end-1].indegree++;		
	}


//	cout<<test_edge(3, 4)<<endl;

	int K;
	cin>>K;


	for(int i=0;i<K;i++)	
	{
		query.clear();

		for(int j=0;j<num_v;j++)
		{
			int index;
			cin>>index;
			index--;
			query.push_back(index);
		}

		for(int j=0;j<num_v;j++)
		{
			nodes[j].current_degree = nodes[j].indegree;
		}


		bool isTopo = true;

		for(int j=0;j<num_v;j++)
		{
			if(nodes[query[j]].current_degree != 0)
			{
				isTopo = false;
				break;
			}

			for(int k=0;k<nodes[query[j]].next.size();k++)
			{
				int next_index = nodes[query[j]].next[k];
				nodes[next_index].current_degree--;
			}
		}

//		cout<<isTopo<<endl;
		if(isTopo == false)    result.push_back(i);

	}


	for(int i=0;i<result.size();i++)
	{
		cout<<result[i];

		if(i!=result.size()-1)    cout<<" ";
	}

	return 0;
}


/*

6 8
1 2
1 3
5 2
5 4
2 3
2 6
3 4
6 4
5
1 5 2 3 6 4
5 1 2 6 3 4
5 1 2 3 6 4
5 2 1 6 3 4
1 2 3 4 5 6


*/
	
