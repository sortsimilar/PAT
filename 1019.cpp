#include<iostream>
#include<vector>
using namespace std;

void convert_system(int number, int D)
{
	vector<int> result;
	vector<int> reverse_result; 
	while(number >= D)
	{
		int remain;
		remain = number % D;	
		result.insert(result.begin(), remain);
		reverse_result.push_back(remain);

		number = int(number/D);
	}

	result.insert(result.begin(), number);
	reverse_result.push_back(number);

//	return reverse_result;
//	return result;

	bool flag = true;
	for(int i=0;i<reverse_result.size();i++)
	{
		if(result[i] != reverse_result[i]) flag = false;
	}

	if(flag==true) cout<<"Yes"<<endl;
	else if(flag == false) cout<<"No"<<endl;

	for(int i=0;i<result.size();i++)
	{
		cout<<result[i];
		if(i != result.size()-1) cout<<" ";
	}
}



int main()
{
	int number;
	cin>>number;
	int radix;
	cin>>radix;

	convert_system(number, radix);

	system("pause");
	return 0;
}