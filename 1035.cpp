#include<iostream>
#include<string>
#include<vector>
using namespace std;


// 1 (one) by @, 0 (zero) by %, l by L, and O by o.


int main()
{
	int num;
	cin>>num;

	vector<string> user(num);
	vector<string> password(num);

	int counter = 0;
	vector<string> out_user;
	vector<string> out_password;

	for(int i=0;i<num;i++)
	{
		cin>>user[i];
		cin>>password[i];
	}
//	cout<<password[1];
	for(int i=0;i<num;i++)
	{
		bool replace = false;
		for(int j=0;j<password[i].length();j++)
		{
			if(password[i][j] == '1')
			{
				password[i][j] = '@';
				replace = true;
			}
			else if(password[i][j] == '0')
			{
				password[i][j] = '%';
				replace = true;
			}
			else if(password[i][j] == 'l')
			{
				password[i][j] = 'L';
				replace = true;
			}
			else if(password[i][j] == 'O')
			{
				password[i][j] = 'o';
				replace = true;
			}
		}

		if(replace==true)
		{
			out_user.push_back(user[i]);
			out_password.push_back(password[i]);
		}

	}

//	cout<<out_password[1];

	if(out_password.size()>0)
	{
		cout<<out_password.size()<<endl;
		for(int i=0;i<out_password.size();i++)
		{
			cout<<out_user[i]<<" "<<out_password[i];
			if(i != out_password.size()-1)
			{
				cout<<endl;
			}
		}
	}
	else if((out_password.size()==0) && (num==1))
	{
		cout<<"There is 1 account and no account is modified";
	}
	else if((out_password.size()==0) && (num>1))
	{
		cout<<"There are "<<num<<" accounts and no account is modified";
	}

	system("pause");
	return 0;
}