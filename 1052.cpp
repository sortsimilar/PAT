#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

struct Node
{
	int location;
	int prev;
	int addr;
	int key;
	int next;
};


string int_to_string(int addr)
{
	string result;
	stringstream ss;
	ss<<addr;
	ss>>result;


	if(result != "-1")
	{
		while(result.length() < 5)    result = "0" + result;
	}

	return result;
}


bool compare(Node first, Node second)
{
	return first.key < second.key;
}



int main()
{
	int N; // total number of nodes;
	cin>>N; 
	int head;
	cin>>head;

	vector<Node> save;
	for(int i=0;i<N;i++)
	{
		Node temp;
		cin>>temp.addr;
		cin>>temp.key;
		cin>>temp.next;
		save.push_back(temp);
	}

	sort(save.begin(), save.end(), compare);



	cout<<N<<" "<<save[0].addr<<endl;
	for(int i=0;i<N;i++)
	{
		cout<<int_to_string(save[i].addr)<<" "<<save[i].key<<" ";

		if(i != N-1)
		{
			cout<<int_to_string(save[i+1].addr)<<endl;
		}
		else
		{
			cout<<"-1";
		}
	}

	return 0;
}










