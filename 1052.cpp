#include<algorithm>
#include<stdio.h>
#include<string>
#include<vector>
using namespace std;

struct Node
{
	int addr;
	int key;
	int next;

};



vector<Node> linklist(200001);
vector<Node> linklist_origin;


// create link list;
void create_list(int head)
{
	int	current = head;
	while(current != -1)
	{	
		linklist_origin.push_back(linklist[current]);
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
	scanf("%d", &N);
	int head;
	scanf("%d", &head);


	// initialize link list;	
	for(int i=0;i<linklist.size();i++)
	{		
		linklist[i].addr = -1;
		linklist[i].next = -1;
	}

	for(int i=0;i<N;i++)
	{
		int temp;;
		scanf("%d", &temp);
		linklist[temp].addr = temp;
		scanf("%d", &linklist[temp].key);
		scanf("%d", &linklist[temp].next);
	}


	//	print link list;
	create_list(head);

	if(linklist_origin.size()>0)
	{
		sort(linklist_origin.begin(), linklist_origin.end(), compare);

		printf("%d %05d\n", linklist_origin.size(), linklist_origin[0].addr);
		for(int i=0;i<linklist_origin.size();i++)
		{
			printf("%05d %d ", linklist_origin[i].addr, linklist_origin[i].key);

			if(i != linklist_origin.size()-1)
			{
				printf("%05d\n", linklist_origin[i+1].addr);
			}
			else
			{
				printf("-1");
			}
		}
	}
	else
	{
		printf("0 -1");
	}


	return 0;
}










