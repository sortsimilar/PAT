#include<iostream>
#include<sstream>
#include<string>
using namespace std;

struct float_num
{
	string radix;
	int exponent;
};




float_num num_to_sci(string num)
{
	float_num output;
	int dot_position = -1;
	for(int i=0;i<num.length();i++)
	{
		if(num[i] == '.')
		{
			dot_position = i;
			break;
		}
	}

	// consider no dot; 123;
	if(dot_position == -1)
	{
		output.radix = "0." + num;	
		output.exponent = num.length();	
	}

	// consider dot in the middle; 123.98;
	if((dot_position>=1) && (num[0]!='0'))
	{
		num.erase(dot_position, 1);

		output.radix = "0." + num;
		output.exponent = dot_position;
	}

	// consider dot in the first; 0.0034;
	if((dot_position==1) && (num[0]=='0'))
	{
		int exponent;
		for(int i=2;i<num.length();i++)
		{
			if(num[i] != '0')
			{
				num.erase(0, i);
				exponent = 2 - i;
				break;
			}
		}
		
		output.radix = "0." + num;
		output.exponent = exponent;

	}


	return output;

}


int main()
{
	int N;
	cin>>N;
	string A, B;
	cin>>A>>B;


	// convert string to scientific notation;
//	cout<<num_to_sci("0.98");

	float_num sci_A = num_to_sci(A);
	float_num sci_B = num_to_sci(B);
	
	string cut_A = "";
	string cut_B = "";

	for(int i=0;i<N+2;i++)
	{
		cut_A = cut_A + sci_A.radix[i];
		cut_B = cut_B + sci_B.radix[i];
	}


	if((cut_A == cut_B) && (sci_A.exponent == sci_B.exponent))
	{
		cout<<"YES "<<cut_A<<"*10^"<<sci_A.exponent;
	}
	else
	{
		cout<<"NO ";
		cout<<cut_A<<"*10^"<<sci_A.exponent<<" ";
		cout<<cut_B<<"*10^"<<sci_B.exponent;
	}



	return 0;
}
