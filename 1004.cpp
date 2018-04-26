#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

int tree[100][100];

int find_parent(int id)
{
	int parent = -1;
	for (int i = 0;i < 100;i++)
	{
		if (tree[i][id - 1] == 1)
		{
			parent = i + 1;
			break;
		}
	}

	return parent;
}

int calculate_distance(int id)
{
	int distance = 0;
	int current_id = id;
	while (find_parent(current_id) != -1)
	{
		distance++;
		current_id = find_parent(current_id);
	}

	return distance;
}

int main()
{
	int child_num[100];
	int distance[100]; // distance from current node to root;

	for (int i = 0;i < 100;i++)
	{
		child_num[i] = 0;
		distance[i] = -1;
	}


	int N; // num of nodes;
	cin >> N;
	int M; // num of non-leaf nodes;
	cin >> M;

	for (int i = 0;i < M;i++)
	{
		int id; // current id of node;
		cin >> id;
		int num_child;
		cin >> num_child;

		child_num[id - 1] = num_child;
		for (int j = 0;j < num_child;j++)
		{
			int child_id;
			cin >> child_id;
			tree[id - 1][child_id - 1] = 1;
		}

	}

//	cout << find_parent(1);
//	cout << calculate_distance(1);
	int max_distance = 0;
	for (int i = 0;i < N;i++)
	{
		distance[i] = calculate_distance(i+1);
		if (distance[i] > max_distance) max_distance = distance[i];
	}
//	cout << distance[6];
//	cout << max_distance;

	for (int i = 0;i <= max_distance;i++)
	{
		int counter = 0;
		for (int j = 0;j < 100;j++)
		{
			if (distance[j] == i)
			{
				if (child_num[j] == 0)
				{
					counter++;
				}
			}
		}
		cout << counter;
		if (i < max_distance) cout << " ";
	}

	return 0;
}
/*  case 1;
2 1
01 1 02
*/
/*  case 2;
3 1
01 2 02 03
*/
/*  case 3;
7 3
01 2 02 03
02 2 04 05
03 2 06 07
*/
