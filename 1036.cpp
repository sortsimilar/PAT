#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct Student
{
	string name;
	char gender;
	string ID;
	int grade;
};



int main()
{
	int N;
	cin>>N;
	
	vector<Student> sequence(N);
	for(int i=0;i<N;i++)
	{
		cin>>sequence[i].name;
		cin>>sequence[i].gender;
		cin>>sequence[i].ID;
		cin>>sequence[i].grade;
	}

	Student high_girl;
	Student low_boy;

	int high_girl_grade = -1;		
	int low_boy_grade = 101;

	for(int i=0;i<N;i++)
	{		
		
		if((sequence[i].gender=='F') && (sequence[i].grade>high_girl_grade))
		{
			high_girl_grade = sequence[i].grade;
			high_girl = sequence[i];
		}

		if((sequence[i].gender=='M') && (sequence[i].grade<low_boy_grade))
		{
			low_boy_grade = sequence[i].grade;
			low_boy = sequence[i];
		}
	}

	
	// output result;
	if(high_girl_grade != -1)    cout<<high_girl.name<<" "<<high_girl.ID<<endl;
	else    cout<<"Absent"<<endl;

	if(low_boy_grade != 101)    cout<<low_boy.name<<" "<<low_boy.ID<<endl;
	else    cout<<"Absent"<<endl;


	if((high_girl_grade != -1)&&(low_boy_grade != 101))    cout<<high_girl.grade-low_boy.grade;
	else    cout<<"NA";


	return 0;
}
