#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

struct Edge
{
	int start;
	int end;
};

struct NodeDeep
{
	int index;
	int deep;
};

int num_v; // number of vertices
vector<Edge> store_edge;
vector<bool> adjacency_matrix;
vector<bool> visited;
vector<int> level;
vector<NodeDeep> nodes;

bool test_edge(int start, int end)
{
	bool flag = false;

	if(adjacency_matrix[(start-1)*num_v+(end-1)]==true)    flag = true;
	if(adjacency_matrix[(start-1)+(end-1)*num_v]==true)    flag = true;

	return flag;
}

// DFS one range;
void DFS(int i)
{
	visited[i-1] = true;

	for(int j=1;j<=num_v;j++)
	{
		if((test_edge(i, j)==true)&&(visited[j-1]==false))
		{
			level[j-1] = level[i-1] + 1;
			DFS(j);
		}
	}

}


// DFS all map;
int DFSTraverse()
{
	int counter = 0;

	// initialize visited matrix;
	for(int i=1;i<=num_v;i++)
	{
		visited[i-1] = false;
	}


	for(int i=1;i<=num_v;i++)
	{
		if(visited[i-1]==false)
		{
			DFS(i);
			counter++;
		}
	}
	
	return counter;
}

bool compare(NodeDeep a, NodeDeep b)
{
	if(a.deep!=b.deep)    return a.deep>b.deep;
	else    return a.index<b.index;
}



int main()
{
	int N;
	cin>>N;
	num_v = N; 

	store_edge.resize(N-1);
	for(int i=0;i<store_edge.size();i++)
	{
		cin>>store_edge[i].start;
		cin>>store_edge[i].end;
	}

	// create adjacency matrix;
	adjacency_matrix.resize(N*N);
	for(int i=0;i<num_v*num_v;i++)
	{
		adjacency_matrix[i] = false;
	}

	// save current amp in adjacency matrix;
	for(int i=0;i<num_v-1;i++)
	{
		int start = store_edge[i].start - 1;
		int end = store_edge[i].end - 1;

		adjacency_matrix[start*num_v + end] = true;
		adjacency_matrix[start + end*num_v] = true;
	}

	// generate visited point;
	visited.resize(num_v);
	for(int i=0;i<num_v;i++)
	{
		visited[i] = false;
	}

	level.resize(num_v);
	for(int i=0;i<num_v;i++)
	{
		level[i] = 0;
	}



	int num_range = DFSTraverse();

	if(num_range>1)
	{
		cout<<"Error: "<<num_range<<" components";
	}
	else
	{
		nodes.resize(num_v);	

		for(int j=1;j<=num_v;j++)
		{
			int max_deep = 0;
			for(int i=0;i<num_v;i++)
			{
				level[i] = 0;
				visited[i] = false;
			}
	

			DFS(j);

			for(int i=0;i<num_v;i++)
			{
				if(max_deep<level[i])    max_deep = level[i];
			}

	//		cout<<max_deep;

			nodes[j-1].index = j;
			nodes[j-1].deep = max_deep;
		}

		sort(nodes.begin(), nodes.end(), compare);

		vector<int> result;
		for(int i=0;i<nodes.size();i++)
		{
			if(nodes[i].deep==nodes[0].deep)    result.push_back(nodes[i].index);
			else break;
		}

		for(int i=0;i<result.size();i++)
		{
			cout<<result[i];
			if(i!=result.size()-1)    cout<<endl;
		}
	}

	return 0;
}


