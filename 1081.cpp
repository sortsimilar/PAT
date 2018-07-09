#include<cmath>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>

using namespace std;

struct Node
{
	int sign;
	int integer;
	int numerator;
	int denominator;
};

vector<string> save;
vector<Node> sequence;

Node yuefen(Node origin)
{
	int upper_bound = origin.numerator;
	if(origin.numerator<origin.denominator)    upper_bound = origin.denominator;


	int i=2;
	while(i<=sqrt(upper_bound))
	{
		if((origin.numerator%i==0)&&(origin.denominator%i==0))
		{
			origin.numerator = origin.numerator / i;
			origin.denominator = origin.denominator / i;
		}
		else
		{
			i++;
		}
	}


	return origin;

}


Node tongfen(Node a, Node b)
{
	Node result;
	result.numerator = a.numerator*b.denominator*a.sign + a.denominator*b.numerator*b.sign;
	result.denominator = a.denominator * b.denominator;

	if(result.numerator>=0)    result.sign = 1;
	else    
	{
		result.sign = -1;
		result.numerator = 0 - result.numerator;
	}

	return result;
}


Node daifen(Node a)
{
	Node result;
	result.sign = a.sign;
	result.integer = a.numerator / a.denominator;
	result.numerator = a.numerator % a.denominator;
	result.denominator = a.denominator;

	return result;
}

int main()
{

	int N; // num of numbers;
	cin>>N;
	
	save.resize(N);
	for(int i=0;i<N;i++)
	{
		string s_temp;
		cin>>s_temp;

		

		Node temp;

		if(s_temp[0]=='-')
		{
			temp.sign = -1;
			s_temp.erase(0, 1);
		}
		else
		{
			temp.sign = 1;
		}

		bool flag = false;
		string fenzi = "";
		string fenmu = "";

		for(int j=0;j<s_temp.length();j++)
		{
			if(s_temp[j]=='/')
			{
				flag = true;
			}
			

			if(flag==false)
			{
				fenzi = fenzi + s_temp[j];
			}

			if(flag==true)
			{
				fenmu = fenmu + s_temp[j];
			}

		}

		fenmu.erase(0, 1);
		
//		cout<<fenzi<<" "<<fenmu<<endl;

		stringstream ss;
		ss<<fenzi;
		ss>>temp.numerator;

		stringstream st;
		st<<fenmu;
		st>>temp.denominator;

		sequence.push_back(temp);		
	}


/*
	for(int i=0;i<sequence.size();i++)
	{
		cout<<sequence[i].sign<<" "<<sequence[i].numerator<<" "<<sequence[i].denominator<<endl;
	}
*/

/*
	Node test;
	test.sign = 1;
	test.numerator = 72;
	test.denominator = 108;
*/
//	Node result = yuefen(test);
//	cout<<result.numerator<<" "<<result.denominator<<endl;

/*
	Node a;
	a.sign = -1;
	a.numerator = 1;
	a.denominator = 2;

	Node b;
	b.sign = 1;
	b.numerator = 1;
	b.denominator = 4;

	Node result = yuefen(tongfen(a, b));
	

	cout<<result.sign<<" "<<result.numerator<<" "<<result.denominator;
*/


	Node result = sequence[0];

	for(int i=1;i<sequence.size();i++)
	{
		result = yuefen(tongfen(result, sequence[i]));
	}

	result = daifen(result);

//	cout<<result.sign<<" "<<result.integer<<" "<<result.numerator<<" "<<result.denominator<<endl;


	if(result.numerator==0)
	{
		cout<<result.sign*result.integer;
	}
	else // numerator != 0;
	{
		if(result.integer!=0)
		{
			cout<<result.sign*result.integer; // integer part;

			if(result.denominator!=1)
			{
				cout<<" "<<result.numerator<<"/"<<result.denominator;
			}
		}
		else // integer == 0;
		{
			cout<<result.sign*result.numerator<<"/"<<result.denominator;
		}
	}


	return 0;

}



