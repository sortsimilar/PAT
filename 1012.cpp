#include<algorithm>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool compare(int a, int b)
{
	return a > b;
}

int main()
{
	// input process ///////////////////////////////////////////////
	int N; // num of student;
	int M; // num of check;

	cin >> N;
	cin >> M;

	vector<string> id(N);
	vector<double> CC(N), CCSort(N);
	vector<double> MM(N), MMSort(N);
	vector<double> EE(N), EESort(N);
	vector<double> AA(N), AASort(N);
	vector<int> rankCC(N), rankMM(N), rankEE(N), rankAA(N), rank(N);
	vector<char> rank_course(N);
	vector<string> check(M);

	for (int i = 0;i < N;i++)
	{
		cin >> id[i];
		cin >> CC[i]; CCSort[i] = CC[i];
		cin >> MM[i]; MMSort[i] = MM[i];
		cin >> EE[i]; EESort[i] = EE[i];
		double average = (CC[i] + MM[i] + EE[i]) / 3;
		AA[i] = average; AASort[i] = AA[i];
	}

	for (int i = 0;i < M;i++)
	{
		cin >> check[i];
	}

	// sort points ///////////////////////////////////////////////////////////
	sort(CCSort.begin(), CCSort.end(), compare);
	sort(MMSort.begin(), MMSort.end(), compare);
	sort(EESort.begin(), EESort.end(), compare);
	sort(AASort.begin(), AASort.end(), compare);

	// for single student, find his rank for 4 class;
	for (int j = 0;j < N;j++)
	{
		for (int i = 0;i < N;i++)
		{
			if (CC[j] == CCSort[i])
			{
				rankCC[j] = i + 1;
				break;
			}
		}

		for (int i = 0;i < N;i++)
		{
			if (MM[j] == MMSort[i])
			{
				rankMM[j] = i + 1;
				break;
			}
		}

		for (int i = 0;i < N;i++)
		{
			if (EE[j] == EESort[i])
			{
				rankEE[j] = i + 1;
				break;
			}
		}

		for (int i = 0;i < N;i++)
		{
			if (AA[j] == AASort[i])
			{
				rankAA[j] = i + 1;
				break;
			}
		}
	}

	// find best course for a single student;
	for (int i = 0;i < N;i++)
	{
		if ((rankAA[i] <= rankCC[i]) && (rankAA[i] <= rankMM[i]) && (rankAA[i] <= rankEE[i]))
		{
			rank[i] = rankAA[i];
			rank_course[i] = 'A';
		}
		else if ((rankCC[i] < rankAA[i]) && (rankCC[i] <= rankMM[i]) && (rankCC[i] <= rankEE[i]))
		{
			rank[i] = rankCC[i];
			rank_course[i] = 'C';
		}
		else if ((rankMM[i] < rankAA[i]) && (rankMM[i] < rankCC[i]) && (rankMM[i] <= rankEE[i]))
		{
			rank[i] = rankMM[i];
			rank_course[i] = 'M';
		}
		else
		{
			rank[i] = rankEE[i];
			rank_course[i] = 'E';
		}
	}

//	for (int i = 0;i < CCSort.size();i++) cout << CCSort[i] << " ";
	for (int i = 0;i < M;i++)
	{
		// check whether in id or not;///////////////////////////////
		int id_position = -1;
		for (int j = 0;j < N;j++)
		{
			if (check[i] == id[j])
			{
				id_position = j;
				break;
			}
		}

		if (id_position == -1)
		{
			cout << "N/A";
		}
		else
		{
//			cout << id_position;
			cout << rank[id_position] << " " << rank_course[id_position];
		}

		if(i != M-1)  cout << endl;
	}

//	cout << rankAA[0]; // test single kemu rank;
//	cout << rank[0] << " " << rank_course[0]; // test single best kemu rank;

	system("pause");
	return 0;
}