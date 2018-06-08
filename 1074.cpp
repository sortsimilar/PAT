#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

// Node of link list;
struct Node
{
	int location;
	int prev;
	int addr;
	int key;
	int next;
};

vector<Node> linklist(100001);
vector<Node> linklist_origin;
vector<Node> linklist_reverse;
vector<Node> stack;

// convert int to string;
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


int main()
{
	int head; // address of the first node;
	cin>>head;
	int N; // total number of nodes;
	cin>>N; 
	int K; // length of the sublist to be reversed;
	cin>>K; 

	vector<Node> save;
	for(int i=0;i<N;i++)
	{
		Node temp;
		cin>>temp.addr;
		cin>>temp.key;
		cin>>temp.next;
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

//	create link list;
	create_list(head);

	
	for(int i=0;i<linklist_origin.size();i++)
	{
//		cout<<linklist_origin[i].addr<<" "<<linklist_origin[i].key<<" "<<linklist_origin[i].next<<endl;
		stack.push_back(linklist_origin[i]);
		if((stack.size()==K))
		{
//			linklist_reverse.push_back(stack[0]);
			for(int j=stack.size()-1;j>=0;j--)
			{
				linklist_reverse.push_back(stack[j]);
			}

			stack.clear();
		}
	}
	for(int i=0;i<stack.size();i++)
	{
		linklist_reverse.push_back(stack[i]);
	}

	
	for(int i=0;i<linklist_reverse.size();i++)
	{
		cout<<int_to_string(linklist_reverse[i].addr)<<" "<<linklist_reverse[i].key<<" ";
		
		if(i!=linklist_reverse.size()-1)
		{
			cout<<int_to_string(linklist_reverse[i+1].addr);
			cout<<endl;
		}
		else
		{
			cout<<"-1";
		}
	}


	return 0;
}

/*
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
*/
