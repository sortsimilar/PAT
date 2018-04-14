#include<iostream>
#include<string>


using namespace std;

int main()
{
	string original;
	cin>>original;
//	cout<<original;

	char signal_dishu; // +, -;
	signal_dishu = original[0];
	original.erase(0,1);

//	cout<<original;

	string dishu = "";
	int position;
	for(int i=0;i<original.length();i++)
	{
		if(original[i] != 'E')
		{
			dishu = dishu + original[i];
		}
		else
		{
			position = i;
			break;
		}
	}
//	cout<<dishu;
//	cout<<position;
	string exponent = "";
	for(int i=position+1;i<original.length();i++)
	{
		exponent = exponent + original[i];
	}

//	cout<<exponent;
	char signal_exponent = exponent[0];
	exponent.erase(0,1);

	int ex = stoi(exponent);

//	cout<<ex;



	// output process;
	if(signal_dishu == '-')
	{
		cout<<"-";
	}
	else if(signal_dishu == '+')
	{
		// do nothing;
	}

	if(signal_exponent == '-')
	{
		cout<<"0.";
		for(int i=0;i<ex-1;i++)
		{
			cout<<"0";
		}

		for(int i=0;i<dishu.length();i++)
		{
			if(dishu[i]!='.') cout<<dishu[i];
		}
	}
	else if(signal_exponent == '+')
	{
		// if dot not exist; +1.23E+3
		if(ex >= dishu.length()-2)
		{
			for(int i=0;i<dishu.length();i++)
			{
				if(dishu[i] != '.') cout<<dishu[i];
			}


			int num_zero = ex-dishu.length()+2;
			for(int i=0;i<num_zero;i++) cout<<"0";
		}
		else // dot still exist; +1.23E+1
		{
			int counter = 0;
			for(int i=0;i<dishu.length();i++)
			{
				if(dishu[i] != '.') cout<<dishu[i];

				counter = counter + 1;
				if(counter == ex+2) cout<<'.';
			}
		}
	}



	system("pause");
	return 0;
}