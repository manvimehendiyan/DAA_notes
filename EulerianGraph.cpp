#include<iostream>
using namespace std;
int main() 
{
	int n;
	cout<<"Enter the number of vertices: ";
	cin>>n;
	int G[n][n];
	cout<<"\nEnter the adjacency matrix of Graph"<<endl;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>G[i][j];
	int degree[n];
	for(int i=0;i<n;i++)
		degree[i]=0;
	for(int i=0;i<n;i++)
	{
		int sum=0;
		for(int j=0;j<n;j++)
			sum+=G[i][j];
		degree[i]=sum;
	}
	int odd=0,even=0;
	for(int i=0;i<n;i++)
	{
		if(degree[i]%2==0)
			even++;
		else
			odd++;
	}
	if(even==n && odd==0)
		cout<<"Eulerian Graph and circuit exits :)"<<endl;
	else if(odd==2)
		cout<<"Semi Eulerian Graph and circuit don't exist :( only path exists "<<endl;
	else
		cout<<"Not a Eulerian Graph!!!"<<endl;
	return 0;
}
