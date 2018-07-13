#include<algorithm>
#include<iostream>
#include<map>
#include<string>
#include<vector>

using namespace std;

struct Node
{
	string Name1;
	string Name2;
	int time;
};

struct ResultNode
{
	string head_gang;
	int size_gang;
};

vector<Node> save;
map<string, int> string_to_int;
map<int, string> int_to_string;
int idNumber = 1;
int num_v; // number of vertices
vector<int> adjacency_matrix;
vector<int> weight;
vector<bool> visited;
vector<int> cluster_member;

struct each_cluster
{
	int total_weight;
	vector<int> cluster_member;
};

vector<each_cluster> clusters;
vector<ResultNode> result;


int trans_func(string s) 
{
    if(string_to_int[s] == 0) 
	{
        string_to_int[s] = idNumber;
        int_to_string[idNumber] = s;
        return idNumber++;
    } 
	else 
	{
        return string_to_int[s];
    }
}


int test_edge(int start, int end)
{
	return adjacency_matrix[(start-1)*num_v+(end-1)];
}

// DFS one range;
void DFS(int i)
{
	visited[i-1] = true;
//	cout<<i<<" ";
	cluster_member.push_back(i);	

	for(int j=1;j<=num_v;j++)
	{
		if(((test_edge(i, j)>0)||(test_edge(j, i)>0))&&(visited[j-1]==false))
		{
			DFS(j);
		}
	}

}

// DFS all map;
void DFSTraverse()
{
	// initialize visited matrix;
	for(int i=1;i<=num_v;i++)
	{
		visited[i-1] = false;
	}


	for(int i=1;i<=num_v;i++)
	{
		if(visited[i-1]==false)
		{
			cluster_member.clear();
			DFS(i);

			each_cluster temp;
			temp.total_weight = 0;
			temp.cluster_member = cluster_member;

			clusters.push_back(temp);
		}
	}
}

bool compare(ResultNode a, ResultNode b)
{
	return a.head_gang < b.head_gang;
}


int main()
{
	int N; // number of phone calls;
	cin>>N;

	int K; // weight threshold;	
	cin>>K;

	save.resize(N);
	for(int i=0;i<N;i++)
	{
		cin>>save[i].Name1;
		cin>>save[i].Name2;
		cin>>save[i].time;
	}

	for(int i=0;i<N;i++)
	{
		trans_func(save[i].Name1);
		trans_func(save[i].Name2);
	}

//	cout<<endl<<idNumber<<endl;

	num_v = string_to_int.size();

// create adjacency matrix;
	for(int i=0;i<num_v*num_v;i++)
	{
		adjacency_matrix.push_back(0);
	}

// save current amp in adjacency matrix;
	weight.resize(N);
	for(int i=0;i<N;i++)
	{
		weight[i] = 0;
	}

	for(int i=0;i<N;i++)
	{
		int start = string_to_int[save[i].Name1] - 1;
		int end = string_to_int[save[i].Name2] - 1;

		weight[start] = weight[start] + save[i].time;
		weight[end] = weight[end] + save[i].time;

		adjacency_matrix[start*num_v + end] = save[i].time;		
	}


// generate visited point;
	visited.resize(num_v);
	for(int i=0;i<num_v;i++)
	{
		visited[i] = false;
	}

// traverse all graph;
	DFSTraverse();

	for(int i=0;i<clusters.size();i++)
	{
		int max = 0;
		for(int j=0;j<clusters[i].cluster_member.size();j++)
		{
			if(weight[clusters[i].cluster_member[j]-1] > weight[clusters[i].cluster_member[max]-1])
			{
				max = j;
			}


			clusters[i].total_weight = clusters[i].total_weight + weight[clusters[i].cluster_member[j]-1];

			if(j==clusters[i].cluster_member.size()-1)
			{
				clusters[i].total_weight = clusters[i].total_weight / 2;

				if((clusters[i].total_weight>K)&&(clusters[i].cluster_member.size()>2))
				{
					ResultNode temp;
					temp.head_gang = int_to_string[clusters[i].cluster_member[max]];
					temp.size_gang = clusters[i].cluster_member.size();
					

					result.push_back(temp);
				}
			}
		}
	}

	cout<<result.size();
	if(result.size()>0)    cout<<endl;
	sort(result.begin(), result.end(), compare);	

	for(int i=0;i<result.size();i++)
	{
		cout<<result[i].head_gang<<" "<<result[i].size_gang;

		if(i!=result.size()-1)    cout<<endl;
	}


	return 0;
}









