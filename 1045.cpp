#include<iostream>
#include<map>
#include<vector>
using namespace std;


map<int, int> int_to_int;
vector<int> favourite;
vector<int> stripe;
vector<int> v;


int CeilIndex(vector<int> &v, int l, int r, int key) 
{
    while (r-l > 1) 
	{
		int m = l + (r-l)/2;
		if (v[m] >= key)    r = m;
		else    l = m;
    }
 
    return r;
}

 
int LIS(vector<int> &v) 
{
    if (v.size() == 0)    return 0;
 
    vector<int> tail(v.size(), 0);
    int length = 1; // always points empty slot in tail
 
    tail[0] = v[0];
    for (int i = 1; i < v.size(); i++) 
	{
        if (v[i] < tail[0])    tail[0] = v[i];
        else if (v[i] >= tail[length-1])    tail[length++] = v[i];
//        else    tail[CeilIndex(tail, -1, length-1, v[i])] = v[i];
    }
 
    return length;
}


int main()
{
	int N;
	cin>>N;

	int M;
	cin>>M;

	favourite.resize(M);
	for(int i=0;i<M;i++)
	{
		cin>>favourite[i];
	}

	int L;
	cin>>L;

	stripe.resize(L);
	for(int i=0;i<L;i++)
	{
		cin>>stripe[i];
	}

	// change favourite color into id;
	for(int i=0;i<favourite.size();i++)
	{
		int_to_int[favourite[i]] = i+1;
	}

	// translate stripe sequence;
	for(int i=0;i<stripe.size();i++)
	{
		int temp = int_to_int[stripe[i]];

		if(temp != 0)
		{
			v.push_back(temp);
		}
	}


	cout<<LIS(v);


	return 0;
}



