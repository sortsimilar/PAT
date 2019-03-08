#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main()
{
	string number;
	cin>>number;
//	number = "12345";
	
	if(number.size()%2 != 0)
	{
		number = number + "0";
	}
	
//	cout<<number<<endl;
	
	string output = "";
	string part;
	for(int i=0;i<number.size();i++)
	{
		if(i%2==0)
		{
			part = number[i];
		}
		else
		{
			part = part + number[i];
//			cout<<part<<endl;
			
			stringstream ss;
			int number_part;
			ss<<part;
			ss>>number_part;
			number_part = number_part + 32;
			
			char asc = number_part;
			
//			cout<<current<<endl;
			output = output + asc;
		}
		
	}
	
	cout<<output;
	
	
	return 0;
}	
	
	



