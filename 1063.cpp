#include<iostream>
#include<set>
#include<stdio.h>
#include<vector>
using namespace std;

struct number_set
{
	set<int> store;
};


vector<double> result;

int main()
{
	int N; // total number of sets;
//	cin>>N;
	scanf("%d", &N);

	vector<number_set> store_all;


	for(int i=0;i<N;i++)
	{
		int M;
//		cin>>M;
		scanf("%d", &M);

		number_set temp;
		for(int j=0;j<M;j++)
		{
			int number;
//			cin>>number;
			scanf("%d", &number);

			temp.store.insert(number);
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
//	cin>>K; 
	scanf("%d", &K);



	for(int i=0;i<K;i++)
	{
		int first;
//		cin>>first;
		scanf("%d", &first);
		int second;
//		cin>>second;
		scanf("%d", &second);
		
		

		// calculate Nc;
		int Nc = 0;		
		int Nt = store_all[first-1].store.size();


//		cout<<store_all[first-1].store.size()<<" ";
//		cout<<store_all[second-1].store.size()<<endl;

		for(set<int>::iterator it=store_all[second-1].store.begin() ;it!=store_all[second-1].store.end();it++)
		{
			if(store_all[first-1].store.find(*it) != store_all[first-1].store.end()) // Find it !!!
			{
				Nc++;
			}
			else
			{
				Nt++;
			}
		
		}
//		cout<<Nc<<endl;

		double result_temp = double (Nc) / double (Nt) * 100.0;

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




