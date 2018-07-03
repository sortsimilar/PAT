#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;

struct node 
{
    int ID;
	int virtue;
	int talent;
};

bool compare(node a, node b) 
{
    if ((a.virtue + a.talent) != (b.virtue + b.talent))
	{
        return (a.virtue + a.talent) > (b.virtue + b.talent);
	}
    else if (a.virtue != b.virtue)
	{
        return a.virtue > b.virtue;
	}
    else
	{
        return a.ID < b.ID;
	}
}


int main() 
{
    int N, L, H;
	cin>>N;
	cin>>L;
	cin>>H;

    vector<node> v[4];
    node temp;
    int total = N;
    for (int i = 0; i < N; i++) 
	{
        scanf("%d %d %d", &temp.ID, &temp.virtue, &temp.talent);

        if (temp.virtue < L || temp.talent < L)
		{
            total--;
		}
        else if (temp.virtue >= H && temp.talent >= H)
		{
            v[0].push_back(temp);
		}
        else if (temp.virtue >= H && temp.talent < H)
		{
            v[1].push_back(temp);
		}
        else if (temp.virtue < H && temp.talent < H && temp.virtue >= temp.talent)
		{
            v[2].push_back(temp);
		}
        else
		{
            v[3].push_back(temp);
		}
    }

    cout<<total<<endl;
    for (int i = 0; i < 4; i++) 
	{
        sort(v[i].begin(), v[i].end(), compare);
        for (int j = 0; j < v[i].size(); j++)
		{
            printf("%d %d %d\n", v[i][j].ID, v[i][j].virtue, v[i][j].talent);

		}
    }

    return 0;
}



