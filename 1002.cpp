#include<iostream>
#include <stdio.h>
#include<vector>

using namespace std;

class Polynomial
{
public:
	int num;
	vector<int> exponent;
	vector<float> coefficient;
};


Polynomial add_polynomial(Polynomial first, Polynomial second)
{
	Polynomial output;
	int first_index = 0;
	int second_index = 0;

	while ((first_index < first.num) && (second_index < second.num))
	{
		if (first.exponent[first_index] < second.exponent[second_index])
		{
			output.exponent.push_back(second.exponent[second_index]);
			output.coefficient.push_back(second.coefficient[second_index]);
			second_index++;
		}
		else if (first.exponent[first_index] > second.exponent[second_index])
		{
			output.exponent.push_back(first.exponent[first_index]);
			output.coefficient.push_back(first.coefficient[first_index]);
			first_index++;
		}
		else
		{
			float sum = first.coefficient[first_index] + second.coefficient[second_index];
			if (sum != 0)
			{
				output.exponent.push_back(first.exponent[first_index]);
				output.coefficient.push_back(sum);
			}
			first_index++;
			second_index++;
		}
	}

	while(first_index < first.num)
	{
		output.exponent.push_back(first.exponent[first_index]);
		output.coefficient.push_back(first.coefficient[first_index]);
		first_index++;
	}

	while(second_index < second.num)
	{
		output.exponent.push_back(second.exponent[second_index]);
		output.coefficient.push_back(second.coefficient[second_index]);
		second_index++;
	}


	return output;
}


int main()
{
	Polynomial first, second, output;

	cin>>first.num;
	first.exponent.resize(first.num);
	first.coefficient.resize(first.num);
	for (int i = 0;i < first.num;i++)
	{
		cin>>first.exponent[i];
		cin>>first.coefficient[i];
	}

	
	cin>>second.num;
	second.exponent.resize(second.num);
	second.coefficient.resize(second.num);
	for (int i = 0;i < second.num;i++)
	{
		cin>>second.exponent[i];
		cin>>second.coefficient[i];
	}


	output = add_polynomial(first, second);

	cout << output.exponent.size();
	if (output.exponent.size() > 0)
	{
		cout << " ";
		for (int i = 0;i < output.exponent.size();i++)
		{
			cout << output.exponent[i] << " ";
			printf("%.1f", output.coefficient[i]);
			if (i != output.exponent.size() - 1) cout << " ";
		}
	}

	return 0;
}


/*

2 1 2.4 0 3.2
2 2 1.5 1 0.5

*/
