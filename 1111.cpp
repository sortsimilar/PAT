#include<algorithm>
#include<climits>
#include<iostream>
#include<vector>
using namespace std;


struct Edge
{
	int start;
	int end;
	bool one_way;
	int weight;
	int time;
};


struct PreviousNode
{
	int key;
	int next;
	vector<int> previous_member;
};


struct OnePath
{
	int total_time;
	vector<int> path_member;
};


int num_v; // Number of vertices in the graph
vector<Edge> store_edge;

vector<int> dist;
vector<bool> sptSet;
vector<PreviousNode> previous_list;
vector<OnePath> paths; 
vector<int> adjacency_matrix;

vector<int> dist_t;
vector<bool> sptSet_t;
vector<PreviousNode> previous_list_t;
vector<OnePath> paths_t;
vector<int> adjacency_time;


int get_weight(int start, int end)
{
	return adjacency_matrix[start*num_v + end];
}


int get_time(int start, int end)
{
	return adjacency_time[start*num_v + end];
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


int minDistance_t()
{
	// Initialize min value
	int min = INT_MAX;
	int min_index;
  
	for (int v=0;v<num_v;v++)
	{
		if (sptSet_t[v]==false && dist_t[v]<=min)
		{
			min = dist_t[v];
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
  
	dist[src] = 0;
  
	for (int i=0;i<num_v;i++)
	{
		int u = minDistance();
		sptSet[u] = true;

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


void dijkstra_t(int src)
{          
	for (int i=0;i<num_v;i++)
	{
        dist_t[i] = INT_MAX;
		sptSet_t[i] = false;

		previous_list_t[i].key = i;
		previous_list_t[i].next = -1;
	}
  
	dist_t[src] = 0;
  
	for (int i=0;i<num_v;i++)
	{
		int u = minDistance_t();
		sptSet_t[u] = true;

		for (int v=0;v<num_v;v++)
		{
			if (!sptSet_t[v] && get_time(u, v) && dist_t[u]!=INT_MAX)
			{
				if(dist_t[u]+get_time(u, v)<dist_t[v])
				{
					dist_t[v] = dist_t[u] + get_time(u, v);
					
					previous_list_t[v].previous_member.clear();
					previous_list_t[v].previous_member.push_back(u);
				}
				else if(dist_t[u]+get_time(u, v)==dist_t[v])
				{
					previous_list_t[v].previous_member.push_back(u);
				}
			}
		}
	}

}



void tree_dfs(int current, int src)
{

	if(previous_list[current].key==src)
	{
		int temp = src;
		OnePath temp_path;
		while(temp!=-1)
		{
			temp_path.path_member.push_back(temp);
			temp = previous_list[temp].next;
		}
		paths.push_back(temp_path);
	}


	for(int i=0;i<previous_list[current].previous_member.size();i++) 
	{ 
		previous_list[previous_list[current].previous_member[i]].next = current;
		tree_dfs(previous_list[current].previous_member[i], src);   
    }	
}


void tree_dfs_t(int current, int src)
{

	if(previous_list_t[current].key==src)
	{
		int temp = src;
		OnePath temp_path;
		while(temp!=-1)
		{
			temp_path.path_member.push_back(temp);
			temp = previous_list_t[temp].next;
		}
		paths_t.push_back(temp_path);
	}


	for(int i=0;i<previous_list_t[current].previous_member.size();i++) 
	{ 
		previous_list_t[previous_list_t[current].previous_member[i]].next = current;
		tree_dfs_t(previous_list_t[current].previous_member[i], src);   
    }	
}


bool compare_time(OnePath a, OnePath b)
{
	return a.total_time < b.total_time;
}

bool compare_pass(OnePath a, OnePath b)
{
	return a.path_member.size() < b.path_member.size();
}


int main()
{
	int N; // total number of streets intersections;
	cin>>N;

	num_v = N;

	dist.resize(num_v);
	sptSet.resize(num_v);
	previous_list.resize(num_v);

	dist_t.resize(num_v);
	sptSet_t.resize(num_v);
	previous_list_t.resize(num_v);

	int M; // number of streets;
	cin>>M;

	store_edge.resize(M);
	for(int i=0;i<store_edge.size();i++)
	{
		cin>>store_edge[i].start;
		cin>>store_edge[i].end;
		cin>>store_edge[i].one_way;
		cin>>store_edge[i].weight;
		cin>>store_edge[i].time;
	}

	int src;
	cin>>src;
	int dest;
	cin>>dest;

	// create adjacency matrix;
	adjacency_matrix.resize(num_v*num_v);
	adjacency_time.resize(num_v*num_v);
	for(int i=0;i<num_v*num_v;i++)
	{
		adjacency_matrix[i] = 0;
		adjacency_matrix[i] = 0;

		adjacency_time[i] = 0;
		adjacency_time[i] = 0;
	}

	
	// save current amp in adjacency matrix;
	for(int i=0;i<store_edge.size();i++)
	{
		int start = store_edge[i].start;
		int end = store_edge[i].end;
		bool one_way = store_edge[i].one_way;

		if(one_way==false)
		{
			adjacency_matrix[start*num_v + end] = store_edge[i].weight;
			adjacency_matrix[start + end*num_v] = store_edge[i].weight;

			adjacency_time[start*num_v + end] = store_edge[i].time;
			adjacency_time[start + end*num_v] = store_edge[i].time;
		}
		else
		{
			adjacency_matrix[start*num_v + end] = store_edge[i].weight;

			adjacency_time[start*num_v + end] = store_edge[i].time;
		}
	}


	// calculate length path; /////////////////////////////
	dijkstra(src);
	tree_dfs(dest, src);

	for(int i=0;i<paths.size();i++)
	{
		paths[i].total_time = 0;
		for(int j=0;j<paths[i].path_member.size()-1;j++)
		{
			int start = paths[i].path_member[j];
			int end = paths[i].path_member[j+1];
			paths[i].total_time = paths[i].total_time + get_time(start, end);
		}
	}

	sort(paths.begin(), paths.end(), compare_time);

	// calculate time path; //////////////////////////////
	dijkstra_t(src);
	tree_dfs_t(dest, src);
	sort(paths_t.begin(), paths_t.end(), compare_pass);

	// check whether two paths are equal;
	bool flag = true;
	if(paths[0].path_member.size()!=paths_t[0].path_member.size())
	{
		flag = false;
	}
	else
	{
		for(int i=0;i<paths[0].path_member.size();i++)
		{
			if(paths[0].path_member[i]!=paths_t[0].path_member[i])
			{
				flag = false;
				break;
			}
		}
	}





	if(flag==false)
	{
		cout<<"Distance = "<<dist[dest]<<": ";
		for(int i=0;i<paths[0].path_member.size();i++)
		{
			cout<<paths[0].path_member[i];

			if(i!=paths[0].path_member.size()-1)    cout<<" -> ";		
		}
	
		cout<<endl<<"Time = "<<dist_t[dest]<<": ";

		for(int i=0;i<paths_t[0].path_member.size();i++)
		{
			cout<<paths_t[0].path_member[i];

			if(i!=paths_t[0].path_member.size()-1)    cout<<" -> ";		
		}
	}
	else
	{
		cout<<"Distance = "<<dist[dest]<<"; ";
		cout<<"Time = "<<dist_t[dest]<<": ";

		for(int i=0;i<paths[0].path_member.size();i++)
		{
			cout<<paths[0].path_member[i];

			if(i!=paths[0].path_member.size()-1)    cout<<" -> ";		
		}
	}

	return 0;
}




