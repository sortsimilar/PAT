#include <cstdio>
#include <iostream>
using namespace std;

int father[10001];


int find_root(int x)
{
	if (father[x] < 0)    return x;
	else    return father[x] = find_root(father[x]);
}


void union_set(int s1, int s2)
{
	int r1 = find_root(s1);
	int r2 = find_root(s2);

	if(r1 != r2)    father[r1] = r2;
}


int main()
{
	for(int i=0;i<10001;i++)    father[i] = -1;
	int n, k, bi, q;
	cin >> n;
	int pic[10001];
	for(int i=0;i<10001;i++)    pic[i] = 0;

	int count = 0;
	for (int i = 1; i <= n; i++) 
	{
		cin >> k;
		for (int j = 0; j < k; j++) 
		{
			cin >> bi;
			if (pic[bi] == 0) 
			{
				pic[bi] = i;
				count++;
			}
			else 
			{
				union_set(i, pic[bi]);
			}
		}
	}

	int nTree = 0;
	for (int i = 1; i <= n; i++)
		if (father[i] < 0) nTree++;


	cout<<nTree<<" "<<count<<endl;
	cin >> q;

	for (int i = 0; i < q; i++) 
	{
		int b1, b2;
		cin >> b1 >> b2;
		cout << (find_root(pic[b1]) == find_root(pic[b2]) ? "Yes" : "No") << endl;
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
