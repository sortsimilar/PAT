#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct Person
{
	string name;
	int height;
};

vector<Person> people;

bool compare(Person first, Person second)
{
	if(first.height != second.height)    return first.height > second.height;
	else    return first.name < second.name;
}



int main()
{
	int N; // total number of people;
	cin>>N;
	int K; // total number of rows;
	cin>>K;

	for(int i=0;i<N;i++)
	{
		Person temp;
		cin>>temp.name;
		cin>>temp.height;
		people.push_back(temp);
	}

	// sort people according to height and name; condition 5;
	sort(people.begin(), people.end(), compare);

//	for(int i=0;i<people.size();i++)    cout<<people[i].name<<" ";

	int each_row = N / K;
	int extra = N % K;
	int last_row = each_row + extra;

	int position = 0;
	string result = people[position].name;
	
	for(int i=1;i<last_row;i++)
	{	
		position++;	
		if(i%2==0)
		{
			result = result + " " + people[position].name;
		}
		else
		{
			result = people[position].name + " " + result;
		}		
	}

	cout<<result;
	if(K > 1)    cout<<endl;

	for(int j=1;j<K;j++)
	{	
		position++;
		string normal_result = people[position].name;

		for(int i=1;i<each_row;i++)
		{
			position++;
			if(i%2==0)    normal_result = normal_result + " " + people[position].name;
			else    normal_result = people[position].name + " " + normal_result;
		}
	
		cout<<normal_result;
		if(j != K-1)    cout<<endl;
	}


	return 0;
}

























