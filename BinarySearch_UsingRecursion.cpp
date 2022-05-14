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
int binary_search(int a[],int LB,int UB,int num)
{
	if(UB>=LB)
	{
		int MID=(UB+LB)/2;
		if(a[MID]==num)
			return MID;
		else if(a[MID]>num)
			return binary_search(a,LB,MID-1,num);
		else if(a[MID]<num)
			return binary_search(a,MID+1,UB,num);
	}
	return -1;
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
	int x=binary_search(a,0,n-1,num);
	if(x!=-1)
		cout<<num<<" FOUND!!"<<endl;
	else
		cout<<num<<" NOT FOUND"<<endl;
	return 0;
}
