#include<iostream>
#include<map>

using namespace std;

int main()
{

	map<int, int> color_table;

	int M; int N;int temp;
	cin>>M; cin>>N;
	int half = M*N/2;

	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{			
			scanf("%d",&temp);
			color_table[temp]++;
			if(color_table[temp] > half)
			{
				printf("%d", temp);
				system("pause");
				return 0;
			}
		}

	}


	return 0;
}