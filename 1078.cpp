#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

vector<int> store_input;
vector<int> hash_table;

bool test_prime(int number)
{
	bool flag = true;
	
	for(int i=2;i<=sqrt(number);i++)
	{
		if(number % i == 0)
		{
			flag = false;
			break;
		}
	}

	return flag;
}

int big_prime(int number)
{
	if(number<2)    return 2;
	else
	{
		int result = number;
		while(test_prime(result)==false)
		{
			result++;
		}

		return result;
	}
}

int hash_insert(int key)
{
	int location = -1;
	for(int i=0;i<hash_table.size();i++)
	{
		int index = (key + i*i) % hash_table.size();
		if(hash_table[index]==0)
		{
			hash_table[index] = 1;
			location = index;
			break;
		}
	}

	return location;
}



int main()
{
	int MSize; // user-defined table size
	cin>>MSize;

	int N; // number of input numbers
	cin>>N;

	for(int i=0;i<N;i++)
	{
		int temp;
		cin>>temp;

		store_input.push_back(temp);
	}


	int hash_size = big_prime(MSize);

//	cout<<endl<<big_prime(5)<<endl;

	for(int i=0;i<hash_size;i++)
	{
		hash_table.push_back(0);
	}
	
	for(int i=0;i<store_input.size();i++)
	{
		int flag = hash_insert(store_input[i]);

		if(flag!=-1) cout<<flag;
		else    cout<<"-";

		if(i != store_input.size()-1)    cout<<" ";
	}



	return 0;
}


