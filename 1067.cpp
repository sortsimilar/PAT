#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

struct Node
{
	int value;
	int position;
};

vector<Node> save;


bool judge_final()
{
	bool flag = true;
	for(int i=0;i<save.size();i++)
	{
		if(save[i].value != save[i].position)
		{
			flag = false;
			break;
		}
	}
	
	return flag;
}

bool compare(Node first, Node second)
{
	return first.value < second.value;
}

bool compare_position(Node first, Node second)
{
	return first.position < second.position;
}


void print_sequence()
{
	for(int i=0;i<save.size();i++)
	{
		cout<<save[i].value<<" "<<save[i].position<<endl;
	}
}



int main()
{
	int N;
	cin>>N;

	for(int i=0;i<N;i++)
	{
		Node temp;
		temp.position = i;
		cin>>temp.value;

		save.push_back(temp);
	}

	sort(save.begin(), save.end(), compare); // sort sequence according to their value;

/*
	for(int i=0;i<N;i++)
	{
		cout<<save[i].value<<" "<<save[i].position<<endl;
	}
*/

//	cout<<judge_final()<<endl;

	int counter = 0;
	while(judge_final()==false)
	{
		if(save[0].position != 0)
		{
			int zero_position = save[0].position;
			int seven_position = save[zero_position].position;

			save[0].position = seven_position;
			save[zero_position].position = zero_position;

			counter++;
			
		}
		else
		{
			int first_wrong;

			vector<Node> position;
			for(int i=0;i<N;i++)
			{
				position.push_back(save[i]);
			}

			sort(position.begin(), position.end(), compare_position);			

			for(int i=0;i<N;i++)
			{
				if(position[i].value != position[i].position)
				{
					first_wrong = i;
					break;
				}
			}


//			cout<<position[first_wrong].value<<endl;

			int zero_position = 0;
			int five_position = first_wrong;

			save[0].position = first_wrong;
			save[position[first_wrong].value].position = 0;

			counter++;
		}		

	}


	cout<<counter;

	return 0;
}










