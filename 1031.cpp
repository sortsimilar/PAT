#include<iostream>
#include<string>

using namespace std;

int main()
{


	string test;
	cin>>test;
	int vertical; int horizonal;
	if((test.length()+2) % 3 == 0)  
	{
		vertical = (test.length()+2)/3;
		horizonal = vertical;
	}
	else if((test.length()+2) % 3 == 1) 
	{
		vertical = (test.length()+2-1)/3;
		horizonal = vertical + 1;
	}
	else if((test.length()+2) % 3 == 2) 
	{
		vertical = (test.length()+2-2)/3;
		horizonal = vertical + 2;
	}

//	cout<<vertical<<" "<<horizonal;

	for(int i=0;i<vertical-1;i++)
	{
		cout<<test[i];
		for(int j=0;j<horizonal-2;j++)
		{
			cout<<" ";
		}
		int temp = test.length()-1-i;
		cout<<test[temp];
		cout<<endl;
	}
	for(int i=0;i<horizonal;i++)
	{
		cout<<test[vertical-1+i];
	}


	system("pause");
	return 0;
}