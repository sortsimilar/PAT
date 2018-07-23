#include<algorithm>
#include<climits>
#include<iostream>
#include<sstream>
#include<stdio.h>
#include<string>
#include<vector>
using namespace std;


struct Edge
{
	string start;
	string end;
	int weight;
};


struct Station
{
	int index;
	int min_distance;
	int total_distance;	
};



int num_v; // Number of vertices in the graph
vector<Edge> store_edge;
vector<int> dist; 
vector<bool> sptSet;
vector<int> previous;
vector<int> adjacency_matrix;

vector<Station> result;


int string_to_id(string s, int num_house)
{
	if(s[0]!='G') // house id;
	{
		int result;
		stringstream ss;
		ss<<s;
		ss>>result;

		return result;
	}
	else
	{
		int result;
		s.erase(0, 1);
		stringstream ss;
		ss<<s;
		ss>>result;
		result = result + num_house;

		return result;
	}
}


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
  
	// Initialize all distances as INFINITE and stpSet[] as false
	for (int i=0;i<num_v;i++)
	{
        dist[i] = INT_MAX;
		sptSet[i] = false;
		previous[i] = -1;
	}
  
	// Distance of source vertex from itself is always 0
	dist[src] = 0;
  
	// Find shortest path for all vertices
	for (int i=0;i<num_v;i++)
	{
		// Pick the minimum distance vertex from the set of vertices not
		// yet processed. u is always equal to src in the first iteration.
		int u = minDistance();

		// Mark the picked vertex as processed
		sptSet[u] = true;

		// Update dist value of the adjacent vertices of the picked vertex.
		for (int v=0;v<num_v;v++)
		{
			// Update dist[v] only if is not in sptSet, there is an edge from 
			// u to v, and total weight of path from src to  v through u is 
			// smaller than current value of dist[v]

			if (!sptSet[v] && get_weight(u, v) && dist[u]!=INT_MAX && dist[u]+get_weight(u, v)<dist[v])
			{
				dist[v] = dist[u] + get_weight(u, v);
				previous[v] = u;
			}
		}
	}

}


int print_solution(int src)
{
	for (int i=0;i<num_v;i++)
	{
		cout<<src<<" distance to ";
		cout<<i<<" is "<<dist[i]<<"; path is ";

		int current = i;
		while(current != -1)
		{
			cout<<current<<" ";
			current = previous[current];
		}
		cout<<endl;
	}
}


bool compare(Station a, Station b)
{
	if(a.min_distance!=b.min_distance)    return a.min_distance > b.min_distance;
	else
	{
		if(a.total_distance!=b.total_distance)    return a.total_distance <b.total_distance;
		else
		{
			return a.index < b.index;
		}
	}
}


int main()
{
	int N; // total number of houses;
	cin>>N;
	int M; // total number of the candidate locations for the gas stations;
	cin>>M;

	num_v = N + M;

	dist.resize(num_v);
	sptSet.resize(num_v);
	previous.resize(num_v);



	int K; // number of roads connecting the houses and the gas stations;
	cin>>K;
	int DS; // maximum service range of the gas station;
	cin>>DS;

	int num_e = K;
	store_edge.resize(num_e);
	for(int i=0;i<num_e;i++)
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


//	cout<<string_to_id("G3", N);

	// save current amp in adjacency matrix;
	for(int i=0;i<num_e;i++)
	{
		int start = string_to_id(store_edge[i].start, N) - 1;
		int end = string_to_id(store_edge[i].end, N) - 1;

		adjacency_matrix[start*num_v + end] = store_edge[i].weight;
		adjacency_matrix[start + end*num_v] = store_edge[i].weight;
	}

/*
	for(int i=0;i<adjacency_matrix.size();i++)
	{
		cout<<adjacency_matrix[i]<<" ";
	}
*/
/*
	dijkstra(string_to_id("G1", N)-1);
	print_solution(string_to_id("G1", N)-1);

	cout<<endl;

	dijkstra(string_to_id("G3", N)-1);
	print_solution(string_to_id("G3", N)-1);
*/



	for(int i=0;i<M;i++)
	{
		dijkstra(N+i);
//		print_solution(N+i);

//		cout<<endl;

		bool flag = true;
		for(int j=0;j<N;j++)
		{
			if(dist[j]>DS)
			{
				flag = false;
				break;
			}
		}

		if(flag==true)
		{
			Station temp;

			temp.index = i + 1;

			temp.min_distance = dist[0];
			temp.total_distance = 0;
			for(int j=0;j<N;j++)
			{
				temp.total_distance += dist[j];

				if(dist[j]<temp.min_distance)
				{
					temp.min_distance = dist[j];
				}
			}

			result.push_back(temp);

		}
	}

	if(result.size()!=0)
	{
		sort(result.begin(), result.end(), compare);

		cout<<"G"<<result[0].index<<endl;

		cout<<result[0].min_distance<<".0 ";

		double average = double (result[0].total_distance) / double (N);

		printf("%.1f", average);
	}
	else    cout<<"No Solution";



	return 0;
}








