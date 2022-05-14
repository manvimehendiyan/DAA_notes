#include<iostream>
using namespace std;
//int print_str(int M[20][20],char *str,int i,int j)
//{
//	if(i==0 || j==0)
//		return 0;
//	if(M[i][j]==M[i-1][j-1])
//	{
//		print_str(M,str,i-1,j-1);
//		cout<<str[i];
//	}
//	else if(M[i][j]==M[i-1][j])
//		print_str(M,str,i-1,j);
//	else print_str(M,str,i,j-1);
//}
//int print_matrix(int M[20][20],int m,int n)
//{
//	for(int i=0;i<m;i++)
//	{
//		for(int j=0;j<n;j++)
//		{
//			cout<<M[i][j];
//			cout<<" ";
//		}
//		cout<<endl;
//	}
//}
int LCS(char *str1,char *str2,int m, int n)
{
	int i,j;
	int LT[m+1][n+1];
	for(i=0;i<=m;i++)
	{
		for(j=0;j<=n;j++)
		{
			if(i==0 || j==0)
				LT[i][j]=0;
			else if(str1[i-1]==str2[j-1])
				LT[i][j]=1+LT[i-1][j-1];
			else
				LT[i][j]=max(LT[i-1][j],LT[i][j-1]);
		}
	}
//	print_matrix(LT,m,n);
//	print_str(LT,str1,i,j);
	cout<<"Size of max substring : "<<LT[m][n];
	
	cout<<"\nPath followed: "<<endl;
	i=m;
	j=n;
	while(i!=0 || j!=0)
	{
		if(LT[i][j]==LT[i-1][j])
		{
			i--;
		}
		if(LT[i][j]!=LT[i-1][j-1])
		{
			cout<<str1[i-1]<<" ";
			i=i-1;
			j=j-1;
		}
		
	}
}
int main()
{
	int m,n,size;
	cout<<"Enter length of string 1: ";
	cin>>m;
	char str1[m];
	cout<<"Enter String 1: ";
	cin>>str1;
	cout<<"Enter length of string 2: ";
	cin>>n;
	char str2[n];
	cout<<"Enter String 2: ";
	cin>>str2;	
	cout<<endl;
	LCS(str1,str2,m,n);
	return 0;
}
