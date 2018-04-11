#include<iostream>
#include<string>
using namespace std;

string convert_system(int original)
{
	string result = "";

	int remain = original % 13;
	int shang = int (original / 13);

	char char_remain; char char_shang;
	if(remain<10) char_remain = '0' + remain;
	else if(remain == 10) char_remain = 'A';
	else if(remain == 11) char_remain = 'B';
	else if(remain == 12) char_remain = 'C';

	if(shang<10) char_shang = '0' + shang;
	else if(shang==10) char_shang = 'A';
	else if(shang==11) char_shang = 'B';
	else if(shang==12) char_shang = 'C';

	result = char_remain + result;
	result = char_shang + result;

	return result;
}



int main()
{
	int first; int second; int third;
	cin>>first; 
	cin>> second; 
	cin>>third;

//	cout<<first<<" "<<second<<" "<<third<<" ";



	cout<<"#"<<convert_system(first)<<convert_system(second)<<convert_system(third);






	system("pause");
	return 0;
}