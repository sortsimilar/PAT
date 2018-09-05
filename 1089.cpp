#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

vector<int> original; // original sequence in the first line;
vector<int> sorted;
vector<int> current; // current sequence in the second line;
vector<int> result;


bool compare(int a, int b)
{
	return a < b;
}


int main()
{
// input process ////////////////////////////////////////////////////
	int N;
	cin>>N;

	original.resize(N);
	sorted.resize(N);
	for(int i=0;i<N;i++)
	{   
		int temp; 
		cin>>temp;
		original[i] = temp;		
		sorted[i] = temp;		
	}
	
	current.resize(N);
	result.resize(N);
	for(int i=0;i<N;i++)
	{
		int temp;
		cin>>temp;
		current[i] = temp;
		result[i] = temp;
	}


	// judge it is insert or not;
	int end_location = 0;
	bool flag_insert = true;
	for(int i=1;i<N;i++)
	{
		if(current[i-1]>current[i])
		{
			end_location = i-1;
			break;
		}
	}


	for(int i=end_location+1;i<N;i++)
	{

		if(original[i] != current[i])
		{
			flag_insert = false;
			break;
		}
	}


	// merge sort //////////////////////////////////////////////////////////////////////
	if(flag_insert==false)
	{
		cout<<"Merge Sort"<<endl;
		int k = 1, flag = 1;
        while(flag) 
		{
            flag = 0;
            for (int i = 0; i < N; i++) 
			{
                if (original[i] != current[i])
                    flag = 1;
            }
            k = k * 2;

            for (int i = 0; i < N / k; i++)
                sort(original.begin() + i * k, original.begin() + (i + 1) * k);
            sort(original.begin() + N / k * k, original.begin() + N);
        }

		for(int i=0;i<original.size();i++)
		{
			cout<<original[i];

			if(i!=original.size()-1)    cout<<" ";
		}

	}
	// insert sort //////////////////////////////////////////////////////////
	else
	{
		cout<<"Insertion Sort"<<endl;
		int end_location = 0;
		for(int i=0;i<N-1;i++)
		{
			if(current[i]>current[i+1])
			{
				end_location = i + 1;
				break;
			}
		}

		
		sort(current.begin(), current.begin()+end_location+1, compare);


		for(int i=0;i<current.size();i++)
		{
			cout<<current[i];
			if(i != current.size()-1)    cout<<" ";
		}

	}




	return 0;
}



/*

10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0

10
3 1 2 8 7 5 9 4 0 6
1 3 2 8 5 7 4 9 0 6

*/
