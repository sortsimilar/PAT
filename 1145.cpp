#include<iostream>
#include<cmath>
#include<stdio.h>
#include<vector>
using namespace std;

vector<int> store_input;
vector<int> query_input;
vector<int> hash_table;

// test whether a number is prime or not;
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

// find smallerst prime number;
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

// insert key into hash table;
int hash_insert(int key)
{
	int location = -1;
	for(int i=0;i<hash_table.size();i++)
	{
		int index = (key + i*i) % hash_table.size();
		if(hash_table[index]==0)
		{
			hash_table[index] = key;
			location = index;
			break;
		}
	}

	return location;
}


// counter search time;
int hash_search(int key)
{
    int index;
	int counter = 1;

    for (int i = 0; i < hash_table.size(); i++) 
	{
        index = (key + i*i) % hash_table.size();


        if (hash_table[index] == key)
		{			
            break;
		}
		
		if(hash_table[index] == 0)
		{
			break;
		}

		counter++;
    }

    return counter;
}


int main()
{
	int MSize; // user-defined table size
	cin>>MSize;

	int N; // number of input numbers
	cin>>N;

	int M; // number of keys to be found
	cin>>M;

	for(int i=0;i<N;i++)
	{
		int temp;
		cin>>temp;

		store_input.push_back(temp);
	}

	for(int i=0;i<M;i++)
	{
		int temp;
		cin>>temp;
		query_input.push_back(temp);
	}


	int hash_size = big_prime(MSize);

//	cout<<endl<<big_prime(5)<<endl;

	for(int i=0;i<hash_size;i++)
	{
		hash_table.push_back(0);
	}
	

// output input result;
	for(int i=0;i<store_input.size();i++)
	{
		int flag = hash_insert(store_input[i]);

		if(flag==-1)    cout<<store_input[i]<<" cannot be inserted."<<endl;
	}

/*
	for(int i=0;i<hash_table.size();i++)
	{
		cout<<hash_table[i]<<" ";
	}
	cout<<endl;
*/

//	cout<<hash_search(11)<<endl;

	int search_time = 0;
	for(int i=0;i<M;i++)
	{
//		cout<<hash_search(query_input[i])<<endl;
		search_time += hash_search(query_input[i]);
	}

	double average = double (search_time) / double (M);
	printf("%.1f", average);

	return 0;
}






