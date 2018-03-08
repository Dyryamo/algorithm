#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 10050
using namespace std;
int n;
int p[N];
int cnt;
int merge(int start,int mid,int end)
{
	int pp=start,q=mid,i=start;
	int T[N];
	//if(end>=start)
	{
		while(pp<mid||q<end)
		{
			if(q>=end||(pp<mid&&p[pp]<=p[q]))
				T[i++]=p[pp++];
			else
			{
				T[i++]=p[q++];
				cnt+=(mid-pp);
			}
			 
		}
		for(int i=start;i<end;i++)
			p[i]=T[i];
	 } 
	
	return cnt;
	
}
int mergesort(int start,int end)
{
	if(end-start>1)
	{
		int mid=(start+end)/2;
		mergesort(start,mid);
		mergesort(mid,end);
		return merge(start,mid,end);
	}
	return -1;
}
int main() 
{

		scanf("%d",&n);
		cnt=0;
		for(int i=0;i<n;i++)
			scanf("%d",&p[i]);	
		printf("%d\n",mergesort(0,n));
	
	return 0;
}
