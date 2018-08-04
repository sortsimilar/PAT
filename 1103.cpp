#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int n, k, p, maxFacSum = -1;
vector<int> v, ans, tempAns;

void init() 
{
    int temp = 0, index = 1;
    while (temp <= n) 
	{
        v.push_back(temp);
        temp = pow(index, p);
        index++;
    }
}

void dfs(int index, int tempSum, int tempK, int facSum) 
{
    if (tempK == k) 
	{
        if (tempSum == n && facSum > maxFacSum) 
		{
                ans = tempAns;
                maxFacSum = facSum;
        }

        return;
    }

    while(index >= 1) 
	{
        if (tempSum + v[index] <= n) 
		{
            tempAns[tempK] = index;
            dfs(index, tempSum + v[index], tempK + 1, facSum + index);
        }

        if (index == 1) return;
        index--;
    }
}


int main() 
{
	cin>>n>>k>>p;
    init(); 
    tempAns.resize(k);

    dfs(v.size() - 1, 0, 0, 0);

    if (maxFacSum == -1) 
	{
		cout<<"Impossible";
        return 0;
    }


	cout<<n<<" = ";
    for (int i = 0; i < ans.size(); i++) 
	{
        if (i != 0)    cout<<" + ";
		cout<<ans[i]<<"^"<<p;
    }

    return 0;
}


