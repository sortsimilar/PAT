#include<cstdio>
#include<vector>
using namespace std;


struct Edge
{
	int start;
	int end;
};


int num_v; // number of vertices
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
void DFSTraverse(int lost_city)
{
	// initialize visited matrix;
	for(int i=1;i<=num_v;i++)
	{
		visited[i-1] = false;
	}

	visited[lost_city-1] = true;

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
	int M; // num of remaining highway;
	int K; // num to be checked;
	scanf("%d%d%d", &N, &M, &K);


	num_v = N;
	// create adjacency matrix;
	original.resize(num_v*num_v);
	for(int i=0;i<num_v*num_v;i++)
	{
		original[i] = false;
	}


	for(int i=0;i<M;i++)
	{
		int start;
		int end;		

		scanf("%d%d", &start, &end);

		start = start - 1;
		end = end - 1;

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
		scanf("%d", &query[i]);
	}


	for(int j=0;j<query.size();j++)
	{
		// cut one dot;
		adjacency_matrix.resize(num_v*num_v);
		for(int i=0;i<original.size();i++)
		{
			adjacency_matrix[i] = original[i];
		}

		counter = 0;
		DFSTraverse(query[j]);
		result.push_back(counter-1);
	}


	for(int i=0;i<result.size();i++)
	{
		printf("%d", result[i]);
		if(i!=result.size()-1)    printf("\n");
	}


	return 0;
}




