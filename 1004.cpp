#include<iostream>
#include<map>
#include<vector>
using namespace std;


struct Node
{
	int key;
	int level;
	vector<int> child;
};


vector<Node> tree;
vector<Node> result;


void tree_bfs(int root)
{  
    if (root == -1)
	{  
        return;  
    }  

	vector<int> q;  
    q.push_back(root);  


    while (!q.empty())
	{
		int current = q[0];
		q.erase(q.begin());
		
		result.push_back(tree[current]); 

		if(tree[current].child.size()>0)
		{
			for(int i=0;i<tree[current].child.size();i++)
			{
				q.push_back(tree[current].child[i]);
				tree[tree[current].child[i]].level = tree[current].level + 1;
			}
		}

    }
	  
	return;  
} 



int main()
{
	int N;
	cin>>N;
	int M;
	cin>>M;


	tree.resize(102);
	for(int i=0;i<tree.size();i++)
	{
		tree[i].key = i;
		tree[i].level = 0;
	}

	for(int i=0;i<M;i++)
	{
		int ID;
		cin>>ID;

		int K;
		cin>>K;

		tree[ID].child.resize(K);
		for(int j=0;j<K;j++)
		{
			cin>>tree[ID].child[j];
		}
	}

	tree_bfs(1);

	int max_level = result[result.size()-1].level;

	vector<int> hash_table(max_level+1, 0);


	for(int i=0;i<result.size();i++)
	{
//		cout<<result[i].key<<" "<<result[i].level<<endl;

		if(tree[result[i].key].child.size()==0)
		{
			hash_table[result[i].level]++;
		}	
	}

	for(int i=0;i<max_level+1;i++)
	{
		cout<<hash_table[i];
		if(i!=max_level)    cout<<" ";
	}


	return 0;
}







