#include<algorithm>
#include<climits>
#include<iostream>
#include<vector>
using namespace std;


int C2; // city must save;
int num_v;
vector<int> rescue;
vector<int> adjacency_matrix;
vector<int> dist;
vector<bool> sptSet;
vector<int> num_path;
vector<int> max_rescue;



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

	}
  	
	dist[src] = 0; // Distance of source vertex from itself is always 0
	num_path[src] = 1;
	max_rescue[src] = rescue[src];
  
	for (int i=0;i<num_v;i++)
	{
		int min_index = minDistance();		
		sptSet[min_index] = true; // Mark the picked vertex as processed

		for (int j=0;j<num_v;j++)
		{			
			if (!sptSet[j] && get_weight(min_index, j) && dist[min_index]!=INT_MAX)
			{
				if(dist[min_index] + get_weight(min_index, j) < dist[j])
				{
					dist[j] = dist[min_index] + get_weight(min_index, j);
					num_path[j] = num_path[min_index];
					max_rescue[j] = max_rescue[min_index] + rescue[j];
				}
				else if(dist[min_index] + get_weight(min_index, j)==dist[j])
				{
					num_path[j] = num_path[j] + num_path[min_index];
					if(max_rescue[min_index] + rescue[j] > max_rescue[j])
					{
						max_rescue[j] = max_rescue[min_index] + rescue[j];
					}
				}
			}
		}
	}

}





int main()
{
	int N; // num of cities;
	cin>>N;

	num_v = N;
	dist.resize(num_v);
	sptSet.resize(num_v);
	

	int M; // num of roads;
	cin>>M;
	int C1; // city current in;	
	cin>>C1;
	cin>>C2;


	rescue.resize(num_v);
	num_path.resize(num_v);
	max_rescue.resize(num_v);
	for(int i=0;i<N;i++)
	{
		cin>>rescue[i];
		num_path[i] = 0;
		max_rescue[i] = 0;
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

	
	dijkstra(C1);
	
	cout<<num_path[C2]<<" "<<max_rescue[C2];


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


