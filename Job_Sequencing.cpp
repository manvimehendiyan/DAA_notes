#include<iostream>
#include<algorithm>
using namespace std;
struct job
{
	int job_id;
	int deadline;
	int profit;
	void input()
	{
		cout<<"Enter the Deadline of job: ";
		cin>>deadline;
		cout<<"Enter the profit: ";
		cin>>profit;
	}
};
bool comparison(job a, job b)
{
	return (a.profit > b.profit);
}
void job_sched(job a[],int n)
{
	sort(a,a+n,comparison);
	int result[n];
	int slot[n];
	for(int i=0;i<n;i++)
		slot[i]=0;
	for(int i=0;i<n;i++)
	{
		for(int j=min(n,a[i].deadline)-1;j>=0;j--)
		if(slot[j]==0)
		{
			result[j]=i;
			slot[j]=1;
			break;
		}
	}
	for(int i=0;i<n;i++)
		if(slot[i]==1)
			cout<<" J"<<a[result[i]].job_id+1<<" ";
}
int main()
{
	int n;
	cout<<"Enter the total number of jobs: ";
	cin>>n;
	job a[n];
	for(char i=0;i<n;i++)
		a[i].job_id=i;
	for(int i=0;i<n;i++)
	{
		cout<<"Job "<<i+1<<":"<<endl;
		a[i].input();
		cout<<endl;
	}
	cout<<"Max Profit sequence of jobs: "<<endl;
	job_sched(a,n);
	return 0;
}
