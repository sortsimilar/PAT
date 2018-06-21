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
vector<int> hash_table(100001);
vector<Node> linklist_origin;
vector<Node> result;
vector<Node> remove_element;
vector<Node> save;

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

int abs(int number)
{
	if(number>=0)    return number;
	else    return (0-number);
}




int main()
{
	int head; // address of the first node;
	cin>>head;
	int N; // total number of nodes;
	cin>>N; 
	
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

	//	print link list;
	create_list(head);

/*
	for(int i=0;i<linklist_origin.size();i++)
	{
		cout<<linklist_origin[i].addr<<" "<<linklist_origin[i].key<<" "<<linklist_origin[i].next<<endl;
	}
*/

	// initialize hash table;
	for(int i=0;i<hash_table.size();i++)
	{
		hash_table[i] = 0;
	}

	for(int i=0;i<linklist_origin.size();i++)
	{
		int value = abs(linklist_origin[i].key);
		if(hash_table[value]==0)
		{
			result.push_back(linklist_origin[i]);
			hash_table[value] = 1;
		}
		else
		{
			remove_element.push_back(linklist_origin[i]);
		}

	}
	
	for(int i=0;i<result.size();i++)
	{
		if(i!=result.size()-1)
		{
			cout<<int_to_string(result[i].addr)<<" "<<result[i].key<<" "<<int_to_string(result[i+1].addr)<<endl;
		}
		else
		{
			cout<<int_to_string(result[i].addr)<<" "<<result[i].key<<" "<<"-1";
		}
	}

	if(remove_element.size()!=0)    cout<<endl;
	for(int i=0;i<remove_element.size();i++)
	{
		if(i!=remove_element.size()-1)
		{
			cout<<int_to_string(remove_element[i].addr)<<" "<<remove_element[i].key<<" "<<int_to_string(remove_element[i+1].addr)<<endl;
		}
		else
		{
			cout<<int_to_string(remove_element[i].addr)<<" "<<remove_element[i].key<<" "<<"-1";
		}
	}



	return 0;
}








