#include<iostream>
#include<map>
#include<string>
#include<vector>

using namespace std;



struct each_pic
{
	vector<string> pic_member;
};


int counter = 0; // count num of trees;
int idNumber = 1;
int num_v; // number of vertices;
vector<each_pic> pics;
map<string, int> string_to_int;
map<int, string> int_to_string;
vector<bool> adjacency_matrix;
vector<bool> visited;
vector<string> result;

bool test_edge(int start, int end)
{
	bool flag = false;

	if(adjacency_matrix[(start-1)*num_v+(end-1)]==true)    flag = true;
	if(adjacency_matrix[(start-1)+(end-1)*num_v]==true)    flag = true;

	return flag;
}


// DFS one range;
void DFS(int i)
{
	visited[i-1] = true;
//	cout<<i<<" ";
	for(int j=1;j<=num_v;j++)
	{
		if((test_edge(i, j)==true)&&(visited[j-1]==false))
		{
			DFS(j);
		}
	}

}

// DFS all map;
void DFSTraverse()
{
	// initialize visited matrix;
	for(int i=1;i<=num_v;i++)
	{
		visited[i-1] = false;
	}


	for(int i=1;i<=num_v;i++)
	{
		if(visited[i-1]==false)
		{
			DFS(i);
			counter++;
		}
	}
}

// test connected graph;
bool test_connect(int start, int end)
{
	for(int i=0;i<num_v;i++)
	{
		visited[i] = false;
	}


	DFS(start);

	if(visited[end-1]==false)    return false;
	else    return true;
	
}




int trans_func(string s) 
{
    if(string_to_int[s] == 0) 
	{
        string_to_int[s] = idNumber;
        int_to_string[idNumber] = s;
        return idNumber++;
    } 
	else 
	{
        return string_to_int[s];
    }
}



int main()
{
	int N; // number of pictures;
	cin>>N;

	pics.resize(N);
	for(int i=0;i<N;i++)
	{
		int K;
		cin>>K;

		pics[i].pic_member.resize(K);
		for(int j=0;j<K;j++)
		{
			cin>>pics[i].pic_member[j];
			trans_func(pics[i].pic_member[j]);
		}
	}

	num_v = string_to_int.size();

// create adjacency matrix;
	for(int i=0;i<num_v*num_v;i++)
	{
		adjacency_matrix.push_back(false);
	}


	for(int i=0;i<pics.size();i++)
	{

		if(pics[i].pic_member.size()>1)
		{
			for(int j=0;j<pics[i].pic_member.size()-1;j++)
			{
				int start = string_to_int[pics[i].pic_member[j]] - 1;
				int end = string_to_int[pics[i].pic_member[j+1]] - 1;

//				cout<<start<<" "<<end<<endl;

				adjacency_matrix[start*num_v + end] = true; 
				adjacency_matrix[start + end*num_v] = true; 
			}
		}
	}

//	cout<<string_to_int.size();

	// generate visited point;
	visited.resize(num_v);
	for(int i=0;i<num_v;i++)
	{
		visited[i] = false;
	}

	DFSTraverse();
//	cout<<endl<<counter<<endl;

	int Q;
	cin>>Q;

	for(int i=0;i<Q;i++)
	{
		string start_string;
		cin>>start_string;
		string end_string;
		cin>>end_string;

		int start = string_to_int[start_string];
		int end = string_to_int[end_string];

		if(test_connect(start, end)==false)    result.push_back("No");
		else    result.push_back("Yes");
	}

	cout<<counter<<" "<<string_to_int.size()<<endl;

//	cout<<test_connect(string_to_int["3"], string_to_int["7"]);

	for(int i=0;i<result.size();i++)
	{
		cout<<result[i];
		if(i!=result.size()-1)    cout<<endl;
	}


	return 0;
}
