#include<iostream>
#include<vector>
using namespace std;

struct Node
{
	int key;
	int parent;
	int height;	// distance between node and root;
};

vector<Node> tree;

int get_height(int index)
{
	int height = 0;
	int current = index;
	while(current != -1)
	{
		current = tree[current].parent;
		height++;
	}

	return height;
}




int main()
{
	int N; // total number of family members in the tree;
	cin>>N;

	int M; // number of family members who have children;
	cin>>M;

	// initialize tree node;
	for(int i=0;i<N+1;i++)
	{
		Node temp;
		temp.key = i;
		temp.parent = -1;
		temp.height = 0;
		tree.push_back(temp);
	}

	for(int i=0;i<M;i++)
	{
		int ID;
		cin>>ID;

		int K;
		cin>>K;
		
		for(int j=0;j<K;j++)
		{
			int temp_j;
			cin>>temp_j;
			tree[temp_j].parent = ID;
		}

	}

	// calculate height for each node;
	vector<int> hash_table;
	for(int i=0;i<N+1;i++)
	{
		hash_table.push_back(0);
	}


	for(int i=1;i<N+1;i++)
	{
		tree[i].height = get_height(i);
		hash_table[tree[i].height]++;
	} 

	int number = -1;
	int level = -1;
	for(int i=0;i<hash_table.size();i++)
	{
		if(hash_table[i]>number)
		{
			number = hash_table[i];
			level = i;
		}
	}

	cout<<number<<" "<<level;

	return 0;
}








