#include<iostream>
#include<string>
#include<vector>
using namespace std;


vector<string> result;
const int maxn = 10010;
vector<int> fa(10010, 0);
vector<int> cnt(10010, 0);
vector<bool> exist(10010, false);

int find_father(int x) 
{
	if(fa[x] == x)    return x;
	else    find_father(fa[x]);
}


void Union(int a, int b) 
{
    int RootA = find_father(a);
    int RootB = find_father(b);

    if(RootA != RootB)    fa[RootA] = RootB;
}



int main() 
{
	int n, m, k;
    cin>>n;
    for(int i = 1; i <= maxn; i++)
	{
        fa[i] = i;
	}

    int id, temp;
    for(int i = 0; i < n; i++) 
	{
		cin>>k>>id;
        exist[id] = true;
        for(int j = 0; j < k-1; j++) 
		{
			cin>>temp;
            Union(id, temp);
            exist[temp] = true;
        }
    }

    for(int i = 1; i <= maxn; i++) 
	{
        if(exist[i] == true) 
		{
            int root = find_father(i);
            cnt[root]++;
        }
    }

    int numTrees = 0, numBirds = 0;
    for(int i = 1; i <= maxn; i++) 
	{
        if(exist[i] == true && cnt[i] != 0) 
		{
            numTrees++;
            numBirds += cnt[i];
        }
    }

	
	cin>>m;

    int ida, idb;
    for(int i = 0; i < m; i++) 
	{
		cin>>ida>>idb;

		if(find_father(ida) == find_father(idb))    result.push_back("Yes");
		else    result.push_back("No");
    }


	cout<<numTrees<<" "<<numBirds<<endl;
	for(int i=0;i<result.size();i++)
	{
		cout<<result[i];
		if(i!=result.size()-1)    cout<<endl;
	}


    return 0;
}


/*

4
3 10 1 2
2 3 4
4 1 5 7 8
3 9 6 4
2
10 5
3 7

*/
