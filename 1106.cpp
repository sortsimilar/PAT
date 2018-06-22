#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

struct Node
{
	int key;
	int parent;
	int height;	// distance between node and root;
	bool leaf ; // test whether node is leaf;
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

	return height-1;
}





int main()
{
	int N; // total number of the members in the supply chain
	cin>>N;
	double P; // price given by the root supplier;
	cin>>P;
	double r; // percentage rate of price increment for each distributor or retailer;
	cin>>r;

// initialize tree node;
	for(int i=0;i<N;i++)
	{
		Node temp;
		temp.key = i;
		temp.parent = -1;
		temp.height = 0;
		temp.leaf = false;
		tree.push_back(temp);
	}


	for(int i=0;i<N;i++)
	{
		int K;
		cin>>K;
		
		if(K != 0)
		{
			for(int j=0;j<K;j++)
			{
				int temp_j;
				cin>>temp_j;
				tree[temp_j].parent = i;
			}
		}
		else
		{
			tree[i].leaf = true;
		}

	}

	// calculate height for each leaf;
	int min_height = N+1;
	for(int i=0;i<N;i++)
	{
		if(tree[i].leaf==true)
		{
			tree[i].height = get_height(i);
//			cout<<tree[i].height<<endl;

			if(tree[i].height <= min_height)
			{
				min_height = tree[i].height;
			}
		}

	}	


//	cout<<min_height<<endl;
	int counter = 0;
	for(int i=0;i<N;i++)
	{
		if(tree[i].height==min_height)
		{
			counter++;
		}
	}

	double sum = P;
	for(int i=0;i<counter;i++)
	{
		sum = sum * (1.0 + r/100.0);
	}

	printf("%.4f", sum);
	cout<<" "<<counter;

	return 0;
}



