#include<algorithm>
#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;

struct one_student
{
	vector<int> courses;
};


map<string, one_student> id_to_course;


bool compare(int a, int b)
{
	return a < b;
}


int main()
{
	int N, K;
	cin >> N >> K;

	for(int i=0;i<K;i++)
	{
		int course_id;
		cin>>course_id;

		int num_student;
		cin>>num_student;

		for(int j=0;j<num_student;j++)
		{
			string id;
			cin>>id;

			id_to_course[id].courses.push_back(course_id);
		}
	}

/*
	for(int i=0;i<id_to_course["ZOE1"].courses.size();i++)
	{
		cout<<id_to_course["ZOE1"].courses[i]<<" ";
	}
*/

	vector<string> queries(N);
	for(int i=0;i<N;i++)
	{
		cin>>queries[i];
	}

	for(int i=0;i<queries.size();i++)
	{
		if(id_to_course[queries[i]].courses.size() == 0)
		{
			cout<<queries[i]<<" 0";
		}
		else
		{
			sort(id_to_course[queries[i]].courses.begin(), id_to_course[queries[i]].courses.end(), compare);

			cout<<queries[i]<<" "<<id_to_course[queries[i]].courses.size()<<" ";

			for(int j=0;j<id_to_course[queries[i]].courses.size();j++)
			{
				if(j!=0)    cout<<" ";
				cout<<id_to_course[queries[i]].courses[j];

			}
		}
		


		if(i!=queries.size()-1)    cout<<endl;
	}


	return 0;
}







