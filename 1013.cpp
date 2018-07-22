#include<iostream>
#include<vector>
using namespace std;


struct Edge
{
	int start;
	int end;
};


int num_v; // number of vertices
vector<Edge> store_edge;
vector<int> query;
vector<bool> adjacency_matrix;
vector<bool> original;
vector<bool> visited;

int counter; // count num of range after occupy;
vector<int> result; // save result;

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
//	cout<<i<<" ";
	for(int j=1;j<=num_v;j++)
	{
		if((test_edge(i, j)==true)&&(visited[j-1]==false))
		{
			DFS(j);
		}
	}

}

// DFS all map;
void DFSTraverse()
{
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
}




int main()
{
	int N; // num of cities;
	cin>>N;
	num_v = N;
	int M; // num of remaining highway;
	cin>>M;
	int K; // num to be checked;
	cin>>K;


	store_edge.resize(M);
	for(int i=0;i<M;i++)
	{
		cin>>store_edge[i].start;
		cin>>store_edge[i].end;
	}

	// create adjacency matrix;
	original.resize(num_v*num_v);
	for(int i=0;i<num_v*num_v;i++)
	{
		original[i] = false;
	}

	// save current amp in adjacency matrix;
	for(int i=0;i<M;i++)
	{
		int start = store_edge[i].start - 1;
		int end = store_edge[i].end - 1;

		original[start*num_v + end] = true;
		original[start + end*num_v] = true;
	}

	// generate visited point;
	visited.resize(num_v);
	for(int i=0;i<num_v;i++)
	{
		visited[i] = false;
	}


	query.resize(K);
	for(int i=0;i<K;i++)
	{
		cin>>query[i];
	}


	for(int j=0;j<query.size();j++)
	{
		// cut one dot;
		adjacency_matrix.resize(num_v*num_v);
		for(int i=0;i<original.size();i++)
		{
			adjacency_matrix[i] = original[i];
		}

		for(int i=0;i<num_v;i++)
		{
			int start = query[j]-1;
			int end = i;

			adjacency_matrix[start*num_v + end] = false;
			adjacency_matrix[start + end*num_v] = false;
		}

		counter = 0;
		DFSTraverse();
		result.push_back(counter-2);
	}


	for(int i=0;i<result.size();i++)
	{
		cout<<result[i];
		if(i!=result.size()-1)    cout<<endl;
	}


	return 0;
}




