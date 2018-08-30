#include<iostream>
#include<vector>
using namespace std;


struct Node
{
	int key;
	Node* left;
	Node* right;
};


vector<int> pre_order;
vector<int> in_order;
vector<int> post_order;


Node* build_tree(int inStart, int inEnd, int preStart, int preEnd)
{
	if(inStart>inEnd || preStart>preEnd)    return NULL;

	Node* root = new Node;

	int position;
	for(int i=inStart;i<=inEnd;i++)
	{
		if(in_order[i] == pre_order[preStart])
		{
			position = i;
			break;
		}
	}

	
	root->key = pre_order[preStart];
	root->left = build_tree(inStart, position-1, preStart+1, preStart-inStart+position);
	root->right = build_tree(position+1, inEnd, preStart-inStart+position+1, preEnd);
	post_order.push_back(root->key);

	return root;
}


int main()
{
	int N;
	cin>>N;
	
	pre_order.resize(N);
	for(int i=0;i<pre_order.size();i++)
	{
		cin>>pre_order[i];
	}

	in_order.resize(N);
	for(int i=0;i<in_order.size();i++)
	{
		cin>>in_order[i];
	}


	build_tree(0, N-1, 0, N-1);
	cout<<post_order[0];	



	return 0;
}

/*
7
1 2 3 4 5 6 7
2 3 1 5 4 7 6
*/

