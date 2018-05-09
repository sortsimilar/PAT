#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct Student
{
	string id;
	int on_line;
	int mid_exam;
	int final_exam;
	int total;
	bool qualify;
};

vector<Student> sequence;

int locate_id(string name)
{
	int position = -1;
	for (int i = 0;i < sequence.size();i++)
	{
		if (sequence[i].id == name)
		{
			position = i;
			break;
		}
	}

	return position;
}

bool compare(Student first, Student second)
{
	if (first.total != second.total)
	{
		return first.total > second.total;
	}
	else    return first.id < second.id;
}



int main()
{
	int P, M, N;
	cin >> P >> M >> N;

	// add on-line score;
	for (int i = 0;i < P;i++)
	{
		Student temp;
		cin >> temp.id;
		cin >> temp.on_line;
		temp.mid_exam = -1;
		temp.final_exam = -1;

		sequence.push_back(temp);

	}

	// add mid-exam score;
	for (int i = 0;i < M;i++)
	{
		Student temp;
		cin >> temp.id;
		cin >> temp.mid_exam;

		if (locate_id(temp.id) == -1) // there is no on-line score;
		{
			temp.on_line = -1;
			temp.final_exam = -1;
			sequence.push_back(temp);
		}
		else // there is on-line score;
		{
			temp.final_exam = -1;
			sequence[locate_id(temp.id)].mid_exam = temp.mid_exam;
		}
	}

	// add final-exam score;
	for (int i = 0;i < N;i++)
	{
		Student temp;
		cin >> temp.id;
		cin >> temp.final_exam;

		if (locate_id(temp.id) == -1) // there is no student;
		{
			temp.on_line = -1;
			temp.mid_exam = -1;
			sequence.push_back(temp);
		}
		else
		{
			sequence[locate_id(temp.id)].final_exam = temp.final_exam;
		}
	}

	/*
	for (int i = 0;i < sequence.size();i++)
	{
		cout << sequence[i].id << " " << sequence[i].on_line << " " << sequence[i].mid_exam << " " << sequence[i].final_exam;
		cout << endl;
	}
	*/

	// calculate total score for each student;
	for (int i = 0;i < sequence.size();i++)
	{
		if (sequence[i].mid_exam > sequence[i].final_exam)
		{
			int result = int (sequence[i].mid_exam*0.4 + sequence[i].final_exam*0.6 + 0.5);
			sequence[i].total = result;
		}
		else    sequence[i].total = sequence[i].final_exam;
	}


	vector<Student> qualified;
	for (int i = 0;i < sequence.size();i++)
	{
		if ((sequence[i].on_line >= 200) && (sequence[i].total >= 60))
		{
			sequence[i].qualify = true;
			qualified.push_back(sequence[i]);
		}
		else    sequence[i].qualify = false;
	}

	sort(qualified.begin(), qualified.end(), compare);

	for (int i = 0;i < qualified.size();i++)
	{
		cout << qualified[i].id << " " << qualified[i].on_line << " ";
		cout << qualified[i].mid_exam << " " << qualified[i].final_exam << " ";
		cout << qualified[i].total;

		if (i != qualified.size() - 1)    cout << endl;
	}


	system("pause");
	return 0;
}