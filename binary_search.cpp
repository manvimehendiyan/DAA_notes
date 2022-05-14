#include<iostream>
using namespace std;
void swap(int *x,int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}
int bubble_sort(int a[],int n)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n-i-1;j++)
			if(a[j]>a[j+1])
				swap(&a[j],&a[j+1]);
}
int binary_search(int a[],int n,int m)
{
	int found=0;
	int LB=0;
	int UB=n-1;
	for(int i=0;i<n;i++)
	{
		int MID=(UB+LB)/2;
		if(a[MID]==m)
			return 1;
		else if(a[MID]>m)
			UB=MID-1;
		else if(a[MID]<m)
			LB=MID+1;
	}
	return 0;
}
int main()
{
	int n,num;
	cout<<"Enter total number: ";
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<<"Enter the number to be searched: ";
	cin>>num;
	bubble_sort(a,n);
	int x=binary_search(a,n,num);
	if(x==1)
		cout<<num<<" FOUND!!"<<endl;
	else
		cout<<num<<" NOT FOUND"<<endl;
	return 0;
}
