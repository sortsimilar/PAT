#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct Node
{  
    int key;  
    Node *left;  
    Node *right;  
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
		if(in_order[i]==pre_order[preStart])
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
	int N; // number of nodes in a tree;
	cin>>N; 

	vector<int> tree_stack;
	for(int i=0;i<2*N;i++)
	{
		string command;
		cin>>command;

		if(command=="Push")
		{
			int value;
			cin>>value;
			pre_order.push_back(value);
			tree_stack.push_back(value);
		}
		else if(command=="Pop")
		{
			int value = tree_stack[tree_stack.size()-1];
			in_order.push_back(value);
			tree_stack.pop_back();
		}

	}

/*
	for(int i=0;i<pre_order.size();i++)    cout<<pre_order[i]<<" ";
	cout<<endl;
	for(int i=0;i<in_order.size();i++)    cout<<in_order[i]<<" ";
*/

	Node *root = build_tree(0, N-1, 0, N-1);

	for(int i=0;i<post_order.size();i++)
	{
		cout<<post_order[i];
		
		if(i != post_order.size()-1)    cout<<" ";
	}

	return 0;
}


/*

6
Push 1
Push 2
Push 3
Pop
Pop
Push 4
Pop
Pop
Push 5
Push 6
Pop
Pop

*/
