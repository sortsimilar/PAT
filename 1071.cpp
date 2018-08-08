#include<algorithm>
#include<iostream>
#include<map>
#include<string>
#include<vector>

using namespace std;

struct Node
{
	string word;
	int freq;
};


map<string, int> string_to_int;
vector<string> save;
vector<Node> result;

void trans_func(string s) 
{
    if(string_to_int[s] == 0) 
	{
        string_to_int[s] = 1;
    } 
	else 
	{
        string_to_int[s]++;
    }
}


bool test_alpha(char c)
{
	if((c>='0')&&(c<='9'))    return true;
	else if((c>='a')&&(c<='z'))    return true;
	else if((c>='A')&&(c<='Z'))    return true;
	else    return false;
}


bool compare(Node a, Node b)
{
	if(a.freq!=b.freq)    return a.freq > b.freq;
	else    return a.word < b.word;
}


int main()
{
	string s = "";
	getline(cin, s);

	string temp = "";
	for(int i=0;i<s.length();i++)
	{		
		if(test_alpha(s[i])==true)
		{
			if((s[i]>='A')&&(s[i]<='Z'))
			{
				s[i] = s[i] - 'A' + 'a';
			}

			temp = temp + s[i];

			if(i==s.length()-1)
			{
				save.push_back(temp);
			}
		}
		else // == false;
		{			
			if(i>0)
			{
				if(test_alpha(s[i-1])==true)
				{
					save.push_back(temp);
					temp = "";
				}
			}
		}
	}

/*
	for(int i=0;i<save.size();i++)
	{
		cout<<save[i]<<endl;
	}

*/


	for(int i=0;i<save.size();i++)
	{
		trans_func(save[i]);
	}


//	cout<<test_alpha('*');

//	cout<<string_to_int["can"];	

	map<string, int>::iterator iter;
	for(iter = string_to_int.begin(); iter != string_to_int.end(); iter++) 
	{
//        cout << iter->first << " : " << iter->second << endl;

		Node temp;
		temp.word = iter->first;
		temp.freq = iter->second;

		result.push_back(temp);
    }

	sort(result.begin(), result.end(), compare);

	cout<<result[0].word<<" "<<result[0].freq;



	return 0;
}









