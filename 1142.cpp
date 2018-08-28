#include<iostream>
#include<string>
#include<vector>
using namespace std;


int Nv; // number of vertices in the graph;
int Ne; // number of undirected edges;

int K; // size of cluster;
vector<int> cluster;
vector<bool> adjacency_matrix;
vector<bool> visited;
vector<string> result;


bool test_edge(int start, int end)
{
	bool flag = false;

	if(adjacency_matrix[(start-1)*Nv+(end-1)]==true)    flag = true;
	if(adjacency_matrix[(start-1)+(end-1)*Nv]==true)    flag = true;

	return flag;
}

// test whether a cluster is connect or not;
bool test_connect_cluster()
{
	bool flag_cluster = true;

	if(cluster.size()!=1)
	{
		for(int i=0;i<cluster.size();i++)
		{
			for(int j=0;j<cluster.size();j++)
			{
				if((j != i)&&(test_edge(cluster[i], cluster[j])==false))
				{
					flag_cluster = false;
					break;
				}
			}
		}
	}
	else
	{
		flag_cluster = true;
		
	}

	return flag_cluster;

}


int main()
{
	
	cin>>Nv; 	
	cin>>Ne; 

	// create adjacency matrix;
	for(int i=0;i<Nv*Nv;i++)
	{
		adjacency_matrix.push_back(false);
	}

	// save current amp in adjacency matrix;
	for(int i=0;i<Ne;i++)
	{
		int start;
		cin>>start;
		int end;
		cin>>end;

		adjacency_matrix[(start-1)*Nv + (end-1)] = true;
		adjacency_matrix[(start-1) + (end-1)*Nv] = true;
	}


//	cout<<test_edge(5, 7)<<endl;
	
	int M; // num of queries;
	cin>>M;

	for(int m=0;m<M;m++)
	{
		cin>>K; 
		cluster.clear();		
		cluster.resize(K);

		for(int i=0;i<K;i++)
		{
			cin>>cluster[i];

		}


	
		// test whether cluster connect or not;	
		if(test_connect_cluster()==false)
		{
			result.push_back("Not a Clique");
		}
		else
		{

	//		cout<<test_connect_cluster()<<endl;

			vector<bool> hash_table;
			for(int i=0;i<=Nv;i++)
			{
				hash_table.push_back(false);
			}

			for(int i=0;i<cluster.size();i++)
			{
				hash_table[cluster[i]] = true;
			}

		/*			
			for(int i=0;i<hash_table.size();i++)
			{
				cout<<hash_table[i]<<" ";
			}	
		*/


			bool flag_max = true;
		
			for(int i=1;i<=Nv;i++)
			{
				if(hash_table[i]==0)
				{
					cluster.push_back(i);


	//				cout<<i<<" "<<test_connect_cluster()<<endl;

					if(test_connect_cluster()==true)
					{
						flag_max = false;
						break;
					}


					cluster.pop_back();
				}
			}


			if(flag_max==true)    result.push_back("Yes");
			else    result.push_back("Not Maximal");	
	
		}

	}


	for(int i=0;i<result.size();i++)
	{
		cout<<result[i];

		if(i!=result.size()-1)    cout<<endl;
	}



	return 0;
}


/*

8 10
5 6
7 8
6 4
3 6
4 5
2 3
8 2
2 7
5 3
3 4
6
4 5 4 3 6
3 2 8 7
2 2 3
1 1
3 4 3 6
3 3 2 1

*/
