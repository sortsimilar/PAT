#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int K;
	cin>>K;
	vector<bool> result(K);

	for(int k=0;k<K;k++)
	{
		int N;
		cin>>N;
		vector<int> chess(N);

		for(int i=0;i<N;i++)
		{
			cin>>chess[i];
		}

		bool flag = true;
		for(int i=0;i<N-1;i++)
		{
			for(int j=i+1;j<N;j++)
			{
				int x_first = i;
				int y_first = chess[i];
				int x_second = j;
				int y_second = chess[j];

				if((y_second - y_first) == (x_second - x_first))
				{
					flag = false;
					break;
				}

				if((y_second - y_first) == (x_second - x_first)*(-1))
				{
					flag = false;
					break;
				}

				if((y_second - y_first) == 0)
				{
					flag = false;
					break;
				}


			}
		}

		result[k] = flag;
	}
//	cout<<flag<<endl;


	for(int i=0;i<K;i++)
	{
		if(result[i]==true)    cout<<"YES";
		else    cout<<"NO";

		if(i !=K-1)    cout<<endl;
	}

	return 0;
}
