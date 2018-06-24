#include<iostream>
#include<vector>
using namespace std;


struct Node
{
	int left;
	int right;
	int name;
	int parent;
};

vector<int> post_order;
vector<int> in_order;
vector<Node> binary;
vector<Node> level_sequence;



int build_tree(int inStart, int inEnd, int postStart, int postEnd)
{
	if (inStart > inEnd || postStart > postEnd)
	{
		return -1;
	}

	int root = post_order[postEnd];

	int k = 0;
	for (int i = 0; i < in_order.size(); i++) 
	{
		if (in_order[i] == root) 
		{
			k = i;
			break;
		}
	}

	binary[root].left = build_tree(inStart, k - 1, postStart, postStart + k - (inStart + 1));
	// Becuase k is not the length, it it need to -(inStart+1) to get the length
	binary[root].right = build_tree(k + 1, inEnd, postStart + k- inStart, postEnd - 1);
	// postStart+k-inStart = postStart+k-(inStart+1) +1


	return root;
}


// print level
void level_order(Node root, int level)
{
	if(level == 1)    level_sequence.push_back(root);
	else if(level > 1)
	{
		if(root.left != -1)    level_order(binary[root.left], level-1); 
		if(root.right != -1)    level_order(binary[root.right], level-1);
	}
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
		post_order.push_back(temp-1);
	}

	for(int i=0;i<N;i++)
	{
		int temp;
		cin>>temp;
		in_order.push_back(temp-1);
	}

// initialize binary tree;
	for(int i=0;i<N;i++)
	{
		Node temp;
		temp.name = i;
		temp.parent = -1;
		binary.push_back(temp);
	}


	build_tree(0, N-1, 0, N-1);


// set parent for every node;
	for(int i=0;i<N;i++)
	{
		int left = binary[i].left;
		int right = binary[i].right;

		if(left != -1)    binary[left].parent = i;
		if(right != -1)    binary[right].parent = i;

	}

// find height of binary tree
	int root = -1;
	int height = 0;	
	for(int i=0;i<N;i++)
	{
		int current_node = i;
		int current_height = 0;
		while(current_node != -1)
		{
			current_height++;
			root = current_node;
			current_node = binary[current_node].parent;
		}

		if(height<current_height)    height = current_height;
	}


// get level order for each level;
	for(int i=1;i<=height;i++)
	{
		level_order(binary[root], i);
	}

	// output result of level order;
	for(int i=0;i<level_sequence.size();i++)
	{
		cout<<level_sequence[i].name+1;
		if(i != level_sequence.size()-1)    cout<<" ";
	}




	return 0;
}

/*
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7
*/

