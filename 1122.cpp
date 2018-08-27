#include<iostream>
#include<vector>
using namespace std;


int num_v;
vector<bool> adjacency_matrix;
vector<int> query;



bool test_edge(int start, int end)
{
	bool flag = false;

	if(adjacency_matrix[(start-1)*num_v+(end-1)]==true)    flag = true;
	if(adjacency_matrix[(start-1)+(end-1)*num_v]==true)    flag = true;

	return flag;
}



int test_hamil()
{
	if(query.size() != num_v+1) // case 1: test whether size if correct;
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
			vector<int> freq(num_v);
			for(int i=0;i<num_v;i++)    freq[i] = 0;

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
	
	int N; // num of vertices;
	int M; // num of edges;

	cin>>N;
	num_v = N;	
	cin>>M;
	

	for(int i=0;i<N*N;i++)
	{
		adjacency_matrix.push_back(false); // initialize matrix;
	}


	for(int i=0;i<M;i++)
	{
		int start;
		cin>>start;

		int end;
		cin>>end;

		adjacency_matrix[(start-1)*num_v + (end-1)] = true;
		adjacency_matrix[(start-1) + (end-1)*num_v] = true;
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


/*

6 10
6 2
3 4
1 5
2 5
3 1
4 1
1 6
6 3
1 2
4 5
6
7 5 1 4 3 6 2 5
6 5 1 4 3 6 2
9 6 2 1 6 3 4 5 2 6
4 1 2 5 1
7 6 1 3 4 5 2 6
7 6 1 2 5 4 3 1

*/
