#include<iostream>
using namespace std;
int main()
{
	int n;
	cout<<"Enter the number of items"<<endl;
	cin>>n;
	cout<<"Enter the value of each items"<<endl;
	int val[n];
	for(int i=0;i<n;i++)
	cin>> val[i];
	cout<<"Enter the weight of each items"<<endl;
	int wt[n];
	for(int i=0;i<n;i++)
	cin>>wt[i];
	int W;
	cout<<"Enter the maximum weight"<<endl;
	cin>>W;
	int dp[n+1][W+1];
	for(int i=0;i<=n;i++)
	{
		for(int w=0;w<=W;w++)
		{
			if(i==0 or w==0)
			dp[i][w]=0;
			else if(wt[i-1]<=w)
			{
				dp[i][w]= max(val[i-1]+dp[i-1][w-wt[i-1]],dp[i-1][w]);
			}
			else
			dp[i][w]=dp[i-1][w];
		}
	}
	cout<<dp[n][W];
}
