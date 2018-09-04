#include<algorithm>
#include<climits>
#include<iostream>
#include<vector>
using namespace std;


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
		int min_index = minDistance();		
		sptSet[min_index] = true; // Mark the picked vertex as processed

		for (int j=0;j<num_v;j++)
		{			
			if (!sptSet[j] && get_weight(min_index, j) && dist[min_index]!=INT_MAX)
			{
				if(dist[min_index]+get_weight(min_index, j)<dist[j])
				{
					dist[j] = dist[min_index] + get_weight(min_index, j);
					
					previous_list[j].previous_member.clear();
					previous_list[j].previous_member.push_back(min_index);
				}
				else if(dist[min_index]+get_weight(min_index, j)==dist[j])
				{
					previous_list[j].previous_member.push_back(min_index);
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

	// create adjacency matrix;
	for(int i=0;i<num_v*num_v;i++)
	{
		adjacency_matrix.push_back(0);
	}

	// save current amp in adjacency matrix;
	for(int i=0;i<M;i++)
	{
		int start;
		cin>>start;
		int end;
		cin>>end;
		int weight;
		cin>>weight;

		adjacency_matrix[start*num_v + end] = weight;
		adjacency_matrix[end*num_v + start] = weight;
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

/*

5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1

*/


