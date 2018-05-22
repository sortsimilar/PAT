#include<iostream>
#include<vector>
using namespace std;


struct Edge
{
	int first;
	int second;

};

vector<Edge> graph;
vector<bool> matrix;
vector<int> query;

int N; // num of vertices;
int M; // num of edges;

bool test_edge(int first, int second)
{
	int one = (first-1) * N + (second-1);
	int other = (second-1) * N + (first-1);

	if((matrix[one]==false)&&(matrix[other]==false))    return false;
	else    return true;

}



int test_hamil()
{
	if(query.size() != N+1) // case 1: test whether size if correct;
	{
		return false;
	}
	else
	{
		bool edge_in = true; // case 2: test whether all edges in the list;
		for(int i=0;i<query.size()-1;i++)
		{
			int first = query[i];
			int second = query[i+1];
			if(test_edge(first, second)==false)
			{
				edge_in = false;
				break;
			}
		}

		if(edge_in==false)    return false;
		else
		{
			// case 3: test whether frequency is correct;
			vector<int> freq(N);
			for(int i=0;i<N;i++)    freq[i] = 0;

			for(int i=0;i<query.size();i++)
			{
				freq[query[i]-1]++;
			}

			bool flag_freq = true;
	
			if(freq[query[0]-1] != 2)    return false;
			if(query[0] != query[query.size()-1])    return false;
			

			for(int i=1;i<query.size()-1;i++)
			{
				if(freq[query[i]-1] != 1)    return false;
			}


			return true;
		}
	}

}




int main()
{
	
	cin>>N;	
	cin>>M;

// store the edge ////////////////////////////////////////
	vector<Edge> graph;
	for(int i=0;i<M;i++)
	{
		Edge temp;
		cin>>temp.first;
		cin>>temp.second;
		graph.push_back(temp);
	}	

	for(int i=0;i<N*N;i++)
	{
		matrix.push_back(false); // initialize matrix;
	}
	for(int i=0;i<M;i++)
	{
		matrix[(graph[i].first-1) * N + (graph[i].second-1)] = true;
		matrix[(graph[i].second-1) * N + (graph[i].first-1)] = true;
	}



	vector<int> result;
	int K;
	cin>>K;
	for(int i=0;i<K;i++)
	{
		int n;
		cin>>n;

		query.clear(); // clear query;
		for(int j=0;j<n;j++)
		{
			int temp;
			cin>>temp;
			query.push_back(temp);
		}

		result.push_back(test_hamil());
	}


	for(int i=0;i<K;i++)
	{
		if(result[i]==true)    cout<<"YES";
		else    cout<<"NO";

		if(i!=K-1)    cout<<endl;
	}

//	cout<<endl<<matrix.size()<<endl;	
//	cout<<endl<<test_edge(5, 4)<<endl;
//	cout<<endl<<test_hamil()<<endl;

	return 0;
}
