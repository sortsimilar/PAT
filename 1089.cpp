#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

vector<int> original; // original sequence in the first line;
vector<int> sorted;
vector<int> current; // current sequence in the second line;
vector<int> result;

int get_min(int x, int y) { return (x<y)? x :y; }


void merge(int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    int L[n1];
	int R[n2];
 
    for (i = 0; i < n1; i++)	L[i] = current[l + i];
    for (j = 0; j < n2; j++)	R[j] = current[m + 1+ j];
 

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            current[k] = L[i];
            i++;
        }
        else
        {
            current[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        current[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
        current[k] = R[j];
        j++;
        k++;
    }
}


void merge_one_more(int curr_size)
{ 
	for (int left_start=0; left_start<current.size()-1; left_start += 2*curr_size)
	{
	   int mid = left_start + curr_size - 1;

	   int right_end = get_min(left_start + 2*curr_size - 1, current.size()-1);

	   merge(left_start, mid, right_end);
	}
}


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
		merge_one_more(end_location+1);

		cout<<"Merge Sort"<<endl;
		for(int i=0;i<current.size();i++)
		{
			cout<<current[i];
			if(i!=current.size()-1)    cout<<" ";
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
