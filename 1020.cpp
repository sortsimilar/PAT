#include<iostream>  
#include<vector>  
using namespace std;  
      
struct Node
{  
    int key;  
    Node* left;  
    Node* right;  
};  

vector<int> post_order;
vector<int> in_order;

vector<int> result;  
    
Node* build_tree(int postStart, int postEnd, int inStart, int inEnd)
{  
    if (postStart > postEnd)
	{  
        return NULL;  
    }  
  
    Node * root = new Node;  
    //查找后序队列中，最后一个数据在中序队列中的位置  
    int i;  
    for (i = inStart; i <= inEnd; i++)
	{  
        if (in_order[i] == post_order[postEnd])
		{  
            //找到了，中序队列中第i个位置就是的  
            break;  
        }  
      
    }  
    //中序队列中距离的起始位置的个数，即第i个位置为根结点，左边num个是它的左子树的个数  
    root->key = post_order[postEnd];  
    root->left = build_tree(postStart, postStart-inStart+i-1, inStart, i-1);   
    root->right = build_tree(postStart-inStart+i, postEnd-1, i+1, inEnd);  
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
    q.push_back(root);  


    while (!q.empty())
	{
		Node* current = q[0];
		q.erase(q.begin());
		
		result.push_back(current->key); 
  
        if (current->left != NULL)    q.push_back(current->left);//左子树入队    
        if (current->right != NULL)   q.push_back(current->right);//右子树入队  

    }
	  
    return ;  
}  
      
int main()
{  
	int N;
	cin>>N;  

    //后序序列  
    for (int i = 0; i<N; i++)
	{  
		int temp;
		cin>>temp;
		post_order.push_back(temp);
    }  
    //中序序列  
    for (int i = 0; i<N; i++)
	{  
		int temp;
		cin>>temp;
		in_order.push_back(temp);
    }  
    //根据后序和中序序列建二叉树  
    Node* root = build_tree(0, N-1, 0, N-1);  
    //层次遍历二叉树  
    level_order(root, N);  

	for(int i=0;i<N;i++)
	{
		cout<<result[i];
		if(i!=N-1)    cout<<" ";
	}
  
    return 0;  
}  




