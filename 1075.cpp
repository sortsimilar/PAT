#include<algorithm>
#include<iostream>
#include<sstream>
#include<vector>
using namespace std;

struct Submit
{
	int user_id;
	int problem_id;
	int partial_score;
};

struct Student
{
	int user_id;
	int score_list[5];
	bool flag_show;
	int total_score;
	int num_perfect;
};

bool compare(Student first, Student second)
{
	if (first.total_score != second.total_score)
	{
		return first.total_score > second.total_score;
	}
	else
	{
		if (first.num_perfect != second.num_perfect)
		{
			return first.num_perfect > second.num_perfect;
		}
		else
		{
			return first.user_id < second.user_id;
		}
	}
}


int main()
{
	int N, K, M;
	cin >> N >> K >> M;

	vector<Student> student_list(N);
	for (int i = 0;i<N;i++)
	{
		for (int j = 0;j<K;j++)
		{
			student_list[i].user_id = i + 1;
			student_list[i].score_list[j] = -2; // initialize as -2;
			student_list[i].flag_show = false;
			student_list[i].total_score = 0; // total score is 0;
			student_list[i].num_perfect = 0; // num of perfect;
		}
	}


	vector<int> full_mark(K);
	for (int i = 0;i<K;i++)
	{
		cin >> full_mark[i];
	}

	// get score of all submissions;
	vector<Submit> sequence(M);
	for (int i = 0;i<M;i++)
	{
		cin >> sequence[i].user_id;
		cin >> sequence[i].problem_id;
		cin >> sequence[i].partial_score;

	}

	//	update highest score for each question;
	for (int i = 0;i<M;i++)
	{
		int temp_user = sequence[i].user_id - 1;
		int temp_problem = sequence[i].problem_id - 1;
		int temp_score = sequence[i].partial_score;
		if (student_list[temp_user].score_list[temp_problem] < temp_score)
		{
			student_list[temp_user].score_list[temp_problem] = temp_score;
		}
	}

	
	for (int i = 0;i < N;i++)
	{
		// calculate total score for each student;
		for (int j = 0;j < K;j++)
		{
			if ((student_list[i].score_list[j] != -2) && (student_list[i].score_list[j] != -1))
			{
				student_list[i].total_score = student_list[i].total_score + student_list[i].score_list[j];
			}
		}

		// calculate perfect number for each student;
		int counter = 0;
		for (int j = 0;j < K;j++)
		{
			if (student_list[i].score_list[j] == full_mark[j])
			{
				counter++;
			}
		}
		student_list[i].num_perfect = counter;

		// decide whether student show in rank list or not;
		for (int j = 0;j < K;j++)
		{
			if ((student_list[i].score_list[j] != -1) && (student_list[i].score_list[j] != -2))
			{
				student_list[i].flag_show = true;
				break;
			}
		}
	}

	vector<Student> rank_list;
	for (int i = 0;i < N;i++)
	{
		if (student_list[i].flag_show == true)    rank_list.push_back(student_list[i]);
	}

	sort(rank_list.begin(), rank_list.end(), compare);

	int rank = 1;
	for (int i = 0;i < rank_list.size();i++)
	{
		cout << rank << " ";

		int temp = rank_list[i].user_id;
		stringstream ss;
		ss << temp;
		string id;
		ss >> id;
		for (int i = 0;i < 5 - id.length();i++)    cout << "0";
		cout << id << " ";
		
		cout << rank_list[i].total_score << " ";
		for (int j = 0;j < K;j++)
		{  
			if (rank_list[i].score_list[j] == -2)    cout << "-";
			else if (rank_list[i].score_list[j] == -1)    cout << "0";
			else    cout << rank_list[i].score_list[j];

			if (j != K - 1)    cout << " ";
		}

		if (i != rank_list.size() - 1)    cout << endl;

		if (i < rank_list.size() - 1)
		{
			if (rank_list[i + 1].total_score != rank_list[i].total_score)    rank = i + 2;
			else    rank = rank;
		}			
	}



	system("pause");
	return 0;	
}
