#include<iostream>
#include<vector>

using namespace std;

struct Node
{
	int index;
	string data;
	int left;
	int right;
};

vector<Node> binary;
int root;

void in_order(Node current)
{
	if((current.index==-1))    return;	

	if(((current.left!=-1)||(current.right!=-1))&&(current.index!=root))
	{
		cout<<"(";
	}	

	if(current.left!=-1)
	{		
		in_order(binary[current.left]);
	}

	cout<<current.data;

	if(current.right!=-1)    
	{
		in_order(binary[current.right]);
	}

	if(((current.left!=-1)||(current.right!=-1))&&(current.index!=root))
	{
		cout<<")";
	}	

}


int main()
{
	int N; // total number of nodes in the syntax tree;
	cin>>N; 


	vector<bool> hash_table(N, false);

	for(int i=0;i<N;i++)
	{
		Node temp;
		temp.index = i;
		cin>>temp.data;
		cin>>temp.left;
		cin>>temp.right;

		if(temp.left!=-1)
		{
			temp.left = temp.left - 1;
			hash_table[temp.left] = true;
		}
		if(temp.right!=-1)	
		{
			temp.right = temp.right - 1;
			hash_table[temp.right] = true;
		}

		binary.push_back(temp);
	}
	
	
	for(int i=0;i<N;i++)
	{
		if(hash_table[i]==false)
		{
			root = i;
			break;
		}
	}


//	cout<<root<<endl;
/*
	for(int i=0;i<N;i++)
	{

		cout<<i<<" "<<binary[i].data<<" "<<binary[i].left<<" "<<binary[i].right<<endl;

	}
*/


	in_order(binary[root]);




	return 0;
}




