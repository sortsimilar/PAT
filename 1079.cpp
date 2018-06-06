#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

struct Node
{
	int key;
	int parent;
	int height;	// distance between node and root;
	int amount; // amount of product;
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
	double P; // unit price given by the root supplier;
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
		temp.amount = -1;
		tree.push_back(temp);
	}

/*
	for(int i=0;i<N;i++)
	{
		cout<<tree[i].key<<" "<<tree[i].parent<<" "<<tree[i].height<<endl;
	}	
*/

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
			int temp;
			cin>>temp;
			tree[i].amount = temp;
		}
	}

	

	double sum = 0;	
	for(int i=0;i<N;i++)
	{
		if(tree[i].amount!=-1)
		{
			int height = get_height(i);
			double result = tree[i].amount * P;
			for(int j=0;j<height;j++)
			{
				result = result * (1.0 + r/100.0);
			}

			sum += result;
			
//			cout<<height<<" "<<tree[i].amount<<endl;
//			cout<<sum<<endl;
		}
	}

	printf("%.1f", sum);



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


