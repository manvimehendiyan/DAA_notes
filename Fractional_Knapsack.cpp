#include<iostream>
using namespace std;
void swap1(int *x,int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}
void swap2(float *x,float *y)
{
	float temp=*x;
	*x=*y;
	*y=temp;
}
void sort(int a[],int w[],int p[],float ep[],int n)
{
	for(int i=0;i<n;i++)
	{
		int flag=1;
		for(int j=0;j<n-i-1;j++)
		{
			if(ep[j]>ep[j+1])
			{
				swap1(&a[j],&a[j+1]);
				swap1(&w[j],&w[j+1]);
				swap1(&p[j],&p[j+1]);
				swap2(&ep[j],&ep[j+1]);
				flag=0;
			}
		}
		if(flag)
			break;
	}
}
void knapsack(int a[],int w[],int p[],float ep[],int n,int limit)
{
	float profit=0;
    int size=0;
    int i=n-1;
    while((i>=0)&&(size<=limit))
    {
        if(w[i]<=(limit-size))
        {
            profit+=float(p[i]);
            size+=w[i];
            cout<<"Object "<<a[i]<<" is added"<<endl;
        }
        else if((w[i]>(limit-size))&&(size<limit))
        {
            int temp=(limit-size);
            float temp2 =(ep[i])*(float(temp));
            profit+=temp2;
            cout<<temp2<<" of object "<<a[i]<<" is added"<<endl;
            break;
        }
        i--;
    }
    cout<<"Maximum profit is: "<<profit;
}
int main()
{
	int n;
	cout<<"Enter number of items: ";
	cin>>n;
	int a[n],weight[n],price[n];
	for(int i=0;i<n;i++)
	{
		a[i]=i+1;
		cout<<"\nEnter the price of item "<<i+1<<": ";
		cin>>price[i];
		cout<<"Enter the weight of item "<<i+1<<": ";
		cin>>weight[i];
	}
	cout<<endl;
	int limit;
	cout<<"Enter the limit of Knapsack: ";
	cin>>limit;
	float each_price[n];
	for(int i=0;i<n;i++)
		each_price[i]=float(price[i])/float(weight[i]);
	sort(a,weight,price,each_price,n);
	knapsack(a,weight,price,each_price,n,limit);
	return 0;
}
