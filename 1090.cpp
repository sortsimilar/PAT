#include<iostream>
#include<stdio.h>
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

	return height-1;
}





int main()
{
	int N; // total number of the members in the supply chain;
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
		cin>>temp.parent;
		temp.height = 0;
		tree.push_back(temp);
	}

	int max_height = -1;
	for(int i=0;i<N;i++)
	{
		tree[i].height = get_height(i);
		if(tree[i].height >= max_height)
		{
			max_height = tree[i].height;
		}
	}

	int counter = 0;
	for(int i=0;i<N;i++)
	{
//		cout<<tree[i].key<<" "<<tree[i].parent<<" "<<tree[i].height<<endl;
		if(tree[i].height == max_height)
		{
			counter++;
		}
	}

	double sum = P;
	for(int i=0;i<max_height;i++)
	{
		sum = sum * (1.0 + r/100.0);
	}

	printf("%.2f", sum);
	cout<<" "<<counter;


	return 0;
}






