#include<iostream>
#include<vector>
using namespace std;

struct Node
{
	int value;
	Node *left;
	Node *right;
	int level;
};


vector<int> level_sum;


Node* build_tree(Node *root, int value, int level)
{
	if(root==NULL)
	{
		root = new Node;
		root->value = value;
		root->level = level;
		root->left = NULL;
		root->right = NULL;

		if(root->level>=level_sum.size())
		{
			level_sum.push_back(1);
		}
		else
		{
			level_sum[root->level]++;
		}
	}
	else
	{
		if(value <= root->value)
		{
			root->left = build_tree(root->left, value, root->level+1);
		}
		else
		{
			root->right = build_tree(root->right, value, root->level+1);
		}
	}

	return root;
}




int main()
{
	int N;
	cin>>N;	

	Node *root = NULL;
	for(int i=0;i<N;i++)
	{
		int value;
		cin>>value;
		root = build_tree(root, value, 0);
	}

	// get height of binary search tree;

	int first = level_sum[level_sum.size()-1];
	int second = level_sum[level_sum.size()-2];
	cout<<first<<" + "<<second<<" = "<<first+second;


	return 0;
}


/*

9
25 30 42 16 20 20 35 -5 28


*/
