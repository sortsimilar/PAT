#include<iostream>
#include<vector>
using namespace std;


// type of node;
struct Node
{
	int key;
	int left;
	int right;
};

vector<Node> binary;
vector<int> level_sequence;
vector<Node> inorder_sequence;

// print level
void level_order(int root)
{
	vector<int> q;
	q.push_back(root);

	while(!q.empty())
	{
		int current = q[0];
		q.erase(q.begin());
		level_sequence.push_back(current);

		if(binary[current].left != -1)    q.push_back(binary[current].left);
		if(binary[current].right != -1)    q.push_back(binary[current].right);
	}
}

// get in-order;
void in_order(Node current)
{
	if(current.key != -1)
	{
		if(current.left != -1)    in_order(binary[current.left]);
		inorder_sequence.push_back(current);
		if(current.right != -1)    in_order(binary[current.right]);
	}
}



int main()
{
	int N;
	cin>>N;
	
	vector<bool> hash_table(N, false);
	
	// build binary tree;
	
	for(int i=0;i<N;i++)
	{
		Node temp;
		temp.key = i;
		char left; 
		char right;
		cin>>left;
		cin>>right;		
		if(left != '-')
		{
			temp.left = left - '0';
			hash_table[temp.left] = true;
		}
		else    temp.left = -1;

		if(right != '-')    
		{
			temp.right = right - '0';
			hash_table[temp.right] = true;
		}
		else    temp.right = -1;


		binary.push_back(temp);
	}

	// swap left and right;
	for(int i=0;i<N;i++)
	{
		int temp = binary[i].left;
		binary[i].left = binary[i].right;
		binary[i].right = temp;
	}

	// find root of binary tree;
	int root = -1;
	for(int i=0;i<N;i++)
	{
		if(hash_table[i]==false)
		{
			root = i;
			break;
		}
	}


	level_order(root);
	for(int i=0;i<level_sequence.size();i++)
	{
		cout<<level_sequence[i];
		if(i!=level_sequence.size()-1)    cout<<" ";
	}

	cout<<endl;


	in_order(binary[root]);
	for(int i=0;i<inorder_sequence.size();i++)
	{
		cout<<inorder_sequence[i].key;
		if(i != inorder_sequence.size()-1)    cout<<" ";
	}


	return 0;
}


/*

8
1 -
- -
0 -
2 7
- -
- -
5 -
4 6

*/

