#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

struct Node
{
	int prev;
	int addr;
	int key;
	int next;

	bool flag;
};



vector<Node> linklist(100001);
vector<Node> linklist_origin;
vector<Node> save;


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

// create link list;
void create_list(int head)
{
	int	current = head;
	while(current != -1)
	{	
		Node temp;
		temp.addr = linklist[current].addr;
		temp.key = linklist[current].key;
		temp.next = linklist[current].next;
		linklist_origin.push_back(temp);

		current = linklist[current].next;
	}
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

	
	for(int i=0;i<N;i++)
	{
		Node temp;
		cin>>temp.addr;
		cin>>temp.key;
		cin>>temp.next;
		temp.flag = false;

		save.push_back(temp);
	}

	// initialize link list;	
	for(int i=0;i<linklist.size();i++)
	{
		linklist[i].addr = -1;
		linklist[i].next = -1;
	}

	// allocate link list nodes;
	for(int i=0;i<N;i++)
	{
		int temp = save[i].addr;
		linklist[temp].addr = save[i].addr;
		linklist[temp].key = save[i].key;
		linklist[temp].next = save[i].next;
	}

	//	print link list;
	create_list(head);


	sort(linklist_origin.begin(), linklist_origin.end(), compare);

	cout<<linklist_origin.size()<<" "<<linklist_origin[0].addr<<endl;
	for(int i=0;i<linklist_origin.size();i++)
	{
		cout<<int_to_string(linklist_origin[i].addr)<<" "<<linklist_origin[i].key<<" ";

		if(i != linklist_origin.size()-1)
		{
			cout<<int_to_string(linklist_origin[i+1].addr)<<endl;
		}
		else
		{
			cout<<"-1";
		}
	}

	return 0;
}










