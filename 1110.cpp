#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

// type of node;
struct Node
{
	int key;
	int left;
	int right;
};


int counter = 0;
int last_node = -1;
vector<Node> binary;
vector<int> level_sequence;


int string_to_int(string temp)
{
	int result;
	stringstream ss;
	ss<<temp;
	ss>>result;

	return result;
}


void level_order(int root)
{    

	vector<int> q;  
    q.push_back(root);  


    while (!q.empty())
	{
		int current = q[0];
		q.erase(q.begin());
		
//		level_sequence.push_back(binary[current].key); 

  
        if (current != -1)    
		{
			q.push_back(binary[current].left);   
        	q.push_back(binary[current].right); 
			counter++;
			last_node = current;
		}
		else
		{
			if(counter==binary.size())
			{
				cout<<"YES "<<last_node;
			}
			else
			{
				cout<<"NO "<<root;
			}

			break;
		}
    }
	  
} 





int main()
{
	
	unsigned N;
	cin>>N;

	
	// build binary tree;
	vector<bool> hash_table(N, false);

	for(unsigned i=0;i<N;i++)
	{
		Node temp;
		temp.key = i;
		string left; 
		string right;
		cin>>left;
		cin>>right;		
		if(left != "-")
		{
			temp.left = string_to_int(left);
			hash_table[temp.left] = true;
		}
		else    temp.left = -1;

		if(right != "-")
		{
			temp.right = string_to_int(right);
			hash_table[temp.right] = true;
		}
		else    temp.right = -1;

		binary.push_back(temp);
	}

	// find root of binary tree;
	int root = -1;
	for(unsigned i=0;i<hash_table.size();i++)
	{
		if(hash_table[i]==false)
		{
			root = i;
			break;
		}
	}


	level_order(root);




	return 0;
}










