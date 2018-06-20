#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

struct Node
{
	int left;
	int right;
	int index;
	int value;
};

vector<Node> binary;
vector<int> result_in_order;
vector<int> save;


void in_order(Node current)
{
	if((current.index==-1))    return;	

	if(current.left!=-1)    in_order(binary[current.left]);
	result_in_order.push_back(current.index);
	if(current.right!=-1)    in_order(binary[current.right]);
}

bool compare(int a, int b)
{
	return a<b;
}



int main()
{
	int N;
	cin>>N;

	for(int i=0;i<N;i++)
	{
		int temp;
		cin>>temp;
		
		save.push_back(temp);
	}

	sort(save.begin(), save.end(), compare);



	// allocate child to all index;
	for(int i=0;i<N;i++)
	{
		Node temp;
		temp.index = i;
		if(2*i+1<N)
		{
			temp.left = 2*i+1;
		}
		else
		{
			temp.left = -1;
		}

		if(2*i+2<N)
		{
			temp.right = 2*i+2;
		}
		else
		{
			temp.right = -1;
		}


		binary.push_back(temp);
	}
/*
	for(int i=0;i<N;i++)
	{
		cout<<binary[i].index<<" "<<binary[i].left<<" "<<binary[i].right<<endl;
	}
*/

	in_order(binary[0]);

//	for(int i=0;i<N;i++)    cout<<result_in_order[i]<<" ";
//	cout<<endl;

	for(int i=0;i<N;i++)
	{
		int index = result_in_order[i];
		binary[index].value = save[i];
	}

	for(int i=0;i<N;i++)
	{
		cout<<binary[i].value;
		if(i!=N-1)    cout<<" ";
	}


	return 0;
}




