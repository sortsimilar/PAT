#include<iostream>
#include<vector>
using namespace std;


vector<int> value;
vector<int> weight;


int max(int a, int b) { return (a > b)? a : b; }


int knapSack(int W, int n)
{
   if (n == 0 || W == 0)    return 0;

   if (weight[n-1] > W)    return knapSack(W, n-1); 
   else return max(value[n-1] + knapSack(W-weight[n-1], n-1), knapSack(W, n-1));
}



int main()
{
    
    int  W = 50;
    int n = 3;

	value.resize(n);
	weight.resize(n);

	value[0]=60; value[1]=100; value[2]=120;
	weight[0]=10; weight[1]=20; weight[2]=30;


    cout<<knapSack(W, n);

    return 0;
}




