#include<iostream>
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

	first.exponent.push_back(-1);
	second.exponent.push_back(-1);

	while (1)
	{
		if ((first.exponent[first_index] == -1) && (second.exponent[second_index] == -1))
		{
			break;
		}
		else
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

	}

	return output;
}


int main()
{
	Polynomial first, second, output;

	cin >> first.num;

	for (int i = 0;i < first.num;i++)
	{
		int temp_exponent;
		cin >> temp_exponent;
		first.exponent.push_back(temp_exponent);
		float temp_coefficient;
		cin >> temp_coefficient;
		first.coefficient.push_back(temp_coefficient);
	}
	
	cin >> second.num;

	for (int i = 0;i < second.num;i++)
	{
		int temp_exponent;
		cin >> temp_exponent;
		second.exponent.push_back(temp_exponent);
		float temp_coefficient;
		cin >> temp_coefficient;
		second.coefficient.push_back(temp_coefficient);
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

	system("pause");
	return 0;
}
