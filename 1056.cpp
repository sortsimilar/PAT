#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

struct Node
{
	int index;
	int key;
	int level;
	int rank;
};


vector<Node> weight_sequence;
vector<int> permutation;

bool compare_level(Node first, Node second)
{
	return first.level > second.level;
}

bool compare_index(Node first, Node second)
{
	return first.index < second.index;
}



int main()
{
	int NP; // number of programmers;
	cin>>NP;
	int NG; // maximum number of mice in a group
	cin>>NG;

	weight_sequence.resize(NP);
	for(int i=0;i<weight_sequence.size();i++)
	{
		cin>>weight_sequence[i].key;
		weight_sequence[i].index = i;
		weight_sequence[i].level = 0;
	}


	permutation.resize(NP);
	for(int i=0;i<permutation.size();i++)
	{
		cin>>permutation[i];
	}


	vector<int> prepare;
	vector<int> group;
	vector<int> current;
	for(int i=0;i<NP;i++)	
	{
		int temp = permutation[i];
		prepare.push_back(temp);
	}


	int counter = 1;
	while(prepare.size() > 1)
	{
		for(int i=0;i<prepare.size();i++)
		{
			group.push_back(prepare[i]);
			if(((i+1)%NG==0) || (i==prepare.size()-1))
			{
				int max_weight = weight_sequence[group[0]].key;
				int max_index = group[0];
				for(int j=0;j<group.size();j++)
				{
					if(weight_sequence[group[j]].key > max_weight)
					{
						max_weight = weight_sequence[group[j]].key;
						max_index = group[j];
					}
				}

				current.push_back(max_index);		
				weight_sequence[max_index].level = counter;		
				group.clear();
			}
		}

		counter++;

		
		prepare.clear();
		for(int i=0;i<current.size();i++)
		{
			prepare.push_back(current[i]);
		}
		current.clear();
	}

	sort(weight_sequence.begin(), weight_sequence.end(), compare_level);

	weight_sequence[0].rank = 1;
	for(int i=1;i<NP;i++)
	{
		if(weight_sequence[i].level == weight_sequence[i-1].level)
		{
			weight_sequence[i].rank = weight_sequence[i-1].rank;
		}
		else
		{
			weight_sequence[i].rank = i + 1;
		}
	}

	sort(weight_sequence.begin(), weight_sequence.end(), compare_index);

	for(int i=0;i<NP;i++)
	{
		cout<<weight_sequence[i].rank;
		if(i!=NP-1)    cout<<" ";
	}

	return 0;
}





