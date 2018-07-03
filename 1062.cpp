#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

struct talent_virtue
{
	int ID;
	int virtue;
	int talent;
	int total;
};

vector<talent_virtue> save;

vector<talent_virtue> sage;
vector<talent_virtue> noble;
vector<talent_virtue> fool;
vector<talent_virtue> small;


bool compare(talent_virtue first, talent_virtue second)
{
	if(first.total != second.total)    return first.total > second.total;
	else
	{
		if(first.virtue != second.virtue)    return first.virtue > second.virtue;
		else
		{
			return first.ID < second.ID;
		}
	}

}



int main()
{
	int N; // number of people to be ranked; 
	cin>>N; 
	int L; // lower bound of the qualified grades;
	cin>>L;
	int H; // those with both grades not below this line are considered as the "sages";
	cin>>H;

	for(int i=0;i<N;i++)
	{
		talent_virtue temp;
		cin>>temp.ID;
		cin>>temp.virtue;
		cin>>temp.talent;
		temp.total = temp.virtue + temp.talent;

		save.push_back(temp);

		if((temp.virtue>=L)&&(temp.talent>=L))
		{
			if((temp.virtue>=H)&&(temp.talent>=H))
			{
				sage.push_back(temp);
			}
			else if((temp.virtue>=H)&&(temp.talent<H))
			{
				noble.push_back(temp);
			}
			else if((temp.virtue<H)&&(temp.talent<H)&&(temp.virtue>=temp.talent))
			{
				fool.push_back(temp);
			}
			else
			{
				small.push_back(temp);
			}
		}
	}

/*
	for(int i=0;i<N;i++)
	{
		cout<<save[i].ID<<" "<<save[i].virtue<<" "<<save[i].talent<<" "<<save[i].total<<endl;
	}
*/


//	cout<<sage.size()<<" "<<noble.size()<<" "<<fool.size()<<" "<<small.size()<<endl;

	sort(sage.begin(), sage.end(), compare);
	sort(noble.begin(), noble.end(), compare);
	sort(fool.begin(), fool.end(), compare);
	sort(small.begin(), small.end(), compare);

	int size = sage.size() + noble.size() + fool.size() + small.size();

	cout<<size;
	if(size!=0)    cout<<endl;

	for(int i=0;i<sage.size();i++)
	{
		cout<<sage[i].ID<<" "<<sage[i].virtue<<" "<<sage[i].talent;
		if(i!=sage.size()-1)    cout<<endl;
	}

	if(noble.size()!=0)    cout<<endl;
	for(int i=0;i<noble.size();i++)
	{
		cout<<noble[i].ID<<" "<<noble[i].virtue<<" "<<noble[i].talent;
		if(i!=noble.size()-1)   cout<<endl;
	}

	if(fool.size()!=0)    cout<<endl;
	for(int i=0;i<fool.size();i++)
	{
		cout<<fool[i].ID<<" "<<fool[i].virtue<<" "<<fool[i].talent;
		if(i!=fool.size()-1)    cout<<endl;
	}

	if(small.size()!=0)    cout<<endl;
	for(int i=0;i<small.size();i++)
	{
		cout<<small[i].ID<<" "<<small[i].virtue<<" "<<small[i].talent;
		if(i!=small.size()-1)    cout<<endl;
	}


	return 0;
}








