#include<iostream>
#include<cmath>
using namespace std;

int main()
{

	int N;
	cin>> N;

	bool find_flag = false;
	int position = 0;
	int size_sequence = 0;
	
	for(int k=0;k<13;k++)
	{
		for(int i=2;i<=sqrt(N);i++)
		{
			int ji = 1;
			for(int j=0;j<k;j++) // change 3 to more in the end;
			{
				ji = ji*(i+j);
			}

			if(ji > N) break;

			if(N % ji == 0)
			{
				find_flag = true;
				position = i;
				size_sequence = k;
				break;
			}
		}
	}

	if(size_sequence != 0)
	{
		cout<<size_sequence<<endl;
		for(int i=0;i<size_sequence;i++)
		{
			cout<<position+i;
			if(i<size_sequence-1) cout<<"*";
		}
	}
	else
	{
		cout<<1<<endl<<N;
	}

	return 0;
}
