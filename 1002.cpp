#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int first_num;
	cin >> first_num;
	vector<int> first_exponent(first_num);
	vector<float> first_coefficient(first_num);

	for (int i = 0;i < first_num;i++)
	{
		cin >> first_exponent[i];
		cin >> first_coefficient[i];
	}
	
	int second_num; // number of second polynomial;
	cin >> second_num;
	vector<int> second_exponent(second_num);
	vector<float> second_coefficient(second_num);

	for (int i = 0;i < second_num;i++)
	{
		cin >> second_exponent[i];
		cin >> second_coefficient[i];
	}

	int output_num = 0;
	vector<int> output_exponent;
	vector<float> output_coefficient;


	int first_index = 0;
	int second_index = 0;

	first_exponent.push_back(-1);
	second_exponent.push_back(-1);

//	for (int i = 0;i < first_num;i++) cout << first_exponent[i] << " ";
	while (1)
	{
		if ((first_exponent[first_index] == -1) && (second_exponent[second_index] == -1))
		{
			break;
		}
		else
		{
			if (first_exponent[first_index] < second_exponent[second_index])
			{
				output_exponent.push_back(second_exponent[second_index]);
				output_coefficient.push_back(second_coefficient[second_index]);
				second_index++;
			}
			else if (first_exponent[first_index] > second_exponent[second_index])
			{
				output_exponent.push_back(first_exponent[first_index]);
				output_coefficient.push_back(first_coefficient[first_index]);
				first_index++;
			}
			else
			{
				float sum = first_coefficient[first_index] + second_coefficient[second_index];
				if (sum != 0)
				{
					output_exponent.push_back(first_exponent[first_index]);
					output_coefficient.push_back(sum);
				}
				first_index++;
				second_index++;
			}

		}

	}

	cout << output_exponent.size();
	if (output_exponent.size() > 0)
	{
		cout << " ";
		for (int i = 0;i < output_exponent.size();i++)
		{
			cout << output_exponent[i] << " ";
			printf("%.1f", output_coefficient[i]);
			if (i != output_exponent.size() - 1) cout << " ";
		}
	}

	system("pause");
	return 0;
}
