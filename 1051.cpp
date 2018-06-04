#include<iostream>
#include<vector>
using namespace std;

vector<int> sequence;
vector<bool> result;



// 判断标准：出栈序列中，元素i之后所有比i小的元素间必须是降序排列的。
bool decrease_after(int position, int size)
{
	bool flag = true;

	int origin = sequence[position];
	int decrease_value = sequence[position];
	int counter = 1;

	for(int i=position+1;i<sequence.size();i++)
	{
		if(sequence[i] < sequence[position])
		{
			counter++;
			if(counter > size)
			{
				flag = false;
				break;
			}
			
			if(sequence[i] < decrease_value)
			{
				decrease_value = sequence[i];
			}
			else
			{
				flag = false;
				break;
			}
		}
	}


	return flag;
}




int main()
{
	int M; // maximum capacity of the stack
	cin>>M;
	int N; // length of push sequence
	cin>>N;
	int K; // number of pop sequences to be checked
	cin>>K;

	for(int i=0;i<K;i++)
	{
		sequence.clear();
		for(int j=0;j<N;j++)
		{
			int temp;
			cin>>temp;
			sequence.push_back(temp);
		}


		bool flag = true;
		for(int j=0;j<sequence.size();j++)
		{
//			cout<<decrease_after(j, M)<<" ";
			if(decrease_after(j, M)==false)
			{
				flag = false;
				break;
			}
		}
//		cout<<flag<<endl;

		result.push_back(flag);
	}


	for(int i=0;i<K;i++)
	{
//		cout<<result[i]<<endl;
		if(result[i]==true)    cout<<"YES";
		else    cout<<"NO";

		if(i != K-1)    cout<<endl;
	}


	return 0;
}








