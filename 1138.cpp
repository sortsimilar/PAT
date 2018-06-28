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
	if (preStart > preEnd || inStart > inEnd)
	{
		return NULL;
	}


	Node* root = new Node;  

	int k = 0;
	for (int i = inStart; i <= inEnd; i++) 
	{
		if (in_order[i] == pre_order[preStart]) 
		{
			k = i;
			break;
		}
	}

	root->key = pre_order[preStart];
	root->left = build_tree(inStart, k-1, preStart+1, preStart+k-inStart);
	root->right = build_tree(k+1, inEnd, preStart+(k-inStart)+1, preEnd);

	post_order.push_back(root->key);

	return root;
}



int main()
{
// input process ////////////////////////////////////////
	int N;
	cin>>N;


	for(int i=0;i<N;i++)
	{
		int temp;
		cin>>temp;
		pre_order.push_back(temp);
	}

	for(int i=0;i<N;i++)
	{
		int temp;
		cin>>temp;
		in_order.push_back(temp);
	}


	build_tree(0, N-1, 0, N-1);

/*
	for(int i=0;i<N;i++)
	{
		cout<<post_order[i]<<" ";
	}
*/

	cout<<post_order[0];

	return 0;
}

/*
7
1 2 3 4 5 6 7
2 3 1 5 4 7 6
*/

