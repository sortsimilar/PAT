#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct Student
{
	bool flag;
	int id;
	string name;
	vector<int> courses;
};


int string_to_int(string name)
{
	int number = name[3] - '0';
	int last = (name[2] - 'A') * 10;
	int middle = (name[1] - 'A') * 10 * 26;
	int first = (name[0] - 'A') * 10 * 26 * 26;

	int result = first + middle + last + number;

	return result;
}




int main()
{
	int N, K;
	cin >> N >> K;


	vector<Student> map(193336);

	for (int i = 0;i < 193336;i++)
	{
		map[i].flag = false;
		map[i].courses.push_back(2501);
	}

	for (int i = 0;i < K;i++)
	{
		int course_index;
		int num_reg;

		cin >> course_index >> num_reg;

		for (int j = 0;j < num_reg;j++)
		{
			string temp;
			cin >> temp;

			int id = string_to_int(temp);

			map[id].flag = true;
			map[id].id = id;
			map[id].name = temp;
//			map[id].courses.push_back(course_index); 
			int position = 0;
			for (int k = 0;k < map[id].courses.size();k++)
			{
				if (course_index < map[id].courses[k])
				{
					position = k;
					break;
				}
			}

			map[id].courses.insert(map[id].courses.begin() + position, course_index);
		}

	}

	// input check sequence;
	vector<string> sequence(N);
	for (int i = 0;i < N;i++)
	{
		cin >> sequence[i];
	}

	




	// output result;
	for (int i = 0;i < N;i++)
	{
		string temp_name = sequence[i];
		int temp_id = string_to_int(temp_name);

		if (map[temp_id].flag == true)
		{
			cout << map[temp_id].name << " ";
			cout << map[temp_id].courses.size() - 1 << " ";
//			sort(map[temp_id].courses.begin(), map[temp_id].courses.end());
			for (int j = 0;j < map[temp_id].courses.size() - 1;j++)
			{
				cout << map[temp_id].courses[j];
				if (j != map[temp_id].courses.size() - 2)    cout << " ";
			}
		}
		else    cout << temp_name <<" 0";

		if (i != N - 1)    cout << endl;

	}

	system("pause");
	return 0;
}