// level order of binary tree;

#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

// type of node;
struct Node
{
	int name;
	int left;
	int right;
	int parent;
	int position;
};


vector<Node> binary;
vector<Node> level_sequence;


int string_to_int(string temp)
{
	int result;
	stringstream ss;
	ss<<temp;
	ss>>result;

	return result;
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
	
	int N;
	cin>>N;

	
	// build binary tree;
	for(int i=0;i<N;i++)
	{
		Node temp;
		temp.name = i;
		string left; 
		string right;
		cin>>left;
		cin>>right;		
		if(left != "-")    temp.left = string_to_int(left);
		else    temp.left = -1;
		if(right != "-")    temp.right = string_to_int(right);
		else    temp.right = -1;

		temp.parent = -1;

		binary.push_back(temp);
	}

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
		int temp = level_sequence[i].name;
		binary[temp].position = i;
	}


	bool flag_complete = true;


	for(int i=0;i<N;i++)
	{
		if(i != root)
		{
//			cout<<binary[i].position<<" "<<binary[binary[i].parent].position<<endl;
			int parent_lilun = (binary[i].position - 1) / 2;
			if(parent_lilun != binary[binary[i].parent].position)
			{
				flag_complete = false;
				break;
			}
		}
	}


	if(flag_complete==true)
	{
		cout<<"YES"<<" "<<level_sequence[N-1].name;
	}
	else
	{
		cout<<"NO"<<" "<<root;
	}



	return 0;
}










