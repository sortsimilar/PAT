#include<iostream>  
#include<vector>  
using namespace std;  
      
struct Node
{  
    int key;  
    Node* left;  
    Node* right;  

	int level;
};

struct NodeResult
{
	int key;
	int level;
};  

struct CurrentLevel
{
	int level;
	vector<int> level_member;
};

vector<int> post_order;
vector<int> in_order;

vector<int> current_level_order;


vector<NodeResult> level_sequence;  
    
Node* build_tree(int inStart, int inEnd, int postStart, int postEnd)
{  
    if (postStart > postEnd)
	{  
        return NULL;  
    }  
  
    Node * root = new Node;  
    //查找后序队列中，最后一个数据在中序队列中的位置  
    int position;  
    for (int i=inStart; i<=inEnd; i++)
	{  
        if (in_order[i] == post_order[postEnd])
		{  
            //找到了，中序队列中第i个位置就是的
			position = i;  
            break;  
        }  
      
    }  
    //中序队列中距离的起始位置的个数，即第i个位置为根结点，左边num个是它的左子树的个数  
    root->key = post_order[postEnd];  
    root->left = build_tree(inStart, position-1, postStart, postStart-inStart+position-1);   
    root->right = build_tree(position+1, inEnd, postStart-inStart+position, postEnd-1);  
    return root;  
}  
      
      
      
//层次遍历二叉树  
void level_order(Node * root,int totalNode)
{  
    if (root == NULL)
	{  
        return;  
    }  

	vector<Node*> q;  
	root->level = 0;
    q.push_back(root);  


    while (!q.empty())
	{
		Node* current = q[0];


		NodeResult temp;
		temp.key = current->key;
		temp.level = current->level;
		
		level_sequence.push_back(temp); 

		q.erase(q.begin());
		
		
	    if (current->left != NULL)    
		{
			current->left->level = current->level + 1;
			q.push_back(current->left);//左子树入队    
		}

	    if (current->right != NULL)   
		{
			current->right->level = current->level + 1;
			q.push_back(current->right);//右子树入队  
		}
		

    }
	  
    return ;  
}  
      




int main()
{  
	int N;
	cin>>N;  
    
    //中序序列  
    for (int i = 0; i<N; i++)
	{  
		int temp;
		cin>>temp;
		in_order.push_back(temp);
    }  

	//后序序列  
    for (int i = 0; i<N; i++)
	{  
		int temp;
		cin>>temp;
		post_order.push_back(temp);
    }  


    //根据后序和中序序列建二叉树  
    Node* root = build_tree(0, N-1, 0, N-1);  
    //层次遍历二叉树  
    level_order(root, N);  


	int total_level = level_sequence[level_sequence.size()-1].level;

	vector<CurrentLevel> zigzag;
	zigzag.resize(total_level+1);
	for(int i=0;i<level_sequence.size();i++)
	{
		int current_level = level_sequence[i].level;
		if(current_level % 2 == 1)
		{
			zigzag[current_level].level_member.push_back(level_sequence[i].key);
		}
		else
		{
			zigzag[current_level].level_member.insert(zigzag[current_level].level_member.begin(), level_sequence[i].key);
		}
	}

	for(int i=0;i<total_level+1;i++)
	{
		for(int j=0;j<zigzag[i].level_member.size();j++)
		{
			cout<<zigzag[i].level_member[j];
			if(j!=zigzag[i].level_member.size()-1)    cout<<" ";
		}
		if(i!=total_level)    cout<<" ";
	}



    return 0;  
}  


/*

8
12 11 20 17 1 15 8 5
12 20 17 11 15 8 5 1

*/

