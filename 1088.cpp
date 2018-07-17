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

	if(temp.sign==-1)
	{
		result = "(" + result+ ")";
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

Node substract(Node a, Node b)
{
	b.sign = (-1) * (b.sign);
	Node result = add(a, b);

	return result;
}

Node multiply(Node a, Node b)
{
	Node result;

	result.sign = a.sign * b.sign;
	result.numerator = a.numerator * b.numerator;
	result.denominator = a.denominator * b.denominator;

	return result;
}

Node divide(Node a, Node b)
{
	Node result;
	result.sign = a.sign / b.sign;
	result.numerator = a.numerator * b.denominator;
	result.denominator = a.denominator * b.numerator;

	return result;
}


int main()
{
	string first;
	cin>>first;
	string second;
	cin>>second;


	cout<<node_to_string(daifen(yuefen(string_to_node(first))));
	cout<<" + ";
	cout<<node_to_string(daifen(yuefen(string_to_node(second))));
	cout<<" = ";
	cout<<node_to_string(daifen(yuefen(add(string_to_node(first), string_to_node(second)))))<<endl;

	cout<<node_to_string(daifen(yuefen(string_to_node(first))));
	cout<<" - ";
	cout<<node_to_string(daifen(yuefen(string_to_node(second))));
	cout<<" = ";
	cout<<node_to_string(daifen(yuefen(substract(string_to_node(first), string_to_node(second)))))<<endl;

	cout<<node_to_string(daifen(yuefen(string_to_node(first))));
	cout<<" * ";
	cout<<node_to_string(daifen(yuefen(string_to_node(second))));
	cout<<" = ";
	cout<<node_to_string(daifen(yuefen(multiply(string_to_node(first), string_to_node(second)))))<<endl;

	cout<<node_to_string(daifen(yuefen(string_to_node(first))));
	cout<<" / ";
	cout<<node_to_string(daifen(yuefen(string_to_node(second))));
	cout<<" = ";
	if(node_to_string(daifen(yuefen(string_to_node(second)))) != "0")
	{	
		cout<<node_to_string(daifen(yuefen(divide(string_to_node(first), string_to_node(second)))));
	}
	else    cout<<"Inf";

	return 0;
}



