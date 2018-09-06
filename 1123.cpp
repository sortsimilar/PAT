#include<iostream>
#include<vector> 

using namespace std;

// An AVL tree node
struct Node
{
    int key;
    Node *left;
    Node *right;
    int height;
	int index;
};

vector<int> save;
vector<Node*> result;


 
// A utility function to get the height of the tree
int height(Node *N)
{
    if (N == NULL)	return 0;
    return N->height;
}
 
// A utility function to get maximum of two integers
int max(int a, int b)
{
    return (a > b)? a : b;
}
 
/* Helper function that allocates a new node with the given key and
    NULL left and right pointers. */
Node* newNode(int key)
{
    Node* node = new Node;
    node->key   = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;  // new node is initially added at leaf
    return node;
}
 
// A utility function to right rotate subtree rooted with y
// See the diagram given above.
Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;
 
    // Perform rotation
    x->right = y;
    y->left = T2;
 
    // Update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
 
    // Return new root
    return x;
}
 
// A utility function to left rotate subtree rooted with x
// See the diagram given above.
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;
 
    // Perform rotation
    y->left = x;
    x->right = T2;
 
    //  Update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
 
    // Return new root
    return y;
}
 
// Get Balance factor of node N
int getBalance(Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
 
// Recursive function to insert a key in the subtree rooted
// with node and returns the new root of the subtree.
Node* insert(Node* node, int key)
{
    /* 1.  Perform the normal BST insertion */
    if (node == NULL)
        return(newNode(key));
 
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Equal keys are not allowed in BST
        return node;
 
    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left),
                           height(node->right));
 
    /* 3. Get the balance factor of this ancestor
          node to check whether this node became
          unbalanced */
    int balance = getBalance(node);
 
    // If this node becomes unbalanced, then
    // there are 4 cases
 
    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
 
    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
 
    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }
 
    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
 
    /* return the (unchanged) node pointer */
    return node;
}
 

//层次遍历二叉树  
void level_order(Node * root)
{  
    if (root == NULL)
	{  
        return;  
    }  

	vector<Node*> q;  
    q.push_back(root);  

	int counter = 0;

    while (!q.empty())
	{
		Node* current = q[0];
		q.erase(q.begin());
		
		current->index = counter;
		counter++;
		result.push_back(current); 
  
//		cout<<current->key<<" "<<current->index<<endl;

        if (current->left != NULL)    q.push_back(current->left);//左子树入队    
        if (current->right != NULL)   q.push_back(current->right);//右子树入队  

    }
	  
    return ;  
} 



int main()
{
	int N;
	cin>>N;

	save.resize(N);
	for(int i=0;i<N;i++)
	{
		cin>>save[i];
	}


	Node *root = NULL;
 
	for(int i=0;i<save.size();i++)
	{
		root = insert(root, save[i]);
	}
 
	//层次遍历二叉树  
	level_order(root); 


	for(int i=0;i<result.size();i++)
	{
		cout<<result[i]->key;

		if(i!=result.size()-1)    cout<<" ";
		else    cout<<endl;
	}



	bool flag = true;
	for(int i=0;i<result.size();i++)
	{
		int current_index = result[i]->index;
		if(result[i]->left != NULL)
		{
			int left_index = result[i]->left->index;

			if(left_index != current_index*2+1)
			{
				flag = false;
				break;				
			}
		}

		if(result[i]->right != NULL)
		{
			int right_index = result[i]->right->index;

			if(right_index != current_index*2+2)
			{
				flag = false;
				break;
			}
		}		
	} 


	if(flag==true)    cout<<"YES";
	else    cout<<"NO";

	return 0;
}





