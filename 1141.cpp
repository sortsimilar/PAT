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


struct element
{
	double tws;
	int Ns;
};


struct School
{
	string name;
	double tws;
	int Ns;
};


vector<School> school_list;


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
			temp[j] = tolower(temp[j]); // change capital letter to lower case;
		}

		sequence[i].school_name = temp;
	}

///////////////////////////////////////////////////////////
	map<string, element> map_school;
	int counter = 0;


	for(int i=0;i<N;i++)
	{
		double temp_score;
		if(sequence[i].ID[0] == 'T')    temp_score = sequence[i].score * 1.5;
		else if(sequence[i].ID[0] == 'A')    temp_score = sequence[i].score;
		else if(sequence[i].ID[0] == 'B')    temp_score = sequence[i].score / 1.5;		

		map_school[sequence[i].school_name].tws += temp_score;
		map_school[sequence[i].school_name].Ns += 1;

	}

	map<string,element>::iterator it;
	for(it = map_school.begin(); it != map_school.end(); it++) 
	{
		School temp;
		temp.name = it->first;
		temp.tws = (it->second).tws;
		temp.Ns = (it->second).Ns;
		school_list.push_back(temp);
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






