#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

vector<int> coupons;
vector<int> products;

bool compare(int a, int b)
{
	return a < b;
}


int main()
{
	int NC; // number of coupons NC;
	cin>>NC;

	coupons.resize(NC);
	for(int i=0;i<NC;i++)
	{
		cin>>coupons[i];
	}

	int NP; // num of product;
	cin>>NP;

	products.resize(NP);
	for(int i=0;i<NP;i++)
	{
		cin>>products[i];
	}

	sort(coupons.begin(), coupons.end(), compare);
	sort(products.begin(), products.end(), compare);

	int max_amount = 0;

	int c = 0; 
	int p = 0;

	while(c<NC && p<NP && coupons[c]<0 && products[p]<0)
	{
		max_amount = max_amount + coupons[c] * products[p];
		c++;
		p++;
	}

	c = NC - 1;
	p = NP - 1;

	while(c>=0 && p>=0 && coupons[c]>0 && products[p]>0)
	{
		max_amount = max_amount + coupons[c] * products[p];
		c--;
		p--;
	}

	cout<<max_amount;

	return 0;
}






