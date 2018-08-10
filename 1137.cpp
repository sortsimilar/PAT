#include<algorithm>
#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;

struct Student
{
	string id;
	int online;
	int mid_exam;
	int final_exam;
	int total;
};


struct Node
{
	int online;
	int mid_exam;
	int final_exam;
	int total;
};


map<string, Node> map_student;


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
		string id;
		cin>>id;

		int online;
		cin >> online;

		map<string, Node>::iterator it;
		it = map_student.find(id);

		if(it == map_student.end())
		{
			map_student[id].online = online;
			map_student[id].mid_exam = -1;
			map_student[id].final_exam = -1;
		}
	}

	// add mid-exam score;
	for (int i = 0;i < M;i++)
	{
		string id;
		cin>>id;
		int mid_exam;
		cin>>mid_exam;

		map<string, Node>::iterator it;
		it = map_student.find(id);

		if(it == map_student.end()) // not find;
		{
			map_student[id].online = -1;
			map_student[id].mid_exam = mid_exam;
			map_student[id].final_exam = -1;
		}
		else // find;
		{
			map_student[id].mid_exam = mid_exam;
			map_student[id].final_exam = -1;
		}
	}

	// add final-exam score;
	for (int i = 0;i < N;i++)
	{
		string id;
		cin>>id;
		int final_exam;
		cin>>final_exam;

		map<string, Node>::iterator it;
		it = map_student.find(id);

		if(it == map_student.end())
		{
			map_student[id].online = -1;
			map_student[id].mid_exam = -1;
			map_student[id].final_exam = final_exam;
		}
		else
		{
			map_student[id].final_exam = final_exam;
		}
	}

	
	// calculate total score for each student;
	map<string, Node>::iterator it;
	for(it=map_student.begin();it!=map_student.end();it++)
	{
		if(it->second.mid_exam > it->second.final_exam)
		{
			int result = int (it->second.mid_exam*0.4 + it->second.final_exam*0.6 + 0.5);
			it->second.total = result;
		}
		else    it->second.total = it->second.final_exam;
	}


	vector<Student> qualified;
	for(it=map_student.begin();it!=map_student.end();it++)
	{
		if((it->second.online>=200) && (it->second.total>=60))
		{
			Student temp;
			temp.id = it->first;
			temp.online = it->second.online;
			temp.mid_exam = it->second.mid_exam;
			temp.final_exam = it->second.final_exam;
			temp.total = it->second.total;

			qualified.push_back(temp);
		}

	}

	sort(qualified.begin(), qualified.end(), compare);

	for (int i = 0;i < qualified.size();i++)
	{
		cout << qualified[i].id << " " << qualified[i].online << " ";
		cout << qualified[i].mid_exam << " " << qualified[i].final_exam << " ";
		cout << qualified[i].total;

		if (i != qualified.size() - 1)    cout << endl;
	}


	return 0;
}












