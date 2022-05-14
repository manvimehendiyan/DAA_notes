#include<iostream>
using namespace std;
void swap(int *x,int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}
int partition(int a[],int low,int high)
{
	int pivot=a[high];
	int i=low-1;
	for(int j=low;j<=high-1;j++)
	{
		if(a[j]<=pivot)
		{
			i++;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[i+1],&a[high]);
	return (i+1);
}
void quick_sort(int a[],int low,int high)
{
	if(low<high)
	{
		int pivot=partition(a,low,high);
		quick_sort(a,low,pivot-1);
		quick_sort(a,pivot+1,high);
	}
}
int main()
{
	int n,num;
	cout<<"Enter total number: ";
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	quick_sort(a,0,n-1);
	cout<<"Sorted array: "<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}
