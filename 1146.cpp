#include<iostream>
#include<vector>

using namespace std;

struct Edge
{
	int start;
	int end;
};


int N; // number of vertices in the graph;
int M; // number of directed edges;
vector<Edge> store_edge;
vector<bool> adjacency_matrix;
vector<bool> visited;
vector<int> query;
vector<int> result;

bool test_edge(int start, int end)
{
	bool flag = false;

	if(adjacency_matrix[(start-1)*N+(end-1)]==true)    flag = true;


	return flag;
}

// DFS one range;
void DFS(int i)
{
	visited[i-1] = true;
//	cout<<i<<" ";
	for(int j=1;j<=N;j++)
	{
		if((test_edge(i, j)==true)&&(visited[j-1]==false))
		{
			DFS(j);
		}
	}

}


// test connected point;
bool test_connect(int start, int end)
{
	bool flag;

	// generate visited point;
	visited.resize(N);
	for(int i=0;i<N;i++)
	{
		visited[i] = false;
	}


	DFS(start);

	if(visited[end-1]==true)
	{
		flag = true;
	}
	else
	{
		flag = false;
	}


	return flag;
}



int main()
{
	
	cin>>N;	
	cin>>M;

	store_edge.resize(M);
	for(int i=0;i<M;i++)
	{
		cin>>store_edge[i].start;
		cin>>store_edge[i].end;
	}

	// create adjacency matrix;
	for(int i=0;i<N*N;i++)
	{
		adjacency_matrix.push_back(false);
	}

	// save current amp in adjacency matrix;
	for(int i=0;i<M;i++)
	{
		int start = store_edge[i].start - 1;
		int end = store_edge[i].end - 1;

		adjacency_matrix[start*N + end] = true;
	}


//	cout<<test_edge(3, 4)<<endl;

	// generate visited point;
	visited.resize(N);
	for(int i=0;i<N;i++)
	{
		visited[i] = false;
	}


//	cout<<test_connect(1, 6)<<endl;
//	cout<<test_connect(6, 1)<<endl;

	int K; // num of query;
	cin>>K;

	for(int i=0;i<K;i++)
	{
		query.clear();
		for(int j=0;j<N;j++)
		{
			int temp;
			cin>>temp;
			query.push_back(temp);
		}


		bool flag = true;
		for(int j=0;j<N-1;j++)
		{
			if((test_edge(query[j], query[j+1])==false)&&(test_connect(query[j], query[j+1])==true))
			{
				flag = false;
				break;
			}
		}

//		cout<<flag<<endl;
		if(flag==false)
		{
			result.push_back(i);
		}

	}

	for(int i=0;i<result.size();i++)
	{
		cout<<result[i];

		if(i!=result.size()-1)    cout<<" ";
	}




	return 0;
}



	
