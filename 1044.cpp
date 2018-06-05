#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct Node
{
	int start;
	int end;
};



vector<int> sequence;

int part_sum(int start, int end)
{
	int result = 0;
	for(int i=start;i<=end;i++)
	{
		result = result + sequence[i];
	}

	return result;
}




int main()
{
	int N; // total number of diamonds;
	cin>>N;
	int M; // amount that have to pay;
	cin>>M;

	for(int i=0;i<N;i++)
	{
		int temp;
		cin>>temp;
		sequence.push_back(temp);
	}

	int flag = false;
	int start;
	int end;
	for(int i=0;i<N;i++)
	{
		for(int j=i;j<N;j++)
		{
			if(part_sum(i, j) == M)
			{
				flag = true;
				start = i + 1;
				end = j + 1;
				cout<<start<<"-"<<end<<endl;
			}
		}
	}

	if(flag==false)
	{
		vector<Node> result;
		int min = part_sum(0, N-1) - M;
		for(int i=0;i<N;i++)
		{
			for(int j=i;j<N;j++)
			{
				if((part_sum(i, j) - M > 0) && (part_sum(i, j) - M <=min))
				{
					min = part_sum(i, j) - M;
					start = i + 1;
					end = j + 1;
				}
			}
		}

		for(int i=0;i<N;i++)
		{
			for(int j=i;j<N;j++)
			{
				if(part_sum(i, j) - M ==min)
				{
					Node temp;
					temp.start = i + 1;
					temp.end = j + 1;		
					result.push_back(temp);			
				}
			}
		}

		for(int i=0;i<result.size();i++)
		{
			cout<<result[i].start<<"-"<<result[i].end;
			if(i != result.size()-1)    cout<<endl;
		}
	}



	return 0;
}








