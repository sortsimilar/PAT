#include<algorithm>
#include<climits>
#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;

struct Edge
{
	string start;
	string end;
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
	int happy_amount;
	int average;
	vector<int> path_member;
};



int num_v; // Number of vertices in the graph
vector<Edge> store_edge;
vector<int> adjacency_matrix;
vector<int> dist;
vector<bool> sptSet;
vector<int> previous;
vector<PreviousNode> previous_list;
vector<OnePath> paths; 
map<string, int> string_to_id;
map<int, string> id_to_string;
map<string, int> string_to_happy;



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
		previous[i] = -1;

		previous_list[i].next = -1;
	}
  	
	dist[src] = 0; // Distance of source vertex from itself is always 0
  
	for (int i=0;i<num_v;i++)
	{
		int u = minDistance();		
		sptSet[u] = true; // Mark the picked vertex as processed

		for (int v=0;v<num_v;v++)
		{
			previous_list[v].key = v;

			if (!sptSet[v] && get_weight(u, v) && dist[u]!=INT_MAX)
			{
				if(dist[u]+get_weight(u, v)<dist[v])
				{
					dist[v] = dist[u] + get_weight(u, v);
					previous[v] = u;
					
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

	if(id_to_string[previous_list[current].key]=="ROM")
	{
		int temp = string_to_id["ROM"];
		OnePath temp_path;
		while(temp!=-1)
		{
			temp_path.path_member.insert(temp_path.path_member.begin(), temp);
			temp = previous_list[temp].next;
		}
		paths.push_back(temp_path);
	}


	for(int i=0;i<previous_list[current].previous_member.size();i++) // childs 存放指向其每個子結點的指標
	{ 
		previous_list[previous_list[current].previous_member[i]].next = current;
		tree_dfs(previous_list[current].previous_member[i]);   
    }	
}


bool compare(OnePath a, OnePath b)
{
	if(a.happy_amount != b.happy_amount)    return a.happy_amount > b.happy_amount;
	else    return a.average > b.average;
}



int main()
{
	int N; // number of cities;
	cin>>N;
	num_v = N;

	dist.resize(num_v);
	sptSet.resize(num_v);
	previous.resize(num_v);
	previous_list.resize(num_v);


	int K; // total number of routes between pairs of cities;
	cin>>K;
	string name_start;
	cin>>name_start;

	int id = 0;
	string_to_id[name_start] = id;
	id_to_string[id] = name_start;
	string_to_happy[name_start] = 0;

	for(int i=1;i<N;i++)
	{
		string temp;
		cin>>temp;

		string_to_id[temp] = i;
		id_to_string[i] = temp;

		int happy;
		cin>>happy;
		string_to_happy[temp] = happy;
	}

//	cout<<string_to_id["BLN"]<<" "<<string_to_happy["BLN"];

	store_edge.resize(K);
	for(int i=0;i<K;i++)
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
	for(int i=0;i<K;i++)
	{
		int start = string_to_id[store_edge[i].start];
		int end = string_to_id[store_edge[i].end];

		adjacency_matrix[start*num_v + end] = store_edge[i].weight;
		adjacency_matrix[start + end*num_v] = store_edge[i].weight;
	}


	dijkstra(string_to_id["ROM"]);


	tree_dfs(string_to_id[name_start]);

	for(int i=0;i<paths.size();i++)
	{
		paths[i].happy_amount = 0;

		for(int j=0;j<paths[i].path_member.size();j++)
		{
			paths[i].happy_amount += string_to_happy[id_to_string[paths[i].path_member[j]]];			
		}
		
		paths[i].average = paths[i].happy_amount / (paths[i].path_member.size()-1);

//		cout<<paths[i].average<<endl;
	}

//	cout<<endl<<dist[string_to_id[name_start]]<<endl;

	sort(paths.begin(), paths.end(), compare);

	cout<<paths.size()<<" "<<dist[string_to_id[name_start]]<<" "<<paths[0].happy_amount<<" "<<paths[0].average<<endl;
	for(int i=0;i<paths[0].path_member.size();i++)
	{
		cout<<id_to_string[paths[0].path_member[i]];
		if(i!=paths[0].path_member.size()-1)    cout<<"->";
	}


	return 0;
}





