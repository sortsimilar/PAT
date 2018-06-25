#include<iostream>
#include<queue>
#include<vector>
using namespace std;


struct Node
{
	int key;
	int left;
	int right;	
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
	for (int i = inStart; i <= inEnd; i++) 
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
void level_order(int root,int totalNode)
{  
    int num = 0;  
    if (root == -1)
	{  
        return;  
    }  
    queue<int> q;  
    q.push(root);  
    while (!q.empty())
	{  
        //出队，然后访问该数据  
        int current = q.front();  
        q.pop();
  
        cout<<binary[current].key+1;
  
        num++;  
        if (num < totalNode)    cout<<" "; 
 
        if (binary[current].left != -1)
		{  
            q.push(binary[current].left);//左子树入队  
        }
  
        if (binary[current].right != -1)
		{  
            q.push(binary[current].right);//右子树入队  
        }  
    }  

    return ;  
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
		temp.key = i;
		temp.parent = -1;
		binary.push_back(temp);
	}


	int root = build_tree(0, N-1, 0, N-1);


	level_order(root, N);

	return 0;
}

/*
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7
*/

