#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;


struct Book
{
	string ID;
	string title;
	string author;
	vector<string> keywords;
	string publisher;
	string year;
};


bool compare(Book a, Book b)
{
	return a.ID < b.ID;
}


int string_to_int(string s)
{
	int result;
	stringstream ss;
	ss<<s;
	ss>>result;

	return result;
}


int main()
{
	// store all book information; 
	string N;
	getline(cin, N);
	int num_N = string_to_int(N);

	vector<Book> check(num_N);

	for (int i = 0;i < num_N;i++)
	{
		getline(cin, check[i].ID);
		getline(cin, check[i].title);
		getline(cin, check[i].author);
		
		string all_keywords;
		getline(cin, all_keywords);
		all_keywords = all_keywords + " ";
		
		string one_key = "";
		for (int j = 0;j < all_keywords.length();j++)
		{
			if (all_keywords[j] != ' ')
			{
				one_key = one_key + all_keywords[j];
			}
			else
			{
				check[i].keywords.push_back(one_key);
				one_key = "";
			}
		}


		getline(cin, check[i].publisher);
		getline(cin, check[i].year);
	}

	// sort Book according to their ID;
	sort(check.begin(), check.end(), compare);



	// query process ///////////////
	string M;
	getline(cin, M);
	int num_M = string_to_int(M);

	vector<string> query(num_M);

	for (int i = 0;i < num_M;i++)
	{
		getline(cin, query[i]);
	}

	for (int i = 0;i < num_M;i++)
	{
		cout << query[i] << endl;
		char type = query[i][0];
		vector<string> result;
		string temp = query[i];
		temp.erase(0, 3);
		if (type == '1') // search title;
		{						
			for (int j = 0;j < num_N;j++)
			{
				if (temp == check[j].title)	   result.push_back(check[j].ID);	
			}			
		}
		else if (type == '2')
		{
			for (int j = 0;j < num_N;j++)
			{
				if (temp == check[j].author)    result.push_back(check[j].ID);
			}
		}
		else if (type == '4')
		{
			for (int j = 0;j < num_N;j++)
			{
				if (temp == check[j].publisher)    result.push_back(check[j].ID);
			}
		}
		else if (type == '5')
		{
			for (int j = 0;j < num_N;j++)
			{
				if (temp == check[j].year)    result.push_back(check[j].ID);
			}
		}
		else if (type == '3')
		{
			for (int j = 0;j < num_N;j++)
			{
				bool flag_exist = false;
				for (int k = 0;k < check[j].keywords.size();k++)
				{
					if (temp == check[j].keywords[k])
					{
						flag_exist = true;
						break;
					}
				}

				if (flag_exist == true) result.push_back(check[j].ID);

			}
		}

		// print result for this query;
		if (result.size() == 0) cout << "Not Found";
		else
		{
			for (int j = 0;j < result.size();j++)
			{
				cout << result[j];
				if (j != result.size() - 1) cout << endl;
			}
		}

		if (i != num_M - 1) cout << endl;
	}


	return 0;
}



