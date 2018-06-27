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

vector<int> post_order;
vector<int> in_order;

vector<int> current_level_order;


vector<NodeResult> result;
vector<int> final_result;  
    
Node* build_tree(int postStart, int postEnd, int midStart, int midEnd)
{  
    if (postStart > postEnd)
	{  
        return NULL;  
    }  
  
    Node * root = new Node;  
    //查找后序队列中，最后一个数据在中序队列中的位置  
    int i;  
    for (i = midStart; i <= midEnd; i++)
	{  
        if (in_order[i] == post_order[postEnd])
		{  
            //找到了，中序队列中第i个位置就是的  
            break;  
        }  
      
    }  
    //中序队列中距离的起始位置的个数，即第i个位置为根结点，左边num个是它的左子树的个数  
    int numStart = i - midStart;  
    root->key = post_order[postEnd];  
    root->left = build_tree(postStart, postStart + numStart - 1, midStart , i - 1);   
    root->right = build_tree(postStart + numStart, postEnd - 1, i + 1, midEnd);  
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
		
		result.push_back(temp); 

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


/*
	for(int i=0;i<result.size();i++)
	{
		cout<<result[i].key<<" "<<result[i].level<<endl;
	}
*/


	final_result.push_back(result[0].key);

	vector<int> temp_stack;
	for(int i=1;i<result.size();i++)
	{
		if(result[i].level==result[i-1].level)
		{
			temp_stack.push_back(result[i].key);
		}
		else
		{	
			if(result[i].level % 2 == 0)
			{
				for(int j=0;j<temp_stack.size();j++)
				{
					final_result.push_back(temp_stack[j]);
				}
			}
			else
			{
				for(int j=0;j<temp_stack.size();j++)
				{
					final_result.push_back(temp_stack[temp_stack.size()-1-j]);
				}
			}

			temp_stack.clear();
			temp_stack.push_back(result[i].key);
		}

	}

	if(result[result.size()-1].level % 2 == 1)
	{
		for(int j=0;j<temp_stack.size();j++)
		{
			final_result.push_back(temp_stack[j]);
		}
	}
	else
	{
		for(int j=0;j<temp_stack.size();j++)
		{
			final_result.push_back(temp_stack[temp_stack.size()-1-j]);
		}
	}
  

	for(int i=0;i<final_result.size();i++)
	{
		cout<<final_result[i];
		if(i!=final_result.size()-1)    cout<<" ";
	}


    return 0;  
}  




