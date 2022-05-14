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
int main()
{
	int n;
	cout<<"Enter total numbers: ";
	cin>>n;
	int a[n];
	cout<<"Enter the array: "<<endl;
	for(int i=0;i<n;i++)
		cin>>a[i];
	bubble_sort(a,n);
	cout<<"Sorted Array: ";
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
