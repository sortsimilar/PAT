#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct Node
{  
    int key;  
    int left;  
    int right;  
}; 

vector<int> tree_stack;
vector<string> command;
vector<int> result;
vector<Node> binary;


void post_order(Node current)
{
	if((current.key==-1))    return;	

	if(current.left!=-1)    post_order(binary[current.left]);	
	if(current.right!=-1)    post_order(binary[current.right]);

	result.push_back(current.key);
}


int main()
{
	int N; // number of nodes in a tree;
	cin>>N; 

	binary.resize(N);
	for(int i=0;i<binary.size();i++)
	{
		binary[i].key = i;
		binary[i].left = -1;
		binary[i].right = -1;
	}

	int root;
	int pop_node;
	for(int i=0;i<2*N;i++)
	{
		string temp_string;
		cin>>temp_string;

		command.push_back(temp_string);		
		

	
		if(temp_string=="Push") // push operation;
		{
			int number;
			cin>>number;


			if(i>0)
			{
				if(command[i-1]=="Push")
				{
					int parent = tree_stack.back();
					binary[parent-1].left = number-1;
				}
				else
				{
					int parent = pop_node;
					binary[parent-1].right = number-1;
				}

			}
			else
			{
				root = number - 1;
			}


			tree_stack.push_back(number);
		}
		else // pop operation;
		{
//			cout<<tree_stack.back();

			pop_node = tree_stack.back();
			tree_stack.pop_back();
		}
	}



//	cout<<root;

	post_order(binary[root]);

	for(int i=0;i<result.size();i++)
	{
		cout<<result[i]+1;

		if(i!=result.size()-1)    cout<<" ";
	}


	return 0;
}



