#include<iostream>
using namespace std;
void merge(int a[],int p,int q,int r)
{
	int n1=q-p+1, n2=r-q;
	int L[n1],R[n2];
	for(int i=0;i<n1;i++)
		L[i]=a[p+i];
	for(int i=0;i<n2;i++)
		R[i]=a[q+1+i];
	int i=0,j=0,k=p;
	while(i<n1 && j<n2)
	{
		if(L[i]<=R[j])
			a[k]=L[i++];
		else 
			a[k]=R[j++];
		k++;
	}
	while(i<n1)
	{
		a[k]=L[i++];
		k++;
	}
	while(j<n2)
	{
		a[k]=R[j++];
		k++;
	}
}
void merge_sort(int a[],int p,int r)
{
	int q=0;
	if(p<r)
	{
		q=(p+r)/2;
		merge_sort(a,p,q);
		merge_sort(a,q+1,r);
		merge(a,p,q,r);
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
	merge_sort(a,0,n-1);
	cout<<"Sorted array: "<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}
