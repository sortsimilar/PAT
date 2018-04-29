#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;


struct node
{
	int left;
	int right;
	int name;
	int value;
};

vector<int> sequence_name;
vector<node> binary;

void inorder(node current)
{
	if((current.name==-1))    return;	

	if(current.left!=-1)    inorder(binary[current.left]);
//	cout<<current.name<<" ";
	sequence_name.push_back(current.name);
	if(current.right!=-1)    inorder(binary[current.right]);
}



int main()
{
	// input process ////////////////////////////////////////
	int N;
	cin>>N;

	
	vector<int> sequence_value(N);
	for(int i=0;i<N;i++)
	{
		node temp;
		cin>>temp.left;
		cin>>temp.right;
		temp.name = i;
		binary.push_back(temp);
	}

	for(int i=0;i<N;i++)
	{
		cin>>sequence_value[i];
	}

	// sort sequence value;
	sort(sequence_value.begin(), sequence_value.end());

	// get sequence of binary search tree;
	inorder(binary[0]);


//	for(int i=0;i<sequence_name.size();i++)    cout<<sequence_name[i]<<" ";

	// give value to name;
	for(int i=0;i<N;i++)
	{
		int temp = sequence_name[i];
		binary[temp].value = sequence_value[i];
	}

//	for(int i=0;i<N;i++)    cout<<binary[i].value<<" "; // output value according to node number;
	// output level order traversal;
	vector<int> current_layer;
	vector<int> next_layer;
	vector<int> level_order;
	current_layer.push_back(0);
	level_order.push_back(0);
	if(binary[0].left != -1)    next_layer.push_back(binary[0].left);
	if(binary[0].right != -1)    next_layer.push_back(binary[0].right);

	while(next_layer.size() != 0)
	{
		current_layer.clear();
		for(int i=0;i<next_layer.size();i++)
		{
			current_layer.push_back(next_layer[i]);
			level_order.push_back(next_layer[i]);
		}

		next_layer.clear();
		for(int i=0;i<current_layer.size();i++)
		{
			int temp = current_layer[i];
			if(binary[temp].left != -1)    next_layer.push_back(binary[temp].left);
			if(binary[temp].right != -1)    next_layer.push_back(binary[temp].right);
		}
	}

	for(int i=0;i<N;i++)    
	{
		cout<<binary[level_order[i]].value;
		if(i != N-1)    cout<<" ";
	}

	return 0;
}
















