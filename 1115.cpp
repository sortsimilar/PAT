#include<iostream>
#include<vector>
using namespace std;

struct Node
{
	int name;
	int value;
	int left;
	int right;
	int level;
};

vector<Node> binary;
vector<int> level_sequence;
vector<int> hash_level;

void level_order(int root)
{
	vector<int> q;
	q.push_back(root);
	binary[root].level = 0;

	while(!q.empty())
	{
		int current = q[0];
		q.erase(q.begin());
		level_sequence.push_back(current);

		if(hash_level.size() <= binary[current].level)
		{
			hash_level.push_back(1);
		}
		else
		{
			hash_level[binary[current].level]++;
		}


		if(binary[current].left != -1)
		{
			q.push_back(binary[current].left);
			binary[binary[current].left].level = binary[current].level + 1;
		}

		if(binary[current].right != -1)    
		{
			q.push_back(binary[current].right);
			binary[binary[current].right].level = binary[current].level + 1;
		}
	}
}




int main()
{
	int N;
	cin>>N;	

	binary.resize(N);
	for(int i=0;i<binary.size();i++)
	{
		cin>>binary[i].value;
		binary[i].name = i;
		binary[i].left = -1;
		binary[i].right = -1;
	}

	for(int i=1;i<N;i++)
	{
		int y;
		int x = binary[0].name;

		while(x != -1)
		{
			y = x;
			if(binary[i].value <= binary[x].value)
			{
				x = binary[x].left;
			}
			else
			{
				x = binary[x].right;
			}
		}
	
		// insert progress; 
		if(binary[i].value <= binary[y].value)
		{
		    binary[y].left = i;
		}
		else
		{
		    binary[y].right = i;
		}
	}

	// get height of binary search tree;
	level_order(0);


	int first = hash_level[hash_level.size()-1];
	int second = hash_level[hash_level.size()-2];
	cout<<first<<" + "<<second<<" = "<<first+second;


	return 0;
}


/*

9
25 30 42 16 20 20 35 -5 28


*/
