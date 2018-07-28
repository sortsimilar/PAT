#include<iostream>
#include<vector>
using namespace std;

struct Node
{
	bool stroke;
	bool visited;
};


struct OneRow
{
	vector<Node> row_member;
};

struct OneSlice
{
	vector<OneRow> matrix_member;
};


vector<OneSlice> slices;
int num_column;
int num_row;
int num_slice;
int counter;
int sum;

bool get_stroke(int slice, int row, int column)
{
	return slices[slice].matrix_member[row].row_member[column].stroke;
}

bool get_visited(int slice, int row, int column)
{
	return slices[slice].matrix_member[row].row_member[column].visited;
}

void set_visited(int slice, int row, int column, int flag)
{
	slices[slice].matrix_member[row].row_member[column].visited = flag;
}




void DFS(int slice, int row, int column)
{
	set_visited(slice, row, column, true);
	counter++;

	if((slice+1<num_slice)&&(get_stroke(slice+1, row, column)==true)&&(get_visited(slice+1, row, column)==false))
	{
		DFS(slice+1, row, column);
	}

	if((slice-1>=0)&&(get_stroke(slice-1, row, column)==true)&&(get_visited(slice-1, row, column)==false))
	{
		DFS(slice-1, row, column);
	}

	if((row+1<num_row)&&(get_stroke(slice, row+1, column)==true)&&(get_visited(slice, row+1, column)==false))
	{
		DFS(slice, row+1, column);
	}

	if((row-1>=0)&&(get_stroke(slice, row-1, column)==true)&&(get_visited(slice, row-1, column)==false))
	{
		DFS(slice, row-1, column);
	}

	if((column+1<num_column)&&(get_stroke(slice, row, column+1)==true)&&(get_visited(slice, row, column+1)==false))
	{
		DFS(slice, row, column+1);
	}

	if((column-1>=0)&&(get_stroke(slice, row, column-1)==true)&&(get_visited(slice, row, column-1)==false))
	{
		DFS(slice, row, column-1);
	}

}


void DFSTraverse(int threshold)
{
	for(int i=0;i<num_slice;i++)
	{
		for(int j=0;j<num_row;j++)
		{
			for(int k=0;k<num_column;k++)
			{
				if((get_stroke(i, j, k)==true)&&(get_visited(i, j, k)==false))
				{
					counter = 0;
					DFS(i, j, k);

					if(counter>=threshold)
					{
						sum = sum + counter;
					}
				}
			}
		}
	}
}



int main()
{
	int M; // row of each slice;
	cin>>M; 

	int N; // column of each slice;
	cin>>N;

	int L; // number of slices of a brain;
	cin>>L;

	int T; // integer threshold;
	cin>>T;

	num_column= N;
	num_row = M;
	num_slice = L;


	slices.resize(L);
	for(int i=0;i<L;i++)
	{
		slices[i].matrix_member.resize(M);
		for(int j=0;j<M;j++)
		{
			slices[i].matrix_member[j].row_member.resize(T);
			for(int k=0;k<N;k++)
			{
				int temp;
				cin>>temp;
				slices[i].matrix_member[j].row_member[k].stroke = temp;
				slices[i].matrix_member[j].row_member[k].visited = false;
			}
		}
	}

	counter = 0;
	sum = 0;

	DFSTraverse(T);
	cout<<sum;

	return 0;
}



