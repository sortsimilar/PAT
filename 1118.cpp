#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> father(10001, -1);
vector<bool> bird(10001, false);
vector<bool> root(10001, false);
vector<int> birds;


int find_root(int x)
{
	if (father[x] < 0)    return x;
	else    return father[x] = find_root(father[x]);
}


void union_set(int s1, int s2)
{
	int r1 = find_root(s1);
	int r2 = find_root(s2);

	if(r1 != r2)    father[r1] = r2;
}


int main()
{
	int N;
	cin>>N;


	for(int i=0;i<N;i++)
	{
		int K;
		cin>>K;

		int first_id;
		cin>>first_id;

		if(bird[first_id]==false)
		{
			bird[first_id] = true;
			birds.push_back(first_id);
		}
		
		
		for(int j=1;j<K;j++)
		{
			int current_id;
			cin>>current_id;

			if(bird[current_id]==false)
			{
				bird[current_id] = true;
				birds.push_back(current_id);
			}

			union_set(first_id, current_id);
		}

	}
	
	int Q;
	cin>>Q;
	vector<string> result;
	for(int i=0;i<Q;i++)
	{
		int start;
		cin>>start;
		int end;
		cin>>end;

		if(find_root(start)==find_root(end))    result.push_back("Yes");
		else    result.push_back("No");
	}

//	cout<<find_root(10)<<" "<<find_root(3)<<endl;

	int RootCounter = 0;
	for(int i=0;i<birds.size();i++)
	{
		int current_root = find_root(birds[i]);
		if(root[current_root] == false)
		{
			root[current_root] = true;
			RootCounter++;
		}
	}	


	cout<<RootCounter<<" "<<birds.size()<<endl;
	for(int i=0;i<result.size();i++)
	{
		cout<<result[i];
		if(i!=result.size()-1)    cout<<endl;
	}


    return 0;
}


/*

4
3 10 1 2
2 3 4
4 1 5 7 8
3 9 6 4
2
10 5
3 7

*/
