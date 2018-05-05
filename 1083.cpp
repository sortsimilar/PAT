#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

struct Student
{
	string name;
	string ID;
	int grade;
};

bool compare(Student first, Student second)
{
	return first.grade > second.grade;
}

int main()
{
	int N;
	cin>>N;

	vector<Student> sequence(N);
	for(int i=0;i<N;i++)
	{
		cin>>sequence[i].name;
		cin>>sequence[i].ID;
		cin>>sequence[i].grade;
	}

	int grade1, grade2;
	cin>>grade1>>grade2;
	
	sort(sequence.begin(), sequence.end(), compare); // decreasing order;

	int start = N+2;
	int end = -1;

	for(int i=0;i<N;i++)
	{
		if(sequence[i].grade <= grade2)
		{
			start = i;
			break;
		}
	}

	for(int i=N-1;i>=0;i--)
	{
		if(sequence[i].grade >= grade1)
		{
			end = i;
			break;
		}
	}


//	cout<<start<<" "<<end<<endl;
	if(end>=start)
	{
		for(int i=start;i<=end;i++)
		{
			cout<<sequence[i].name<<" "<<sequence[i].ID;
			if( i != end)    cout<<endl;
		}
	}
	else    cout<<"NONE";


	return 0;
}
