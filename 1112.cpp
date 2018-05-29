#include<iostream>
#include<string>
using namespace std;

int k; // repeat times;
string origin; // origin string;
int hash_table[1000];


bool detect_repeat(int position)
{
	bool flag = true;
	for(int i=position;i<position+k;i++)
	{
		if(origin[position] != origin[i])
		{
			flag = false;
			break;
		}
	}
	
	return flag;
}






int main()
{	
	cin>>k;	
	cin>>origin;

// initialize hash table;
	for(int i=0;i<1000;i++)
	{
		hash_table[i] = 0;
	}


//	cout<<endl<<detect_repeat(3)<<endl;

// generate hash table;
	for(int i=0;i<=origin.length()-k;i++)
	{
//		cout<<origin[i]<<" ";
		if(detect_repeat(i)==true)
		{
			int temp = origin[i];
			hash_table[temp]++;
		}

	}

// output result;

	string result = "";
	for(int i=0;i<=origin.length()-k;i++)
	{
		result = result + origin[i];
		int temp = origin[i];
		if((hash_table[temp]>=2)&&(detect_repeat(i)==true))
		{
			i = i + k - 1;
		}
	}
	for(int i=origin.length()-k+1;i<origin.length();i++)    result = result + origin[i];


	for(int i=0;i<=origin.length()-k;i++)
	{
		int temp = origin[i];
		if(hash_table[temp]>=2)
		{
			cout<<origin[i];
			hash_table[temp] = 0;
		}
	}
	cout<<endl<<result;

	return 0;
}


/*
3
caseee1__thiiis_iiisss_a_teeeeeest
*/







