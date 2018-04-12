#include<iostream>
#include<string>

using namespace std;

int main()
{

	string old_deck[54]; string new_deck[54];

	for(int i=0;i<=8;i++)
	{
		old_deck[i] = "";
		char number = i + '1';
		old_deck[i] = old_deck[i] + "S" + number;
	}

	for(int i=9;i<=12;i++)
	{
		old_deck[i] = "";
		char number = i-10 + '1';
		old_deck[i] = old_deck[i] + "S1" + number;
	}

	for(int i=13;i<=21;i++)
	{
		old_deck[i] = "";
		char number = i + '1'-13;
		old_deck[i] = old_deck[i] + "H" + number;
	}

	for(int i=22;i<=25;i++)
	{
		old_deck[i] = "";
		char number = i-10 + '1'-13;
		old_deck[i] = old_deck[i] + "H1" + number;
	}
	//////////////////////////////////////////////////////////
	for(int i=0+26;i<=8+26;i++)
	{
		old_deck[i] = "";
		char number = i + '1'-26;
		old_deck[i] = old_deck[i] + "C" + number;
	}

	for(int i=9+26;i<=12+26;i++)
	{
		old_deck[i] = "";
		char number = i-10 + '1'-26;
		old_deck[i] = old_deck[i] + "C1" + number;
	}

	for(int i=13+26;i<=21+26;i++)
	{
		old_deck[i] = "";
		char number = i + '1'-39;
		old_deck[i] = old_deck[i] + "D" + number;
	}

	for(int i=22+26;i<=25+26;i++)
	{
		old_deck[i] = "";
		char number = i-10 + '1'-39;
		old_deck[i] = old_deck[i] + "D1" + number;
	}

	old_deck[52] = "J1"; old_deck[53] = "J2";



//	for(int i=0;i<54;i++) cout<<old_deck[i]<<" ";



	
	int times;
	cin>>times;
	int move[54];
	for(int i=0;i<54;i++)
	{
		cin>>move[i];
	}


	for(int i=0;i<times;i++)
	{
		for(int j=0;j<54;j++)
		{
			new_deck[move[j]-1] = old_deck[j];
		}
	
		for(int j=0;j<54;j++)
		{
			old_deck[j] = new_deck[j];
		}
	}



	for(int i=0;i<54;i++)
	{
		cout<<new_deck[i];
		if(i != 54-1) cout<<" ";
	}

	

	system("pause");
	return 0;
}


