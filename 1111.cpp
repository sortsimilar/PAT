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
	int total_time;
	vector<int> path_member;
};


int num_v; // Number of vertices in the graph
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
  
	for (int i=0;i<num_v;i++)
	{
		if (sptSet[i]==false && dist[i]<=min)
		{
			min = dist[i];
			min_index = i;
		}
	}  

	return min_index;
}


int minDistance_t()
{
	// Initialize min value
	int min = INT_MAX;
	int min_index;
  
	for (int i=0;i<num_v;i++)
	{
		if (sptSet_t[i]==false && dist_t[i]<=min)
		{
			min = dist_t[i];
			min_index = i;
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
		int min_index = minDistance();
		sptSet[min_index] = true;

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
		int min_index = minDistance_t();
		sptSet_t[min_index] = true;

		for (int j=0;j<num_v;j++)
		{
			if (!sptSet_t[j] && get_time(min_index, j) && dist_t[min_index]!=INT_MAX)
			{
				if(dist_t[min_index]+get_time(min_index, j)<dist_t[j])
				{
					dist_t[j] = dist_t[min_index] + get_time(min_index, j);
					
					previous_list_t[j].previous_member.clear();
					previous_list_t[j].previous_member.push_back(min_index);
				}
				else if(dist_t[min_index]+get_time(min_index, j)==dist_t[j])
				{
					previous_list_t[j].previous_member.push_back(min_index);
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
	for(int i=0;i<M;i++)
	{
		int start;
		cin>>start;
		int end;
		cin>>end;
		bool one_way;
		cin>>one_way;
		int weight;
		cin>>weight;
		int time;
		cin>>time;

		if(one_way==false)
		{
			adjacency_matrix[start*num_v + end] = weight;
			adjacency_matrix[start + end*num_v] = weight;

			adjacency_time[start*num_v + end] = time;
			adjacency_time[start + end*num_v] = time;
		}
		else
		{
			adjacency_matrix[start*num_v + end] = weight;

			adjacency_time[start*num_v + end] = time;
		}
	}


	int src;
	cin>>src;
	int dest;
	cin>>dest;


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


/*

10 15
0 1 0 1 1
8 0 0 1 1
4 8 1 1 1
3 4 0 3 2
3 9 1 4 1
0 6 0 1 1
7 5 1 2 1
8 5 1 2 1
2 3 0 2 2
2 1 1 1 1
1 3 0 3 1
1 4 0 1 1
9 7 1 3 1
5 1 0 5 2
6 5 1 1 2
3 5



7 9
0 4 1 1 1
1 6 1 1 3
2 6 1 1 1
2 5 1 2 2
3 0 0 1 1
3 1 1 1 3
3 2 1 1 2
4 5 0 2 2
6 5 1 1 2
3 5

*/

