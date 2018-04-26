#include<iostream>
#include<stdio.h>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

// convert earth number to mar number;
string earth_to_mar(string earth)
{
	string mar = "";

	// convert string earth to number earth;
	int earth_num;
	stringstream ss;
	ss<<earth;
	ss>>earth_num;


	int yushu = earth_num % 13;
	int shang = earth_num / 13;

	if(earth_num == 0)
	{
		mar = "tret";
	}
	else
	{
		if(shang == 0)    mar = mar;
		else if(shang == 1)    mar = mar + "tam";
		else if(shang == 2)    mar = mar + "hel";
		else if(shang == 3)    mar = mar + "maa";
		else if(shang == 4)    mar = mar + "huh";
		else if(shang == 5)    mar = mar + "tou";
		else if(shang == 6)    mar = mar + "kes";
		else if(shang == 7)    mar = mar + "hei";
		else if(shang == 8)    mar = mar + "elo";
		else if(shang == 9)    mar = mar + "syy";
		else if(shang == 10)    mar = mar + "lok";
		else if(shang == 11)    mar = mar + "mer";
		else if(shang == 12)    mar = mar + "jou";

	
		if(shang != 0)
		{
			if(yushu == 1)    mar = mar + " jan";
			else if(yushu == 2)    mar = mar + " feb";
			else if(yushu == 3)    mar = mar + " mar";
			else if(yushu == 4)    mar = mar + " apr";
			else if(yushu == 5)    mar = mar + " may";
			else if(yushu == 6)    mar = mar + " jun";
			else if(yushu == 7)    mar = mar + " jly";
			else if(yushu == 8)    mar = mar + " aug";
			else if(yushu == 9)    mar = mar + " sep";
			else if(yushu == 10)    mar = mar + " oct";
			else if(yushu == 11)    mar = mar + " nov";
			else if(yushu == 12)    mar = mar + " dec";
		}
		else
		{
			if(yushu == 1)    mar = mar + "jan";
			else if(yushu == 2)    mar = mar + "feb";
			else if(yushu == 3)    mar = mar + "mar";
			else if(yushu == 4)    mar = mar + "apr";
			else if(yushu == 5)    mar = mar + "may";
			else if(yushu == 6)    mar = mar + "jun";
			else if(yushu == 7)    mar = mar + "jly";
			else if(yushu == 8)    mar = mar + "aug";
			else if(yushu == 9)    mar = mar + "sep";
			else if(yushu == 10)    mar = mar + "oct";
			else if(yushu == 11)    mar = mar + "nov";
			else if(yushu == 12)    mar = mar + "dec";
		}
	}

	return mar;
}


// convert mar number to earth number;
string mar_to_earth(string mar)
{
	string earth = "";

	bool flag_two = false; 
	int position = 0;
	string gaowei_string = "";
	string diwei_string = "";
	for(int i=0;i<mar.length();i++)
	{
		if(mar[i] == ' ')
		{
			flag_two = true;
			position = i;
			break;
		}
		else
		{
			gaowei_string = gaowei_string + mar[i];
		}
	}

	for(int i=position+1;i<mar.length();i++)
	{
		diwei_string = diwei_string + mar[i];
	}


	int diwei = 0; int gaowei = 0;


	if(mar == "tret")
	{
		earth = "0";
	}
	else
	{
		if(flag_two == false)
		{
			if(mar == "jan")    diwei = 1;
			else if(mar == "feb")    diwei = 2;
			else if(mar == "mar")    diwei = 3;
			else if(mar == "apr")    diwei = 4;
			else if(mar == "may")    diwei = 5;
			else if(mar == "jun")    diwei = 6;
			else if(mar == "jly")    diwei = 7;
			else if(mar == "aug")    diwei = 8;
			else if(mar == "sep")    diwei = 9;
			else if(mar == "oct")    diwei = 10;
			else if(mar == "nov")    diwei = 11;
			else if(mar == "dec")    diwei = 12;

			else if(mar == "tam")    diwei = 13*1;
			else if(mar == "hel")    diwei = 13*2;
			else if(mar == "maa")    diwei = 13*3;
			else if(mar == "huh")    diwei = 13*4;
			else if(mar == "tou")    diwei = 13*5;
			else if(mar == "kes")    diwei = 13*6;
			else if(mar == "hei")    diwei = 13*7;
			else if(mar == "elo")    diwei = 13*8;
			else if(mar == "syy")    diwei = 13*9;
			else if(mar == "lok")    diwei = 13*10;
			else if(mar == "mer")    diwei = 13*11;
			else if(mar == "jou")    diwei = 13*12;
		}
		else
		{
			if(diwei_string == "tret")    diwei = 0;
			else if(diwei_string == "jan")    diwei = 1;
			else if(diwei_string == "feb")    diwei = 2;
			else if(diwei_string == "mar")    diwei = 3;
			else if(diwei_string == "apr")    diwei = 4;
			else if(diwei_string == "may")    diwei = 5;
			else if(diwei_string == "jun")    diwei = 6;
			else if(diwei_string == "jly")    diwei = 7;
			else if(diwei_string == "aug")    diwei = 8;
			else if(diwei_string == "sep")    diwei = 9;
			else if(diwei_string == "oct")    diwei = 10;
			else if(diwei_string == "nov")    diwei = 11;
			else if(diwei_string == "dec")    diwei = 12;

			if(gaowei_string == "tam")    gaowei = 1*13;
			else if(gaowei_string == "hel")    gaowei = 2*13;
			else if(gaowei_string == "maa")    gaowei = 3*13;
			else if(gaowei_string == "huh")    gaowei = 4*13;
			else if(gaowei_string == "tou")    gaowei = 5*13;
			else if(gaowei_string == "kes")    gaowei = 6*13;
			else if(gaowei_string == "hei")    gaowei = 7*13;
			else if(gaowei_string == "elo")    gaowei = 8*13;
			else if(gaowei_string == "syy")    gaowei = 9*13;
			else if(gaowei_string == "lok")    gaowei = 10*13;
			else if(gaowei_string == "mer")    gaowei = 11*13;
			else if(gaowei_string == "jou")    gaowei = 12*13;
			
		}
		
		int result = diwei + gaowei;
		stringstream ss;
		ss<<result;
		ss>>earth;

	}

	return earth;
}



int main()
{
	string num;
	getline(cin, num);

	int N;
	stringstream ss;
	ss<<num;
	ss>>N;

	vector<string> content;

	for(int i=0;i<N;i++)
	{
		string temp;
		getline(cin, temp);
		content.push_back(temp);
	}


//	string output = earth_to_mar("13");
//	string output = mar_to_earth("tam");
//	cout<<endl<<output<<endl;


	for(int i=0;i<N;i++)
	{
		if((content[i][0] >= '0') && (content[i][0] <= '9')) // earth to mar;
		{
			cout<<earth_to_mar(content[i]);
		}
		else
		{
			cout<<mar_to_earth(content[i]);
		}

		if(i != N-1)    cout<<endl;
	}


	return 0;
}
