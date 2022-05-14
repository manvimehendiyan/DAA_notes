#include<iostream>
using namespace std;
void swap(int *x,int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}
int selection_sort(int a[],int n)
{
	int min;
	for(int i=0;i<n-1;i++)
	{
		min=i;
		for(int j=i+1;j<n;j++)
			if(a[min]>a[j])
				min=j;
		swap(&a[min],&a[i]);
	}
}
int main()
{
	int n;
	cout<<"Enter total numbers: ";
	cin>>n;
	int a[n];
	cout<<"Enter the array: "<<endl;
	for(int i=0;i<n;i++)
		cin>>a[i];
	selection_sort(a,n);
	cout<<"Sorted Array: ";
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
