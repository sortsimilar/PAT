#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	string first, second, third, fourth;
	cin>>first>>second>>third>>fourth;

	char c1, c2;
	int c1_position;

	int min = first.length();
	if(min>second.length()) min = second.length();

	for(int i=0;i<min;i++)
	{
		if(first[i] == second[i])
		{
			if((first[i]-'A'>=0)&&(first[i]-'G'<=0))
			{
				c1 = first[i];
				c1_position = i;
				break;
			}
		}
	}

	if(c1=='A') cout<<"MON";
	else if(c1=='B') cout<<"TUE";
	else if(c1=='C') cout<<"WED";
	else if(c1=='D') cout<<"THU";
	else if(c1=='E') cout<<"FRI";
	else if(c1=='F') cout<<"SAT";
	else if(c1=='G') cout<<"SUN";
	cout<<" ";


	for(int i=c1_position+1;i<min;i++)
	{
		if(first[i] == second[i])
		{
			if(((first[i]-'A'>=0)&&(first[i]-'N'<=0))||((first[i]-'0'>=0)&&(first[i]-'9'<=0)))
			{
				c2 = first[i];
				break;
			}
		}
	}

	if((c2-'A'>=0)&&(c2-'N'<=0)) cout<<10+c2-'A';
	else if((c2-'0'>=0)&&(c2-'9'<=0)) cout<<"0"<<c2;
	cout<<":";


	int position = 0;
	min = third.length();
	if(min>fourth.length()) min = fourth.length();

	for(int i=0;i<min;i++)
	{
		if((((third[i]-'A'>=0)&&('Z'-third[i]>=0))||((third[i]-'a'>=0)&&('z'-third[i]>=0))) && third[i] == fourth[i])
		{
			position = i;
			break;
		}
	}

//	cout<<position;
	if(position<10) cout<<"0"<<position;
	else cout<<position;



	system("pause");
	return 0;
}