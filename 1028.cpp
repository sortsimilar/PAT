#include<algorithm>
#include<iostream>
#include<sstream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<vector>
using namespace std;

struct Student
{
	int ID;
	char name[10];
	int grade;
};


// C = 1;
bool compare_ID(Student first, Student second)
{
	return first.ID < second.ID;
}


// C = 2;
bool compare_name(Student first, Student second)
{
	if(strcmp(first.name, second.name) != 0)    return strcmp(first.name, second.name) < 0;
	else    return first.ID < second.ID;
}

// C = 3;
bool compare_grade(Student first, Student second)
{
	if(first.grade != second.grade)    return first.grade < second.grade;
	else    return first.ID < second.ID;
}


int main()
{
	int N, C;
	cin>>N>>C;

	vector<Student> sequence(N);

	for(int i=0;i<N;i++)
	{
		cin>>sequence[i].ID;
		scanf("%s",sequence[i].name);
		cin>>sequence[i].grade;
	}

	if(C==1)    sort(sequence.begin(), sequence.end(), compare_ID);
	else if(C==2)    sort(sequence.begin(), sequence.end(), compare_name);
	else if(C==3)    sort(sequence.begin(), sequence.end(), compare_grade);



	for(int i=0;i<N;i++)
	{
		printf("%06d", sequence[i].ID);
		cout<<" ";
		printf("%s", sequence[i].name);
		cout<<" "<<sequence[i].grade;


		if(i != N-1)    cout<<endl;
	}



	return 0;
}





