#include<iostream>
#include<sstream>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;

// Node of link list;
struct Node
{
	int addr;
	int key;
	int next;
};

vector<Node> linklist(100001);
vector<Node> linklist_reverse;
vector<Node> stack;

int K; // length of the sublist to be reversed;


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


		stack.push_back(temp);
		if((stack.size()==K))
		{
			for(int j=stack.size()-1;j>=0;j--)
			{
				linklist_reverse.push_back(stack[j]);
			}

			stack.clear();
		}

		current = linklist[current].next;
	}
}



int main()
{
	int head; // address of the first node;
	cin>>head;
	int N; // total number of nodes;
	cin>>N; 
	
	cin>>K; 

	// initialize link list;	
	for(int i=0;i<linklist.size();i++)
	{
		linklist[i].addr = -1;
		linklist[i].next = -1;
	}

	// allocate link list nodes;
	for(int i=0;i<N;i++)
	{
		int temp;
		cin>>temp;
		linklist[temp].addr = temp;
		cin>>linklist[temp].key;		
		cin>>linklist[temp].next;

	}

//	create link list;
	create_list(head);

	for(int i=0;i<stack.size();i++)
	{
		linklist_reverse.push_back(stack[i]);
	}

	
	for(int i=0;i<linklist_reverse.size();i++)
	{
		printf("%05d %d ", linklist_reverse[i].addr, linklist_reverse[i].key);
		
		if(i!=linklist_reverse.size()-1)
		{
			printf("%05d\n", linklist_reverse[i+1].addr);
		}
		else
		{
			cout<<"-1";
		}
	}


	return 0;
}

/*
00100 6 3
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
*/
