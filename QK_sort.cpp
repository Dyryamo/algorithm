#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stdlib.h>
#define N 10050
//快排，从小往打派 
using namespace std;
	int n;
	int p[N];
int partition(int p[],int low ,int high)
{
	int x=rand()%(high-low+1)+low;
	int pa=p[x];//选取主元
	int left=low,right=high; 
	while(left<right)
	{
		//先从右往左找 
		while(left<right&&pa<p[right])	right--;//找到比主元小的元素
		if(left<high)	
		{
			p[x]=p[right];
			x=right;
		 } 
		while(left<right&&pa>=p[left]) left++;
		if(left<high)
		{
			p[x]=p[left];
			x=left;
		}
	}
	p[x]=pa;
	return x;
}
void QK_sort(int low,int high)
{
	int mid; 
	if(low>=high)
		return;
	else 
	{
		mid=partition(p,low,high);
		QK_sort(low,mid-1);
		QK_sort(mid+1,high);
		return;
	}
}
int main()
{
	#ifdef dyr
		freopen("input.txt","r",stdin);
	#endif
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
	}
	
	for(int i=0;i<n;i++)
		printf("%d ",p[i]);
		printf("\n");
	QK_sort(0,n-1);
	for(int i=0;i<n;i++)
		printf("%d ",p[i]);
		return 0;
 } 
 
 
