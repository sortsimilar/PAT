#include<iostream>

using namespace std;


// -1,000,000 <= a, b <= 1000000


int main()
{
	int a;
	int b;
	cin>>a>>b;
	int sum = a+b;
	int abs = 0;
	if (sum>=0)
	{
		abs = sum;
	}
	else
	{
		abs = -sum;
		cout<<"-";
	}

	int right = abs % 1000;
	int middle = (int (abs /1000)) % 1000;
	int left = (int (abs /1000000)) % 1000;


	if(left==0 && middle==0)
	{
		cout<<right<<endl;
	}
	else if(left ==0 && middle !=0)
	{
		cout<<middle<<",";
		if(right <= 9)
		{
			cout<<"00"<<right;
		}
		else if(right>=10 && right<=99)
		{
			cout<<"0"<<right;
		}
		else
		{
			cout<<right;
		}
		cout<<endl;
	}
	else
	{
		cout<<left<<",";
		if(middle <= 9)
		{
			cout<<"00"<<middle;
		}
		else if(middle>=10 && middle<=99)
		{
			cout<<"0"<<middle;
		}
		else
		{
			cout<<middle;
		}
		cout<<",";

		if(right <= 9)
		{
			cout<<"00"<<right;
		}
		else if(right>=10 && right<=99)
		{
			cout<<"0"<<right;
		}
		else
		{
			cout<<right;
		}
		cout<<endl;
	}


//	system("pause");
	return 0;
}