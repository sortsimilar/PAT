#include<iostream>
#include<vector>
using namespace std;

struct Edge
{
	int start;
	int end;
};


int N; // number of vertices
int M; //  number of edges
vector<Edge> store_edge;
vector<int> hash_table;
vector<bool> adjacency_matrix;
vector<bool> visited;



bool test_edge(int start, int end)
{
	bool flag = false;

	if(adjacency_matrix[(start-1)*N+(end-1)]==true)    flag = true;
	if(adjacency_matrix[(start-1)+(end-1)*N]==true)    flag = true;

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

// test connected graph;
bool test_connect()
{
	bool flag = true;

	DFS(N);

	for(int i=0;i<N;i++)
	{
		if(visited[i]==false)
		{
			flag = false;
			break;
		}
	}

	return flag;
}



// main function //////////////////////////////////////////////////
int main()
{
	
	cin>>N;

	for(int i=0;i<N;i++)
	{
		hash_table.push_back(0);
	}
	
	cin>>M;

	for(int i=0;i<M;i++)
	{
		Edge temp;
		cin>>temp.start;
		cin>>temp.end;
		store_edge.push_back(temp);
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
		adjacency_matrix[start + end*N] = true;
	}

//	cout<<test_edge(2, 1)<<endl;
//	cout<<test_edge(2, 4)<<endl;

	// generate visited point;
	for(int i=0;i<N;i++)
	{
		visited.push_back(false);
	}

	bool connected = test_connect();



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

	if(connected==true)
	{
		if(counter==0)    cout<<"Eulerian";
		else if(counter==2)    cout<<"Semi-Eulerian";
		else    cout<<"Non-Eulerian";
	}
	else    cout<<"Non-Eulerian";


	return 0;
}













