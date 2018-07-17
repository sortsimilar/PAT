#include<cmath>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

struct Node
{
	long long int sign;
	long long int integer;
	long long int numerator;
	long long int denominator;
};

vector<string> save;
vector<Node> sequence;

string int_to_string(int temp)
{
	string result;
	stringstream ss;
	ss<<temp;
	ss>>result;

	return result;
}


string node_to_string(Node temp)
{
	string result = "";


	if(temp.numerator==0)
	{
		result = int_to_string(temp.sign*temp.integer);
	}
	else // numerator != 0;
	{
		if(temp.integer!=0)
		{
			result += int_to_string(temp.sign*temp.integer); // integer part;

			if(temp.denominator!=1)
			{
				result = result + " " + int_to_string(temp.numerator) + "/" + int_to_string(temp.denominator);
			}
		}
		else // integer == 0;
		{
			result = int_to_string(temp.sign*temp.numerator) + "/" + int_to_string(temp.denominator);
		}
	}


	return result;
}


Node string_to_node(string s)
{
	Node result;

	if(s[0]=='-')
	{
		result.sign = -1;
		s.erase(0, 1);
	}
	else
	{
		result.sign = 1;
	}

	bool flag = false;
	string fenzi = "";
	string fenmu = "";

	for(long long int j=0;j<s.length();j++)
	{
		if(s[j]=='/')
		{
			flag = true;
		}
		

		if(flag==false)
		{
			fenzi = fenzi + s[j];
		}

		if(flag==true)
		{
			fenmu = fenmu + s[j];
		}

	}

	fenmu.erase(0, 1);
	
//		cout<<fenzi<<" "<<fenmu<<endl;

	stringstream ss;
	ss<<fenzi;
	ss>>result.numerator;

	stringstream st;
	st<<fenmu;
	st>>result.denominator;

	return result;
}


Node yuefen(Node origin)
{
	long long int upper_bound = origin.numerator;
	if(origin.numerator<origin.denominator)    upper_bound = origin.denominator;


	long long int i=2;
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


Node daifen(Node a)
{
	Node result;
	result.sign = a.sign;
	result.integer = a.numerator / a.denominator;
	result.numerator = a.numerator % a.denominator;
	result.denominator = a.denominator;

	return result;
}


Node add(Node a, Node b)
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




int main()
{

	long long int N; // num of numbers;
	cin>>N;
	
	save.resize(N);
	for(long long int i=0;i<N;i++)
	{
		string s_temp;
		cin>>s_temp;		

		sequence.push_back(string_to_node(s_temp));		
	}

	Node result = sequence[0];

	for(long long int i=1;i<sequence.size();i++)
	{
		result = yuefen(add(result, sequence[i]));		
	}
	result = daifen(result);	

	cout<<node_to_string(result);

	return 0;

}



