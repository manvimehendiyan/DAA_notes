#include<iostream>
using namespace std;
int insertion_sort(int a[],int n)
{
	for(int i=1;i<n;i++)
	{
		int temp=a[i];
		int j=i-1;
		while(j>=0 && temp<=a[j])
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
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
	insertion_sort(a,n);
	cout<<"Sorted Array: ";
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
