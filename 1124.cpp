#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> winners;

bool test_in(string temp)
{
	bool flag = false;
	for(int i=0;i<winners.size();i++)
	{
		if(temp == winners[i])
		{
			flag = true;
			break;
		}
	}
	
	return flag;
}


int main()
{
	int M; // total number of forwards;
	int N; // skip number of winners;
	int S; // index of first winner;

	cin>>M>>N>>S;

	vector<string> sequence(M);	

	for(int i=0;i<M;i++)
	{
		cin>>sequence[i];
	}


	// output result;
	if(S>M)    cout<<"Keep going...";
	else
	{
		winners.push_back(sequence[S-1]);

		int current = S-1;
		while(current+N < sequence.size())
		{
			int next = current + N;
			while(next < sequence.size())
			{
								
				if(test_in(sequence[next]) == false)
				{
					winners.push_back(sequence[next]);
					break;
				}
				else    next++;

			}
			current = next;
		}

		// output result;
		for(int i=0;i<winners.size();i++)
		{
			cout<<winners[i];
			if(i != winners.size()-1)    cout<<endl;
		}		
	}

	return 0;
}
