#include<iostream>
#include<sstream>
#include<stdio.h>
#include<string>
#include<vector>
using namespace std;


struct Node
{
	int location;
	int prev;
	int addr;
	string key;
	int next;
};


vector<Node> save;
vector<Node> linklist(100001);
vector<Node> linklist_first;
vector<Node> linklist_second;


void create_list(int head)
{
	int	current = head;
	while(current != -1)
	{	
		linklist_first.push_back(linklist[current]);
		current = linklist[current].next;
	}
}

void create_list_second(int head)
{
	int	current = head;
	while(current != -1)
	{	
		Node temp;
		temp.addr = linklist[current].addr;
		temp.key = linklist[current].key;
		temp.next = linklist[current].next;
		linklist_second.push_back(temp);

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

	save.resize(N);
	for(int i=0;i<save.size();i++)	
	{
		cin>>save[i].addr;
		cin>>save[i].key;
		cin>>save[i].next;
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


	create_list(head_first);
	create_list_second(head_second);

	int i=linklist_first.size()-1;
	int j=linklist_second.size()-1;


	if(linklist_first[i].addr != linklist_second[j].addr)
	{
		cout<<"-1";
	}
	else
	{
		while((linklist_first[i].addr == linklist_second[j].addr)&&(i>=0)&&(j>=0))
		{
			i--;
			j--;
		}

		if(linklist_first[i+1].addr != -1)    printf("%05d", linklist_first[i+1].addr);
		else    cout<<"-1";
	}


	return 0;
}






