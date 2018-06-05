#include<algorithm>
#include<iostream>
#include<sstream>
#include<vector>
using namespace std;

int main()
{
	int N;
	string N_string;
	getline(cin, N_string);
	stringstream ss;
	ss<<N_string;
	ss>>N;

	vector<string> command_list(N);	
	vector<int> stack;

	int hash[100002];
	for(int i=0;i<100002;i++)    hash[i] = 0;

	for(int i=0;i<N;i++)
	{
		string temp;
		getline(cin, temp);
		command_list[i] = temp;
	}



	for(int i=0;i<N;i++)	
	{
		string command = command_list[i];

		if(command[1] == 'o') // Pop;
		{
			if(stack.size() == 0)
			{
				cout<<"Invalid";				
			}
			else
			{
				int output = stack[stack.size()-1];
				cout<<output;
				stack.erase(stack.begin()+stack.size()-1);
				hash[output]--;				
			}

			if(i != N-1)    cout<<endl;
		}
		else if(command[1] == 'u') // Push;
		{
			int number;
			command.erase(0, 5);
			stringstream st;
			st<<command;
			st>>number;

			stack.push_back(number);
			hash[number]++;
		}
		else if(command[1] == 'e') // PeekMedian;
		{
			if(stack.size() == 0)
			{
				cout<<"Invalid";				
			}
			else
			{				
				int n = stack.size();

				int counter = 0;
				for(int i=0;i<100002;i++)
				{
					counter = counter + hash[i];
					if(n%2==0)
					{
						if(counter>=n/2)
						{
							cout<<i;
							break;
						}
					}
					else
					{
						if(counter>=(n+1)/2)
						{
							cout<<i;
							break;
						}
					}
				}

			}

			if(i != N-1)    cout<<endl;
		}		
	}




	return 0;
}
