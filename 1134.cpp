#include<iostream>
#include<string>
#include<vector>
using namespace std;

//vector<int> cover;
int cover[10001];



struct Edge
{
	int first;
	int second;
};

// test whether one edge is covered by vertex cover;
bool test_edge(int first, int second)
{
	if((cover[first]==0)&&(cover[second]==0))    return false;
	else    return true;

}



int main()
{
// input process ///////////////////////////////////////////////
	int N, M;
	cin>>N>>M;

	vector<Edge> graph(M);
	vector<string> result;
	for(int i=0;i<M;i++)
	{
		cin>>graph[i].first;
		cin>>graph[i].second;
	}

	int K;
	cin>>K;

	for(int i=0;i<K;i++)
	{
		int Nv;
		cin>>Nv;

		for(int j=0;j<10001;j++)    cover[j] = 0; // clear cover for every test;		


		for(int j=0;j<Nv;j++)
		{
			int temp;
			cin>>temp;
			cover[temp]++;
		}

		
		// test all edges in vertex set;
		bool flag = true;
		for(int j=0;j<M;j++)
		{
			if(test_edge(graph[j].first, graph[j].second)==false)
			{
				flag = false;
				break;
			}
		}

		if(flag == true)    result.push_back("Yes");
		else    result.push_back("No");

	}

	// output result;
	for(int i=0;i<K;i++)
	{
		cout<<result[i];
		if(i != K-1)    cout<<endl;
	}


	return 0;
}
