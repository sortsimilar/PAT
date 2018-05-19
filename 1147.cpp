#include<iostream>
#include<string>
#include<vector>
using namespace std;



vector<int> heap;
vector<int> post_sequence;

void post_order(int current)
{
	if(current <= heap.size()-1)	
	{
		post_order(2*current+1);		
		post_order(2*current+2);
		post_sequence.push_back(heap[current]);
	}
}



int main()
{
	int M, N;
	cin>>M>>N;

	vector<int> sequence(M*N);

	for(int i=0;i<M*N;i++) // store all data;
	{
		cin>>sequence[i];
	}

	for(int j=0;j<M;j++)
	{
		heap.clear(); // clear heap;
		post_sequence.clear(); // clear post sequence;
		for(int i=0+N*j;i<N+N*j;i++)
		{
			heap.push_back(sequence[i]);
		}

		string signal = "";
		bool max_heap = true;				
		if(heap[0] > heap[1]) // test max heap;
		{
			for(int i=N-1;i>=1;i--)
			{
				if(heap[i] > heap[(i-1)/2])
				{
					max_heap = false;
					break;
				}
			}
			if(max_heap == true)    signal = "Max Heap";
			else signal = "Not Heap";
		}
		


		bool min_heap = true;
		if(heap[0] < heap[1]) // test min heap;
		{
			for(int i=N-1;i>=1;i--)
			{
				if(heap[i] < heap[(i-1)/2])
				{
					min_heap = false;
					break;
				}
			}
			if(min_heap == true)    signal = "Min Heap";
			else signal = "Not Heap";
		}
		

		cout<<signal<<endl;
		post_order(0);

		for(int i=0;i<post_sequence.size();i++)
		{
			cout<<post_sequence[i];
			if(i != post_sequence.size()-1)    cout<<" ";
		}

		if(j != M-1)    cout<<endl;
	}


	return 0;
}
