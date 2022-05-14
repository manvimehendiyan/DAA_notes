#include<iostream>
using namespace std;
void swap(int *x,int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}
int sort(int a[],int end[],int start[],int n)
{
	for(int i=0;i<n-1;i++)
		for(int j=0;j<n-i-1;j++)
			if(end[j]>end[j+1])
			{
				swap(&end[j],&end[j+1]);
				swap(&start[j],&start[j+1]);
				swap(&a[j],&a[j+1]);
			}
}
int activity(int a[],int start[],int end[],int n)
{
	int i,j;
	cout<<"Activities selected are in the order: "<<endl;
	i=0;
	cout<<"A"<<a[i]+1; 
	for(j=1;j<n;j++)
	{
		if(start[j]>=end[i])
		{
			cout<<" A"<<a[j]+1;
			i=j;
		}
	}
}
int main()
{
	int n;
	cout<<"Enter the number of activities: ";
	cin>>n;
	cout<<endl;
	int a[n],start[n],end[n];
	for(int i=0;i<n;i++)
		a[i]=i;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter starting time of Activity "<<i+1<<": ";
		cin>>start[i];
		cout<<"Enter finishing time of Activity "<<i+1<<": ";
		cin>>end[i];
		cout<<endl;
	}
	sort(a,end,start,n);
	activity(a,start,end,n);
	return 0;
}
