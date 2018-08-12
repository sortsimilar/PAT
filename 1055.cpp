#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
using namespace std;


struct Node
{
	string name;
	int age;
	int worth;
};

struct Query
{
	int M; // max of outputs;
	int Amin; // range of ages;
	int Amax;
};


vector<Node> people;
vector<Query> queries;


bool compare(Node a, Node b)
{
	if(a.worth != b.worth)    return a.worth > b.worth;
	else
	{
		if(a.age != b.age)    return a.age < b.age;
		else
		{
			return a.name < b.name;
		}
	}
}



int main()
{
	int N; // total number of people;
	cin>>N;
	int K; // num of queries;
	cin>>K;

	people.resize(N);
	for(int i=0;i<people.size();i++)
	{
		cin>>people[i].name;
		cin>>people[i].age;
		cin>>people[i].worth;
	}

	queries.resize(K);
	for(int i=0;i<queries.size();i++)
	{
		cin>>queries[i].M;
		cin>>queries[i].Amin;
		cin>>queries[i].Amax;
	}

	for(int i=0;i<queries.size();i++)
	{
		vector<Node> result;
		for(int j=0;j<people.size();j++)
		{
			if((people[j].age>=queries[i].Amin)&&(people[j].age<=queries[i].Amax))
			{
				result.push_back(people[j]);
			}
		}

		sort(result.begin(), result.end(), compare);

		cout<<"Case #"<<i+1<<":"<<endl;
		if(result.size()>0)
		{
			for(int j=0;j<result.size() && j<queries[i].M;j++)
			{
				cout<<result[j].name<<" "<<result[j].age<<" "<<result[j].worth;

				if((j!=result.size()-1)&&(j!=queries[i].M-1))    cout<<endl;
			}
		}
		else
		{
			cout<<"None";
		}

		if(i!=queries.size()-1)    cout<<endl;
	}


	return 0;
}



















