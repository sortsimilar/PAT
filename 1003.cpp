#include<algorithm>
#include<climits>
#include<iostream>
#include<vector>
using namespace std;

struct Edge
{
	int start;
	int end;
	int weight;
};

struct PreviousNode
{
	int key;
	int next;
	vector<int> previous_member;
};

struct OnePath
{
	int total_rescue;
	vector<int> path_member;
};


int num_v;
vector<Edge> store_edge;
vector<int> rescue;
vector<int> adjacency_matrix;
vector<int> dist;
vector<bool> sptSet;
vector<PreviousNode> previous_list;
vector<OnePath> paths; 
int C2; // city must save;



int get_weight(int start, int end)
{
	return adjacency_matrix[start*num_v + end];
}

int minDistance()
{
	// Initialize min value
	int min = INT_MAX;
	int min_index;
  
	for (int v=0;v<num_v;v++)
	{
		if (sptSet[v]==false && dist[v]<=min)
		{
			min = dist[v];
			min_index = v;
		}
	}  

	return min_index;
}

void dijkstra(int src)
{          
	for (int i=0;i<num_v;i++)
	{
		dist[i] = INT_MAX;
		sptSet[i] = false;

		previous_list[i].key = i;
		previous_list[i].next = -1;
	}
  	
	dist[src] = 0; // Distance of source vertex from itself is always 0
  
	for (int i=0;i<num_v;i++)
	{
		int u = minDistance();		
		sptSet[u] = true; // Mark the picked vertex as processed

		for (int v=0;v<num_v;v++)
		{			
			if (!sptSet[v] && get_weight(u, v) && dist[u]!=INT_MAX)
			{
				if(dist[u]+get_weight(u, v)<dist[v])
				{
					dist[v] = dist[u] + get_weight(u, v);
					
					previous_list[v].previous_member.clear();
					previous_list[v].previous_member.push_back(u);
				}
				else if(dist[u]+get_weight(u, v)==dist[v])
				{
					previous_list[v].previous_member.push_back(u);
				}
			}
		}
	}

}

void tree_dfs(int current)
{

	if(previous_list[current].key==C2)
	{
		int temp = C2;
		OnePath temp_path;
		while(temp!=-1)
		{
			temp_path.path_member.insert(temp_path.path_member.begin(), temp);
			temp = previous_list[temp].next;
		}
		paths.push_back(temp_path);
	}


	for(int i=0;i<previous_list[current].previous_member.size();i++)
	{ 
		previous_list[previous_list[current].previous_member[i]].next = current;
		tree_dfs(previous_list[current].previous_member[i]);   
    }	
}


bool compare(OnePath a, OnePath b)
{
	return a.total_rescue > b.total_rescue;
}



int main()
{
	int N; // num of cities;
	cin>>N;

	num_v = N;
	dist.resize(num_v);
	sptSet.resize(num_v);
	previous_list.resize(num_v);

	int M; // num of roads;
	cin>>M;
	int C1; // city current in;	
	cin>>C1;
	cin>>C2;


	rescue.resize(N);
	for(int i=0;i<N;i++)
	{
		cin>>rescue[i];
	}


	store_edge.resize(M);
	for(int i=0;i<M;i++)
	{
		cin>>store_edge[i].start;
		cin>>store_edge[i].end;
		cin>>store_edge[i].weight;
	}

	// create adjacency matrix;
	adjacency_matrix.resize(num_v*num_v);
	for(int i=0;i<num_v*num_v;i++)
	{
		adjacency_matrix[i] = 0;
	}

	// save current amp in adjacency matrix;
	for(int i=0;i<store_edge.size();i++)
	{
		int start = store_edge[i].start;
		int end = store_edge[i].end;

		adjacency_matrix[start*num_v + end] = store_edge[i].weight;
		adjacency_matrix[start + end*num_v] = store_edge[i].weight;
	}

	
	dijkstra(C2);
	tree_dfs(C1);

	for(int i=0;i<paths.size();i++)
	{
		paths[i].total_rescue = 0;
		for(int j=0;j<paths[i].path_member.size();j++)
		{
			paths[i].total_rescue += rescue[paths[i].path_member[j]];
		}
	}
	
	sort(paths.begin(), paths.end(), compare);

	cout<<paths.size()<<" "<<paths[0].total_rescue;

	return 0;
}




