#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

struct Node
{
	int key;
	vector<int> child;

	int height;	// distance between node and root;
	bool leaf; // amount of product;
	
	double data;
};


double P; // unit price given by the root supplier;
double r; // percentage rate of price increment for each distributor or retailer;
vector<Node> tree;

int min_level = 100001;
double min_price;

void tree_dfs(int current)
{
//	cout<<tree[current].key<<" "<<tree[current].height<<endl;

	if(tree[current].leaf == true)
	{
		if(tree[current].height<min_level)
		{
			min_level = tree[current].height;
			min_price = tree[current].data;
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
		temp.leaf = false;
		tree.push_back(temp);
	}


	tree[0].data = P;


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
				tree[i].child.push_back(temp_j);
			}
		}
		else
		{
			tree[i].leaf = true;
		}
	}


	tree_dfs(0);




	int counter = 0;
	for(int i=0;i<N;i++)
	{
//		cout<<tree[i].height<<" "<<tree[i].data<<endl;
		if((tree[i].height==min_level)&&(tree[i].leaf==true))
		{
			counter++;
		}
	}

	
	printf("%.4f", min_price);
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


