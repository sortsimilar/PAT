#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

struct Node
{
	int inventory;
	double price;
	double one_price;
	int sell_amount; // amount of sell amount;
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
		temp.sell_amount = 0;
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



	int remain = D;
	for(int i=0;i<save.size();i++)
	{
		if(remain > save[i].inventory)
		{
			save[i].sell_amount = save[i].inventory;
			remain = remain - save[i].inventory;
		}	
		else
		{
			save[i].sell_amount = remain;
			remain = 0;
		}
	}


	double sum = 0;
	for(int i=0;i<N;i++)
	{
//		cout<<save[i].inventory<<" "<<save[i].price<<" "<<save[i].one_price<<" "<<save[i].sell_amount<<endl;
		sum = sum + save[i].one_price * save[i].sell_amount;
	}


	printf("%.2f", sum);



	return 0;
}







