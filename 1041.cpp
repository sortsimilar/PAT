#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int num;
	cin>>num;
	vector<int> sequence(num);
	vector<int> lottery(10001);
	for(int i=0;i<10001;i++) lottery[i] = 0; // initialize vector;
	
	for(int i=0;i<num;i++)
	{
		int temp;
		cin>>temp;

		sequence[i] = temp;
		lottery[temp]++;
	}


	bool flag = false;
	for(int i=0;i<num;i++)
	{
		if(lottery[sequence[i]] == 1)
		{
			flag = true;
			cout<<sequence[i];
			break;
		}
	}

	if(flag==false) cout<<"None";


	system("pause");
	return 0;
}