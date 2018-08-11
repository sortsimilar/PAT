#include<iostream>
#include<set>
#include<string>
#include<vector>
using namespace std;

struct Node
{
	set<string> students; 
};

vector<Node> courses;

bool compare(string a, string b)
{
	return a < b;
}


int main()
{
	int N; // num of student;
	cin>>N;
	int K; // num of courses;
	cin>>K;

	courses.resize(K);

	for(int i=0;i<N;i++)
	{
		string student_name;
		cin>>student_name;

		int num;
		cin>>num;

		for(int j=0;j<num;j++)
		{
			int course_select;
			cin>>course_select;

			courses[course_select-1].students.insert(student_name);
		}
	}


// output result;
	for(int i=0;i<courses.size();i++)
	{
		if(i>0)    cout<<endl;
		cout<<i+1<<" "<<courses[i].students.size();

		if(courses[i].students.size()>0)
		{
			cout<<endl;

			set<string>::iterator it;
			for(it=courses[i].students.begin();it!=courses[i].students.end();it++)
			{
				if(it!=courses[i].students.begin())    cout<<endl;
				cout<<*it;
			}
		}
	}



	return 0;
}






