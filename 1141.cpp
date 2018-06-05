#include<algorithm>
#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;

struct Student
{
	string ID;
	double score;
	string school_name;
};

struct School
{
	string name;
	double tws;
	int Ns;
};

// change chapital letter to lower case;
char capital_to_lower(char letter)
{
	if((letter>='A')&&(letter<='Z'))
	{
		letter = letter - 'A' + 'a';
	}

	return letter;
}

vector<School> school_list;

// test whether school in list or not;
int locate_name(string name)
{
	int location = -1;
	for(int i=0;i<school_list.size();i++)
	{
		if(name == school_list[i].name)
		{
			location = i;
			break;
		}
	}

	return location;
}

// compare function of sort;
bool compare(School first, School second)
{
	if(int (first.tws) != int (second.tws))    return first.tws > second.tws;
	else
	{
		if(first.Ns != second.Ns)    return first.Ns < second.Ns;
		else    return first.name < second.name;
	}

}


int main()
{
// input process;
	int N;
	cin>>N;

	vector<Student> sequence(N);
	for(int i=0;i<N;i++)
	{
		cin>>sequence[i].ID;
		cin>>sequence[i].score;
		string temp;
		cin>>temp;

		for(int j=0;j<temp.length();j++)
		{
			temp[j] = capital_to_lower(temp[j]); // change capital letter to lower case;
		}

		sequence[i].school_name = temp;
	}

///////////////////////////////////////////////////////////
	map<string, int> map_school;
	int counter = 0;


	for(int i=0;i<N;i++)
	{
		double temp_score;
		if(sequence[i].ID[0] == 'T')    temp_score = sequence[i].score * 1.5;
		else if(sequence[i].ID[0] == 'A')    temp_score = sequence[i].score;
		else if(sequence[i].ID[0] == 'B')    temp_score = sequence[i].score / 1.5;		


		map<string,int>::iterator it;
		it = map_school.find(sequence[i].school_name);		



		if(it == map_school.end())
		{
			map_school[sequence[i].school_name] = counter;
			counter++;

			School temp;
			temp.name = sequence[i].school_name;
			temp.tws = temp_score;
			temp.Ns = 1;
			school_list.push_back(temp);
		}
		else
		{
			int location = map_school[sequence[i].school_name];
			school_list[location].tws += temp_score;
			school_list[location].Ns++;
		}

	
	}

	sort(school_list.begin(), school_list.end(), compare);

	cout<<school_list.size()<<endl;
	int rank = 0;
	for(int i=0;i<school_list.size();i++)
	{
		if(i>0)
		{
			if(int (school_list[i].tws) != int (school_list[i-1].tws))    rank = i;
		}
		cout<<rank+1<<" ";

		cout<<school_list[i].name<<" "<<int (school_list[i].tws)<<" "<<school_list[i].Ns;
		if(i != school_list.size()-1)    cout<<endl;
	}



	return 0;
}
