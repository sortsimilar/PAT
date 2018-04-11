#include<iostream>
#include<string>
using namespace std;

bool compare(string compare_original, string compare_multiple)
{
	bool flag = true;

	for(int i=0;i<compare_multiple.length();i++)
	{
		bool current_exist = false;
		for(int j=0;j<compare_original.length();j++)
		{
			if(compare_multiple[i] == compare_original[j])
			{
				current_exist = true;
				break;
			}
		}

		if(current_exist == false) // if we find new digit, then output no;
		{
			flag = false;
			break;
		}
	}

	for(int i=0;i<compare_original.length();i++)
	{
		bool current_exist = false;
		for(int j=0;j<compare_multiple.length();j++)
		{
			if(compare_original[i] == compare_multiple[j])
			{
				current_exist = true;
				break;
			}
		}

		if(current_exist == false)
		{
			flag = false;
			break;
		}
	}


	return flag;
}



int main()
{

	string original;
	cin>>original;

	

	
	bool jinwei = false;
	string temp_new = "";
	for(int i=original.length()-1;i>=0;i--)
	{
		
		int result = 2*(original[i] - '0') + jinwei;
		
		if(result<10)
		{
			jinwei = false;
			char char_result = result + '0';
			temp_new = char_result + temp_new;
		}
		else if(result>=10)
		{
			jinwei = true;
			result = result - 10;
			char char_result = result + '0';
			temp_new = char_result + temp_new;
		}

	}
	if(jinwei == true) temp_new = '1' + temp_new;


	bool flag = compare(original, temp_new);

	if(flag==true) cout<<"Yes"<<endl;
	else if(flag==false) cout<<"No"<<endl;
	cout<<temp_new;
	
	system("pause");
	return 0;
}