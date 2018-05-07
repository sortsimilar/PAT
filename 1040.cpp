#include<iostream>
#include<string>
using namespace std;

string test;


bool test_symm(int start, int end)
{
	bool flag = true;

	for (int i = 0;i <= end - start;i++)
	{
		if (test[start + i] != test[end - i])
		{
			flag = false;
			break;
		}
	}


	return flag;
}


int main()
{	
	getline(cin, test);


//	cout << test_symm(test) << endl;

	bool flag = false;
	string result = "";
	for (int i = test.length() - 1;i >= 0;i--)
	{
		// for length == i;
		for (int j = 0;j <= test.length()-1-i;j++) // j is start position;
		{
			if (test_symm(j, j + i) == true)
			{
				for (int k = j;k <= j + i;k++)
				{
					result = result + test[k];					
				}
				flag = true;
				break;
			}
		}

		if (flag == true)    break;
	}

	cout << result.length();

	system("pause");
	return 0;
}