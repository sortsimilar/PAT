#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

int main()
{
	int N;
	cin>>N;
	
	vector<double> sequence(N);
	for(int i=0;i<N;i++)
	{
		cin>>sequence[i];
	}


	double sum = 0;

	for(int i=0;i<N;i++)
	{
		sum = sum + sequence[i]*(i+1)*(N-i);
	}

	

	printf("%.2f", sum);

	return 0;
}
