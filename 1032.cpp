#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
using namespace std;


struct Node
{
	bool flag;
	int addr;
	string key;
	int next;
};


int start_addr = -1;
vector<Node> linklist(100001);


void create_list(int head)
{
	int	current = head;
	while(current != -1)
	{	
		linklist[current].flag = true;
		current = linklist[current].next;
	}
}

void create_list_second(int head)
{
	int	current = head;
	while(current != -1)
	{	
		if(linklist[current].flag==true)
		{
			start_addr = current;
			break;
		}

		current = linklist[current].next;
	}
}



int main()
{
	int head_first;
	cin>>head_first;

	int head_second;
	cin>>head_second;

	int N;
	cin>>N;

	// initialize link list;	
	for(int i=0;i<linklist.size();i++)
	{
		linklist[i].addr = -1;
		linklist[i].next = -1;
		linklist[i].flag = false;
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


	create_list(head_first);
	create_list_second(head_second);

	if(start_addr==-1)    cout<<-1;
	else
	{
		printf("%05d", start_addr);
	}


	return 0;
}






