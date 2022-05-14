#include<iostream>
using namespace std;
int main() 
{
	int n,c=0;
	cout<<"Enter the number of vertices: ";
	cin>>n;
	int G[n][n];
	cout<<"\nEnter the adjacency matrix"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the adjacency of vertex "<<i+1<<": ";
		for(int j=0;j<n;j++)
			cin>>G[i][j];
	}
	int indegree[n],check[n];
	for(int i=0;i<n;i++)
	{
		indegree[i]=0;
		check[i]=0;
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			indegree[i]=indegree[i]+G[j][i];
	cout<<"\nTopological sort order: ";
	while(c<n)
	{
		for(int j=0;j<n;j++)
		{
			if((indegree[j]==0) && (check[j]==0))
			{
				cout<<j+1<<" ";
				check[j]=1;
			}
			for(int k=0;k<n;k++)
			{
				if(G[k][j]==1)
					indegree[j]--;
			}
		}
		c++;
	}
	return 0;
}
