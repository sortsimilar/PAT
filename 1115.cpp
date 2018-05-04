#include<iostream>
#include<vector>
using namespace std;

struct Node
{
	int name;
	int value;
	int left;
	int right;
	int parent;
};

vector<Node> binary;
int counter = 0;

void level_order(Node root, int level)
{
	if(level==1)    counter++;
	else if(level>1)
	{
		if(root.left != -1)    level_order(binary[root.left], level-1);
		if(root.right != -1)    level_order(binary[root.right], level-1);
	}
}

int main()
{
	int N;
	cin>>N;	

	for(int i=0;i<N;i++)
	{
		Node temp;
		cin>>temp.value;
		temp.name = i;
		temp.parent = -1;
		temp.left = -1;
		temp.right = -1;

		binary.push_back(temp);
	}

	for(int i=1;i<N;i++)
	{
		int y;
		int x = binary[0].name;
		int z = i; // change to i afterwards;

		while(x != -1)
		{
			y = x;
			if(binary[z].value <= binary[x].value)
			{
				x = binary[x].left;
			}
			else
			{
				x = binary[x].right;
			}
		}
	
		// insert progress; 
		if(binary[z].value <= binary[y].value)
		{
		    binary[y].left = z;
			binary[z].parent = y;
		}
		else
		{
		    binary[y].right = z;
			binary[z].parent = y;
		}
	}

	// get height of binary search tree;
	int height = -1;
	for(int i=0;i<N;i++)
	{
		int distance = 0;
		int current_node = i; // change 0 to i afterwards;
	
		while(current_node != -1)
		{
			distance++;
			current_node = binary[current_node].parent;
		}

		if(distance>height)    height = distance;

	}
	
//	cout<<endl<<height<<endl;

	counter = 0;
	level_order(binary[0], height);
	int n1 = counter;

	counter = 0;
	level_order(binary[0], height-1);
	int n2 = counter;

	cout<<n1<<" + "<<n2<<" = "<<n1+n2;


	return 0;
}
