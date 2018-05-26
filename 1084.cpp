#include<iostream>
#include<string>
using namespace std;

// convert lower case letter to capital letter;
char convert_capital(char character)
{
	if((character>='a')&&(character<='z'))
	{
		character = character - 'a' + 'A';
	}

	return character;

}






int main()
{
	string original;
	cin>>original;

	string typed_out;
	cin>>typed_out;

// initialize hash table;
	bool hash_typed_out[10000];

	for(int i=0;i<10000;i++)
	{
		hash_typed_out[i] = false;
	}


//	cout<<endl<<convert_capital('_')<<endl;


	for(int i=0;i<typed_out.length();i++)
	{
		char temp = convert_capital(typed_out[i]);
		int temp1 = temp;
		hash_typed_out[temp1] = true;
	}


	for(int i=0;i<original.length();i++)
	{
		char temp = convert_capital(original[i]);
		int temp1 = temp;
		if(hash_typed_out[temp1]==false)
		{
			cout<<temp;
			hash_typed_out[temp1] = true;
		}
	}




	return 0;
}
