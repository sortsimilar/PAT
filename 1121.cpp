#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

vector<int> couple;
vector<int> guest;


string int_to_string(int number)
{
	string result;
	stringstream ss;
	ss<<number;
	ss>>result;
	int temp = 5 - result.length();

	for(int i=0;i<temp;i++)    result = "0" + result;

	return result;
}



int main()
{
// input process /////////////////////////////////////////////
	int N;
	cin>>N;

	for(int i=0;i<2*N;i++)
	{
		int temp;
		cin>>temp;
		couple.push_back(temp);
	}

	int M;
	cin>>M;

	for(int i=0;i<M;i++)
	{
		int temp;
		cin>>temp;
		guest.push_back(temp);
	}	
	

	vector<int> hash(100000);
	vector<int> hash_guest(100000);
	for(int i=0;i<hash.size();i++)
	{
		hash[i] = -1;
		hash_guest[i] = -1;
	}

	// mark all couple as 1;
	for(int i=0;i<couple.size();i++)
	{
//		int temp = couple[i];
//		hash[temp]++;
		if(i%2==0)
		{
			hash[couple[i]] = couple[i+1];			
		}
		else
		{
			hash[couple[i]] = couple[i-1];
		}
	}

//	cout<<hash[11111]<<endl<<hash[22222]<<endl;


	for(int i=0;i<guest.size();i++)
	{
		int temp = guest[i];
		hash_guest[temp] = 1;
	}





	vector<int> single;
	for(int i=0;i<guest.size();i++)
	{
		int temp = guest[i];
		if(hash[temp] == -1) // he has no couple;
		{
			single.push_back(temp);
		}
		else // his couple does not come;
		{
			int couple_id = hash[temp];
			if(hash_guest[couple_id]==-1)
			{
				single.push_back(temp);
			}
		}
		
	}
	sort(single.begin(), single.end());


//	cout<<int_to_string(34)<<endl;


// output result;
	cout<<single.size();
	if(single.size() != 0)    cout<<endl;
	for(int i=0;i<single.size();i++)
	{		
		cout<<int_to_string(single[i]);
		if(i != single.size()-1)    cout<<" ";
	}



	return 0;
}
