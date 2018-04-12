#include<iostream>
#include<vector>
using namespace std;


int main()
{

	int N; int sum = 0;
	cin>>N;
	vector<int> distance(N);

	for(int i=0;i<N;i++)
	{
		int temp;
		cin>>temp;
		distance[i] = sum;
		sum = sum + temp;		
	}

	



//	cout<<distance[1];
//	cout<<sum;

	int M;
	cin>>M;
	vector<int> first_column(M);
	vector<int> second_column(M);
	for(int i=0;i<M;i++)
	{
		cin>>first_column[i];
		cin>>second_column[i];
	}

	for(int j=0;j<M;j++)
	{
		int first = first_column[j]; int second = second_column[j];

		if(first > second)
		{
			int temp = first;
			first = second;
			second = temp;
		}


		int one_way = 0; int back_way = 0;

		one_way = distance[second-1] - distance[first-1];
		back_way = sum - one_way;

		if(one_way > back_way) cout<<back_way;
		else                   cout<<one_way;


		if(j != M-1) cout<<endl;
	}


	system("pause");
	return 0;
}