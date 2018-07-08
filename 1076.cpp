#include<iostream>
#include<vector>

using namespace std;

struct Edge
{
	int start;
	int end;
};


struct Node
{
	int key;
	int level;
};


int N; // number of users;
int L; // number of levels of indirect followers that are counted;
int counter; // count level of dfs; 
vector<bool> adjacency_matrix;
vector<bool> visited;
vector<int> result;
vector<int> output;

bool test_edge(int start, int end)
{
	bool flag = false;

	if(adjacency_matrix[(start-1)*N+(end-1)]==true)    flag = true;

	return flag;
}


// BFS one range;
void BFS(int i)
{
	visited[i-1] = true;	

	vector<Node> q;
	Node temp;
	temp.key = i;
	temp.level = 0;

	if(temp.level<=L)    result.push_back(temp.key);
	
	q.push_back(temp);

	while(q.size()!=0)
	{
		Node first = q.front();
		q.erase(q.begin());

		for(int j=0;j<N;j++)
		{
			if((test_edge(first.key, j+1) == true)&&(visited[j]==false))
			{
				visited[j] = true;

				Node temp;
				temp.key = j+1;
				temp.level = first.level + 1;


				if(temp.level<=L)    result.push_back(temp.key);
				else break;
	
				q.push_back(temp);
			}
		}
	}
}




int main()
{
	
	cin>>N;	
	cin>>L;

	// create adjacency matrix;
	for(int i=0;i<N*N;i++)
	{
		adjacency_matrix.push_back(false);
	}


	// save current amp in adjacency matrix;
	for(int i=0;i<N;i++)
	{
		int Mi;
		cin>>Mi;

		for(int j=0;j<Mi;j++)
		{
			int user;
			cin>>user;
			
			adjacency_matrix[(user-1)*N + i] = true;
		}
	}


	int K;
	cin>>K; 

	for(int j=0;j<K;j++)
	{
		// generate visited point;
		visited.resize(N);
		for(int i=0;i<N;i++)
		{
			visited[i] = false;
		}

		int query;
		cin>>query;

		result.clear();
		BFS(query);

		output.push_back(result.size()-1);
	}


	for(int i=0;i<output.size();i++)
	{
		cout<<output[i];
		if(i!=output.size()-1)    cout<<endl;
	}

	return 0;
}



