#include <iostream>
#include <vector>

using namespace std;
bool isMirror;

vector<int> pre;
vector<int> post;


void get_post(int root, int tail) 
{
    if(root > tail) return ;
    int i = root + 1, j = tail;
    if(!isMirror) 
	{
        while(i <= tail && pre[root] > pre[i]) i++;
        while(j > root && pre[root] <= pre[j]) j--;
    } 
	else 
	{
        while(i <= tail && pre[root] <= pre[i]) i++;
        while(j > root && pre[root] > pre[j]) j--;
    }

    if(i - j != 1) return ;

    get_post(root + 1, j);
    get_post(i, tail);
    post.push_back(pre[root]);
}


int main() 
{
    int N;
    cin>>N;

    pre.resize(N);
    for(int i = 0; i < N; i++)
	{
        cin>>pre[i];
	}


    get_post(0, N-1);

    if(post.size() != N) 
	{
        isMirror = true;
        post.clear();
        get_post(0, N - 1);
    }


    if(post.size() == N) 
	{
        cout<<"YES"<<endl;
        for(int i = 0; i < N; i++)
		{
            cout<<post[i];
			if(i!=N-1)    cout<<" ";
		}
    } 
	else 
	{
        cout<<"NO";
    }

    return 0;
}


