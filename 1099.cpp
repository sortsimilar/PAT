#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;


struct Node
{
	int left;
	int right;
	int name;
	int value;
};

vector<int> sequence_name;
vector<Node> binary;
vector<int> level_sequence;


void in_order(Node current)
{
	if((current.name==-1))    return;	

	if(current.left!=-1)    in_order(binary[current.left]);
//	cout<<current.name<<" ";
	sequence_name.push_back(current.name);
	if(current.right!=-1)    in_order(binary[current.right]);
}


void level_order(int root)
{
	vector<int> q;
	q.push_back(root);

	while(!q.empty())
	{
		int current = q[0];
		q.erase(q.begin());
		level_sequence.push_back(binary[current].value);

		if(binary[current].left != -1)    q.push_back(binary[current].left);
		if(binary[current].right != -1)    q.push_back(binary[current].right);
	}

}


bool compare(int a, int b)
{
	return a < b;
}





int main()
{
	// input process ////////////////////////////////////////
	int N;
	cin>>N;

	
	binary.resize(N);
	for(int i=0;i<binary.size();i++)
	{
		cin>>binary[i].left;
		cin>>binary[i].right;
		binary[i].name = i;
	}

	vector<int> sequence_value(N);
	for(int i=0;i<N;i++)
	{
		cin>>sequence_value[i];
	}


	// sort sequence value;
	sort(sequence_value.begin(), sequence_value.end(), compare);

	in_order(binary[0]);

	// give value to name;
	for(int i=0;i<N;i++)
	{
		int temp = sequence_name[i];
		binary[temp].value = sequence_value[i];
	}


	level_order(0);

	for(int i=0;i<level_sequence.size();i++)
	{
		cout<<level_sequence[i];

		if(i!=level_sequence.size()-1)    cout<<" ";
	}


	return 0;
}


/*

9
1 6
2 3
-1 -1
-1 4
5 -1
-1 -1
7 -1
-1 8
-1 -1
73 45 11 58 82 25 67 38 42


*/









