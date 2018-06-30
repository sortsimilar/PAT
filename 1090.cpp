#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

struct Node
{
	int key;
	vector<int> child;

	int height;	// distance between node and root;
	
	double data;
};


double P; // unit price given by the root supplier;
double r; // percentage rate of price increment for each distributor or retailer;
vector<Node> tree;

int max_level = -1;
double max_price;

void tree_dfs(int current)
{
//	cout<<tree[current].key<<" "<<tree[current].height<<endl;

	if(tree[current].child.size() == 0)
	{
		if(tree[current].height>max_level)
		{
			max_level = tree[current].height;
			max_price = tree[current].data;
		}
	}

	for(int i=0;i<tree[current].child.size();i++) // childs 存放指向其每個子結點的指標
	{ 
		tree[tree[current].child[i]].height = tree[current].height + 1;
		tree[tree[current].child[i]].data = tree[current].data * (1.0 + r/100.0);
		tree_dfs(tree[current].child[i]);   
    }	
}



int main()
{
	int N; // total number of the members in the supply chain;
	cin>>N;
	
	cin>>P;
	
	cin>>r;

	// initialize tree node;
	for(int i=0;i<N;i++)
	{
		Node temp;
		temp.key = i;
		temp.height = 0;

		tree.push_back(temp);
	}
	

	int root;
	for(int i=0;i<N;i++)
	{
		int temp;
		cin>>temp;
		if(temp!=-1)
		{
			tree[temp].child.push_back(i);
		}
		else
		{
			root = i;
		}
	}

	tree[root].data = P;


/*
	for(int i=0;i<N;i++)
	{
		cout<<i<<" ";
		for(int j=0;j<tree[i].child.size();j++)
		{
			cout<<tree[i].child[j]<<" ";
		}
		cout<<endl;
	}
*/


	tree_dfs(root);


	printf("%.2f", max_price);



	int counter = 0;
	for(int i=0;i<N;i++)
	{
//		cout<<tree[i].height<<" "<<tree[i].data<<endl;
		if((tree[i].height==max_level)&&(tree[i].child.size()==0))
		{
			counter++;
		}
	}

		
	cout<<" "<<counter;



	return 0;
}


/*
10 1.80 1.00
3 2 3 5
1 9
1 4
1 7
0 7
2 6 1
1 8
0 9
0 4
0 3
*/

