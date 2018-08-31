#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;


vector<int> father(1001, -1);
vector<int> hobby(1001, -1);

int find_root(int x)
{
	if (father[x] < 0)    return x;
	else    return father[x] = find_root(father[x]);
}


void union_set(int s1, int s2)
{
	int r1 = find_root(s1);
	int r2 = find_root(s2);

	if(r1 != r2)    father[r1] = r2;
}


bool compare(int a, int b)
{
	return a > b;
}


int main()
{
	int N;
	cin>>N;

	for(int i=1;i<=N;i++)
	{
		int num;
		string temp;
		cin>>temp;
		temp.erase(temp.end()-1);
		stringstream ss;
		ss<<temp;
		ss>>num;


		for(int j=0;j<num;j++)
		{
			int temp_hobby;
			cin>>temp_hobby;
			
			if(hobby[temp_hobby] > 0)
			{
				union_set(hobby[temp_hobby], i);
			}
			
			hobby[temp_hobby] = i;

		}
	}

//	cout<<find_root(4);


	vector<int> root(N+1, 0);

	for(int i=1;i<N+1;i++)
	{
		root[find_root(i)]++;
	}

	vector<int> result;
	for(int i=1;i<N+1;i++)
	{
		if(root[i] != 0)
		{
			result.push_back(root[i]);
		}
	}

	sort(result.begin(), result.end(), compare);
	cout<<result.size()<<endl;
	for(int i=0;i<result.size();i++)
	{
		cout<<result[i];

		if(i!=result.size()-1)    cout<<" ";
	}


	return 0;
}


/*

8
3: 2 7 10
1: 4
2: 5 3
1: 4
1: 3
1: 4
4: 6 8 1 5
1: 4

*/
