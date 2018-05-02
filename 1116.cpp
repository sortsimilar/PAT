#include<cmath>
#include<iostream>
#include<sstream>
#include<vector>
using namespace std;

bool test_prime(int test)
{
	bool flag = true;

	for(int i=2;i<=sqrt(test);i++)
	{
		if(test % i == 0)
		{
			flag = false;
			break;
		}
	}

	return flag;
}



int main()
{
	int N;
	cin>>N;

	vector<string> sequence(N);

	for(int i=0;i<N;i++)
	{
		cin>>sequence[i];
	}

	int hash_table[10000];
	bool check_table[10000];
	for(int i=0;i<9999;i++)
	{
		hash_table[i] = -1;
		check_table[i] = false;
	}

	// store result in hash table;
	for(int i=0;i<N;i++)
	{
		int temp;
		stringstream ss;
		ss<<sequence[i];
		ss>>temp;
		hash_table[temp] = i + 1;		
	}

	int K;
	cin>>K;

	vector<string> query(K);
	for(int i=0;i<K;i++)
	{
		cin>>query[i];
	}

//	cout<<test_prime(4);

	for(int i=0;i<K;i++)
	{
		int temp;
		stringstream st;
		st<<query[i];
		st>>temp;

		int rank = hash_table[temp];
		bool check = check_table[temp];

		if(rank == -1)    cout<<query[i]<<": Are you kidding?";
		else
		{
			if(check == true)
			{
				cout<<query[i]<<": Checked";
			}
			else
			{
				cout<<query[i];
				if(rank == 1)
				{
					cout<<": Mystery Award";
					check_table[temp] = true;
				}			
				else
				{
					if(test_prime(rank) == true)
					{
						cout<<": Minion";
						check_table[temp] = true;
					}
					else
					{
						cout<<": Chocolate";
						check_table[temp] = true;
					}
				}
			}
		}
		if(i != K-1)    cout<<endl;
	}




	return 0;
}
