#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

struct Node
{
	double inventory;
	double price;
	double one_price;
};


vector<Node> save;

bool compare_one(Node first, Node second)
{
	return first.one_price > second.one_price;
}


int main()
{
// input process //////////////////////////////////
	int N; // number of different kinds of mooncakes;
	cin>>N;
	int D; // maximum total demand of the market;
	cin>>D; 
	
	// initialize save;
	for(int i=0;i<N;i++)
	{
		Node temp;
		save.push_back(temp);
	}

	for(int i=0;i<N;i++)
	{
		cin>>save[i].inventory;
	}

	for(int i=0;i<N;i++)
	{
		cin>>save[i].price;
	}

	// calculate one price;
	for(int i=0;i<N;i++)
	{
		save[i].one_price = save[i].price / save[i].inventory;
	}


	sort(save.begin(), save.end(), compare_one);


	double sum = 0;
	int remain = D;
	for(int i=0;i<save.size();i++)
	{
		if(remain > save[i].inventory)
		{
			remain = remain - save[i].inventory;
			sum = sum + save[i].price;
		}	
		else
		{
			sum = sum + remain*save[i].one_price;
			remain = 0;
			break;
		}
	}

	printf("%.2f", sum);



	return 0;
}







