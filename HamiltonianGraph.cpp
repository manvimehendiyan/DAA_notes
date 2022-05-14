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
	int deg_sum=0;
	for(int i=0;i<n;i++)
	{
		deg_sum+=degree[i];
	}
	if(n>=3 && deg_sum>=(n/2))
		cout<<"Hamiltonian Graph :)"<<endl;
	else
		cout<<"Not a Hamiltonian Graph :("<<endl;
	return 0;
}
