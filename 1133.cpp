#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

struct Node{
	int location;
	int prev;
	int addr;
	int key;
	int next;
};

vector<Node> linklist(100001);
vector<Node> locationlist;
int head;

// add prev to linklist;
void add_prev(int head)
{
	int current = head;
	int current_location = 0;
	int prev = -1;

	while(current != -1)
	{
		linklist[current].prev = prev;
		prev = current;
		current = linklist[current].next;		
	}

}

void set_location(int head)
{
	int current = head;
	int current_location = 0;
	while(current != -1)
	{
		linklist[current].location = current_location;
		current_location++;

		current = linklist[current].next;
	}
}

string int_to_string(int addr)
{
	string result;
	stringstream ss;
	ss<<addr;
	ss>>result;


	if(result != "-1")
	{
		int temp = 5 - result.length();
		for(int i=0;i<temp;i++)    result = "0"+result;
	}

	return result;
}

void print_list(int head)
{
	int	current = head;
	while(current != -1)
	{	
		cout<<int_to_string(linklist[current].addr)<<" "<<linklist[current].key<<" "<<int_to_string(linklist[current].next);
		if(linklist[current].next != -1)    cout<<endl;

		current = linklist[current].next;
	}
}

void move_element(int dest_addr, int moved_addr)
{
	// take moved element out;
	int prev_moved = linklist[moved_addr].prev;
	int next_moved = linklist[moved_addr].next;

//	cout<<next_moved<<endl;

	linklist[prev_moved].next = next_moved;
    if(next_moved!=-1)    linklist[next_moved].prev = prev_moved; // consider last element;


	if(dest_addr != head)    linklist[linklist[dest_addr].prev].next = moved_addr;
	else    head = moved_addr;
	linklist[moved_addr].next = dest_addr;

	linklist[moved_addr].prev = linklist[dest_addr].prev;
	linklist[dest_addr].prev = moved_addr;	

}





int main()
{	
	cin>>head;
	int N;
	cin>>N;
	int K;
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

	// initialize linklist;	
	for(int i=0;i<linklist.size();i++)
	{
		linklist[i].addr = -1;
		linklist[i].next = -1;
	}

	for(int i=0;i<N;i++)
	{
		int temp = save[i].addr;
		linklist[temp].addr = save[i].addr;
		linklist[temp].key = save[i].key;
		linklist[temp].next = save[i].next;
	}
	// add prev to linklist;
	add_prev(head);

	// set location for linklist;
	set_location(head);
	
//	cout<<endl;
//	print_list(head);




//	move_element(12309, 33218); // learn how to move element

	// location the first non-negative;
	int non_negative = -1;
	int current = head;	
	while(current != -1)
	{
		if(linklist[current].key >= 0)
		{
			non_negative = current;
			break;
		}
		else    current = linklist[current].next;		
	}

	vector<int> negative_addr;
	if(non_negative != -1)
	{
		current = non_negative;
		while(current != -1)
		{
			if(linklist[current].key < 0)    negative_addr.push_back(current);
	
			current = linklist[current].next;
		}
	}


//	cout<<endl<<non_negative<<endl;

// test negative;
//	for(int i=0;i<negative_addr.size();i++)    cout<<linklist[negative_addr[i]].key<<endl;

	for(int i=0;i<negative_addr.size();i++)
	{
		move_element(non_negative, negative_addr[i]);
	}
	set_location(head);

	int beyond = -1;
	current = head;
	while(current != -1)
	{
		if(linklist[current].key > K)
		{
			beyond = current;
			break;
		}
		else current = linklist[current].next;
	}

//	cout<<endl<<beyond<<endl;


	vector<int> in_range;
	if(beyond != -1)
	{
		current = beyond;
		while(current != -1)
		{
			if((linklist[current].key>=0)&&(linklist[current].key<=K))
			{
				in_range.push_back(current);				
			}
			current = linklist[current].next;
		}
	}

	for(int i=0;i<in_range.size();i++)
	{
		move_element(beyond, in_range[i]);
	}


	// try to print linklist;
//	cout<<endl;
	print_list(head);

	// try to move linklist element forward;
//	cout<<endl;	


	return 0;
}
