#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

struct Node
{
	int key;
	int parent;
	int weight;	// distance between node and root;
	bool leaf; // judge whether node is leaf or not;

	int length; // distance between leaf to root;
	vector<int> path; // path from root to leaf;
};

struct Path
{
	vector<int> one_path;

};


vector<Node> tree;
vector<Path> result;

int get_distance(int index)
{
	int distance = 0;
	int current = index;
	while(current != -1)
	{
		distance = distance + tree[current].weight;
		tree[index].path.insert(tree[index].path.begin(), tree[current].weight);

		current = tree[current].parent;
	}

	return distance;
}

bool compare(Path first, Path second)
{
	int size;
	if(first.one_path.size()<second.one_path.size())
	{
		size = first.one_path.size();
	}
	else
	{
		size = second.one_path.size();
	}

	bool flag = false;

	for(int i=0;i<size;i++)
	{
		if(first.one_path[i]>second.one_path[i])
		{
			flag = true;
			break;
		}
		else if(first.one_path[i]<second.one_path[i])
		{
			flag = false;
			break;
		}
	}

	return flag;
}


int main()
{
	int N; // number of nodes in a tree;
	cin>>N; 
	int M; // number of non-leaf nodes;
	cin>>M;
	int S; // given weight number; positive; 
	cin>>S;

	// initialize tree node;
	for(int i=0;i<N;i++)
	{
		Node temp;
		temp.key = i;
		temp.parent = -1;
		temp.leaf = true;
		cin>>temp.weight;
		tree.push_back(temp);
	}

	for(int i=0;i<M;i++)
	{
		int ID;
		cin>>ID;

		tree[ID].leaf = false;

		int K;
		cin>>K;
		
		for(int j=0;j<K;j++)
		{
			int temp_j;
			cin>>temp_j;
			tree[temp_j].parent = ID;
		}

	}


	for(int i=0;i<N;i++)
	{
		if(tree[i].leaf == true)
		{
			int temp = get_distance(i);
			if(temp==S)
			{
				Path temp_path;
				for(int j=0;j<tree[i].path.size();j++)
				{
		//			cout<<tree[i].path[j]<<" ";
					temp_path.one_path.push_back(tree[i].path[j]);
				}
		//		cout<<endl;

				result.push_back(temp_path);
			}
		}
	}

	sort(result.begin(), result.end(), compare);

	for(int i=0;i<result.size();i++)
	{
		for(int j=0;j<result[i].one_path.size();j++)
		{
			cout<<result[i].one_path[j];
			
			if(j!=result[i].one_path.size()-1)    cout<<" ";
		}

		if(i!=result.size()-1)    cout<<endl;
	}



	return 0;
}






