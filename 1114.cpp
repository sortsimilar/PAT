#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

struct Node
{
	int key;
	int father;
	int mother;
	bool isRoot;

	int smallest;
	int total_num;
	double total_M;
	double total_area;


	vector<int> child;

	double M_estate;
	double Area;

};

vector<int> father(10001, -1);
vector<Node> family (10001);
vector<Node> result;


int find_root(int x)
{
	if (father[x] < 0)    return x;
	else    return father[x] = find_root(father[x]);
}


void union_set(int s1, int s2)
{
	int r1 = find_root(s1);
	int r2 = find_root(s2);

	if(r1 != r2)    father[r1] = r2;
}


bool compare(Node a, Node b)
{
	if(a.total_area/a.total_num != b.total_area/b.total_num)    return a.total_area/a.total_num > b.total_area/b.total_num;
	else    return a.smallest < b.smallest;
}


int main()
{
	for(int i=0;i<10001;i++)
	{
		family[i].key = -2;
		family[i].isRoot = false;

		family[i].M_estate = 0;
		family[i].Area = 0;

		family[i].smallest = 10001;
		family[i].total_num = 0;
		family[i].total_M = 0;
		family[i].total_area = 0;
	}


	int N; // N lines;
	cin>>N;

	for(int i=0;i<N;i++)
	{
		int ID;
		cin>>ID;
		
		family[ID].key = ID;

		cin>>family[ID].father;

		if(family[ID].father != -1)
		{
			union_set(ID, family[ID].father);
			family[family[ID].father].key = family[ID].father;
		}

		cin>>family[ID].mother;

		if(family[ID].mother != -1)
		{
			union_set(ID, family[ID].mother);
			family[family[ID].mother].key = family[ID].mother;			
		}		

		int k;
		cin>>k; // number of children of this person;

		for(int i=0;i<k;i++)
		{
			int child_ID;
			cin>>child_ID;

			family[ID].child.push_back(child_ID);

			union_set(ID, child_ID);
			family[child_ID].key = child_ID;
		}

		cin>>family[ID].M_estate;
		cin>>family[ID].Area;
	}


//	cout<<find_root(6666);

	for(int i=0;i<10001;i++)
	{
		if(family[i].key == i)
		{
			int root = find_root(family[i].key);

			family[root].isRoot = true;

			if(family[root].smallest > family[i].key)
			{
				family[root].smallest = family[i].key;
			}

			family[root].total_num++;
			family[root].total_M = family[root].total_M + family[i].M_estate;
			family[root].total_area = family[root].total_area + family[i].Area;
		}
	}

	for(int i=0;i<10001;i++)
	{
		if(family[i].isRoot == true)
		{
			result.push_back(family[i]);
		}
	}

	sort(result.begin(), result.end(), compare);

	cout<<result.size()<<endl;
	for(int i=0;i<result.size();i++)
	{
		printf("%04d", result[i].smallest);
		cout<<" "<<result[i].total_num<<" ";

		printf("%.3f", result[i].total_M / result[i].total_num);
		cout<<" ";
		printf("%.3f", result[i].total_area / result[i].total_num);

		if(i!=result.size()-1)    cout<<endl;
	}

	return 0;
}



/*

10
6666 5551 5552 1 7777 1 100
1234 5678 9012 1 0002 2 300
8888 -1 -1 0 1 1000
2468 0001 0004 1 2222 1 500
7777 6666 -1 0 2 300
3721 -1 -1 1 2333 2 150
9012 -1 -1 3 1236 1235 1234 1 100
1235 5678 9012 0 1 50
2222 1236 2468 2 6661 6662 1 300
2333 -1 3721 3 6661 6662 6663 1 100

*/




