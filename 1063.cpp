#include<iostream>
#include<set>
#include<stdio.h>
#include<vector>
using namespace std;

struct number_set
{
	vector<int> store;
};


vector<double> result;

int main()
{
	int N; // total number of sets;
	cin>>N;

	vector<number_set> store_all;

	for(int i=0;i<N;i++)
	{
		int M;
		cin>>M;

		number_set temp;
		for(int j=0;j<M;j++)
		{
			int number;
			cin>>number;

			temp.store.push_back(number);
		}


		store_all.push_back(temp);

	}

/*
	for(int i=0;i<store_all.size();i++)
	{
		for(int j=0;j<store_all[i].store.size();j++)
		{
			cout<<store_all[i].store[j]<<" ";
		}
		cout<<endl;
	}
*/

	int K; // K lines of queries
	cin>>K; 

	for(int i=0;i<K;i++)
	{
		int first;
		cin>>first;
		int second;
		cin>>second;

		
		set<int> NtSet;
		int Nt = 0;

		// calculate Nt;
		for(int j=0;j<store_all[first-1].store.size();j++)
		{
			NtSet.insert(store_all[first-1].store[j]);
		}

		for(int j=0;j<store_all[second-1].store.size();j++)
		{
			NtSet.insert(store_all[second-1].store[j]);
		}

//		cout<<NtSet.size()<<endl;

		// calculate Nc;
		int Nc = 0;
		set<int> FirstSet;
		set<int> SecondSet;
		
		for(int j=0;j<store_all[first-1].store.size();j++)
		{
			FirstSet.insert(store_all[first-1].store[j]);
		}

		for(int j=0;j<store_all[second-1].store.size();j++)
		{
			SecondSet.insert(store_all[second-1].store[j]);
		}

		for(set<int>::iterator it=SecondSet.begin() ;it!=SecondSet.end();it++)
		{
			if(FirstSet.find(*it) != FirstSet.end())
			{
				Nc++;
			}
			
		}
//		cout<<Nc<<endl;

		double result_temp = double (Nc) / double (NtSet.size()) * 100.0;

		result.push_back(result_temp);
	}


	for(int i=0;i<result.size();i++)
	{
		printf("%.1f", result[i]);
		cout<<"%";

		if(i!=result.size()-1)    cout<<endl;
	}


	return 0;
}




