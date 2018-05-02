#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>
using namespace std;

bool compare(int a, int b)
{
	return a>b;
}

int main()
{
	int N;
	cin>>N;

	// construct matrix size;
	int n = sqrt(N);
	while(n>0)
	{
		if(N % n == 0)    break;
		else
		{
			n--;
		}
	}
	int m = N / n;

	// get matrix;
	vector<int> sequence(N);
	vector<int> result(N);
	for(int i=0;i<N;i++)	
	{
		cin>>sequence[i];
	}

	// sort sequence;
	sort(sequence.begin(), sequence.end(), compare);

	// initialize result matrix;
	for(int i=0;i<N;i++)
	{
		result[i] = 0;
	}

	int position = 0;
	int i = 0;
	int j = 0;
	int counter = 0; // to go up, down, left, right;
	int length = 0; // number of matrix element to fill in;


	while(counter<2*m-1)
	{	
		if(counter%4==0)
		{
			if(counter != 0)
			{
				i = i + 1;
				j = j + 1;
			}
			while((result[i*n+j]==0) && (j<n))
			{
				result[i*n+j] = sequence[position];
				position++;
				j++;
			}
		}

//		cout<<endl<<i<<" "<<j<<endl;

		if(counter%4==1)
		{
			i = i + 1;
			j = j - 1;			
			while((result[i*n+j]==0) && (i<m))
			{
				result[i*n+j] = sequence[position];
				position++;
				i++;
			}
		}	

		if(counter%4==2)
		{
			i = i - 1;			
			j = j - 1;
			while((result[i*n+j]==0) && (j>=0))
			{
				result[i*n+j] = sequence[position];
				position++;
				j--;
			}
		}


		if(counter%4==3)
		{
			i = i - 1;
			j = j + 1;
			while((result[i*n+j]==0) && (i>=0))
			{
				result[i*n+j] = sequence[position];
				position++;
				i--;
			}
		}


		counter++;
	}

	// output result;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<result[i*n+j];
			if(j != n-1)    cout<<" ";
		}
		if(i != m-1)    cout<<endl;
	}


	return 0;
}
