#include<stdio.h>
#include<string>
#include<vector>
using namespace std;

// Node of link list;
struct Node
{
	int location;
	int addr;
	int key;
	int next;
};


vector<Node> linklist(100001);
vector<int> hash_table(100001);
vector<Node> result;
vector<Node> remove_element;


int abs(int number)
{
	if(number>=0)    return number;
	else    return (0-number);
}


// create link list;
void create_list(int head)
{
	// initialize hash table;
	for(int i=0;i<hash_table.size();i++)
	{
		hash_table[i] = 0;
	}


	int	current = head;
	while(current != -1)
	{			
		int value = abs(linklist[current].key);
		if(hash_table[value]==0)
		{
			result.push_back(linklist[current]);
			hash_table[value] = 1;
		}
		else
		{
			remove_element.push_back(linklist[current]);
		}

		current = linklist[current].next;
	}
}






int main()
{
	int head; // address of the first node;
	scanf("%d", &head);
	int N; // total number of nodes;
	scanf("%d", &N);
 


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
		scanf("%d", &temp);
		linklist[temp].addr = temp;

		scanf("%d%d", &linklist[temp].key, &linklist[temp].next);
	}

	//	print link list;
	create_list(head);	

	
	for(int i=0;i<result.size();i++)
	{
		if(i!=result.size()-1)
		{
			printf("%05d %d %05d\n", result[i].addr, result[i].key, result[i+1].addr);
		}
		else
		{
			printf("%05d %d -1", result[i].addr, result[i].key);
		}
	}

	if(remove_element.size()!=0)    printf("\n");
	for(int i=0;i<remove_element.size();i++)
	{
		if(i!=remove_element.size()-1)
		{
			printf("%05d %d %05d\n", remove_element[i].addr, remove_element[i].key, remove_element[i+1].addr);
		}
		else
		{
			printf("%05d %d -1", remove_element[i].addr, remove_element[i].key);
		}
	}



	return 0;
}








