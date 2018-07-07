#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>

using namespace std;

struct Node
{
	vector<int> hobby;
	vector<int> hash_table;
};


int N; // total number of people in a social network;
vector<Node> cluster;
vector<bool> visited;
vector<int> cluster_member;
vector<int> result;

int test_common(int first, int second)
{
	int result = 0;
	for(int i=0;i<cluster[first-1].hash_table.size();i++)
	{
		result = result + cluster[first-1].hash_table[i] * cluster[second-1].hash_table[i];
	}

	return result;
}


// DFS one range;
void DFS(int i)
{
	visited[i-1] = true;
//	cout<<i<<" ";

	cluster_member.push_back(i);

	for(int j=1;j<=N;j++)
	{
		if((test_common(i, j)!=0)&&(visited[j-1]==false))
		{
			DFS(j);
		}
	}

}


// DFS all map;
void DFSTraverse()
{
	// initialize visited matrix;
	for(int i=1;i<=N;i++)
	{
		visited[i-1] = false;
	}


	for(int i=1;i<=N;i++)
	{
		if(visited[i-1]==false)
		{
			cluster_member.clear();
			DFS(i);
//			cout<<cluster_member.size();
			result.push_back(cluster_member.size());
		}
	}
}

bool compare(int first, int second)
{
	return first > second;
}


int main()
{
	
	cin>>N;
	

	cluster.resize(N);	

	for(int i=0;i<N;i++)
	{
		int num;
		string temp;
		cin>>temp;
		temp.erase(temp.end()-1);
		stringstream ss;
		ss<<temp;
		ss>>num;

		cluster[i].hobby.resize(num);
		cluster[i].hash_table.resize(1005);
		for(int j=0;j<1005;j++)
		{
			cluster[i].hash_table[j] = 0;
		}

		for(int j=0;j<num;j++)
		{
			int temp_hobby;
			cin>>temp_hobby;
			cluster[i].hobby[j] = temp_hobby;
			cluster[i].hash_table[temp_hobby]++;
		}
	}

//	cout<<test_common(1, 1);
	
	// generate visited point;
	for(int i=0;i<N;i++)
	{
		visited.push_back(false);
	}


//	DFS(3); // test DFS one range;
	
	DFSTraverse();

	sort(result.begin(), result.end(), compare);

	cout<<result.size()<<endl;
	for(int i=0;i<result.size();i++)
	{
		cout<<result[i];

		if(i!=result.size()-1)    cout<<" ";
	}


	return 0;
}



