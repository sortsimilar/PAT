#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

vector<int> original;
vector<int> sorted;
vector<int> result;
vector<int> current;

void max_heapify(int start, int end) 
{
	//建立父節點指標和子節點指標
	int dad = start;
	int son = dad * 2 + 1;
	while (son <= end) { //若子節點指標在範圍內才做比較
		if (son + 1 <= end && original[son] < original[son + 1]) //先比較兩個子節點大小，選擇最大的
			son++;
		if (original[dad] > original[son]) //如果父節點大於子節點代表調整完畢，直接跳出函數
			return;
		else { //否則交換父子內容再繼續子節點和孫節點比較
			swap(original[dad], original[son]);
			dad = son;
			son = dad * 2 + 1;
		}
	}
}


int main()
{
// input process ////////////////////////////////////////////////////
	int N;
	cin>>N;

	// are numbers distinct? Yes?
	
	for(int i=0;i<N;i++)
	{   
		int temp; 
		cin>>temp;
		original.push_back(temp);		
		sorted.push_back(temp);		
	}
	
	for(int i=0;i<N;i++)
	{
		int temp;
		cin>>temp;
		current.push_back(temp);
		result.push_back(temp);
	}





	// we think difference between insertation sort and heap sort is max at the end;
	int max = -1;
	for(int i=0;i<N;i++)
	{
		if(max < original[i])
		{
			max = original[i];
		}
	}


	// heap sort //////////////////////////////////////////////////////////////////////
	if(max == current[N-1])
	{
		cout<<"Heap Sort"<<endl;
		sort(sorted.begin(), sorted.end());
		
		int end_location = N-1;
		for(int i=N-1;i>=0;i--)
		{
			if(sorted[i] != current[i])
			{
				end_location = i;
				break;
			}
		}

//		cout<<endl<<end_location<<endl;


		//初始化，i從最後一個父節點開始調整
		for (int i = N / 2 - 1; i >= 0; i--)
			max_heapify(i, N - 1);
		//先將第一個元素和已经排好的元素前一位做交換，再從新調整(刚调整的元素之前的元素)，直到排序完畢
		for (int i = N - 1; i >= end_location; i--) 
		{
			swap(original[0], original[i]);
			max_heapify(0, i - 1);
//			cout<<i<<endl;
//			print_sequence();
		}


		for(int i=0;i<original.size();i++)
		{
			cout<<original[i];
			if(i != original.size()-1)    cout<<" ";
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

		
	//	cout<<end_location<<endl;
		result.erase(result.begin()+end_location);

		int insert_location = 0;
		if(end_location != N)
		{			
			for(int i=end_location-1;i>=0;i--)
			{
				if(current[i]<current[end_location])
				{
					insert_location = i+1;
					break;
				}
			}
		}

	//	cout<<insert_location<<endl;
		result.insert(result.begin()+insert_location, current[end_location]);


		for(int i=0;i<result.size();i++)
		{
			cout<<result[i];
			if(i != result.size()-1)    cout<<" ";
		}

	}




	return 0;
}
