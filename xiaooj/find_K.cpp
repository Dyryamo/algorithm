#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 10050 
using namespace std;
int n,p[N],k;
int partition(int low,int high)
{
	
	int x=rand()%(high-low+1)+low;//空穴 
	int pa=p[x];//主元
	while(low<high)
	{
		//从右向左找小于主元的数 
		while(low<high&&p[high]>pa)	high--;
		if(low<high)
		{
			p[x]=p[high];
			x=high;
		}
		while(low<high&&p[low]<=pa) low++;
		if(low<high)
		{
			p[x]=p[low];
			x=low;
		}
	 } 
	 p[x]=pa;
	 return x;
}
int findk(int k,int low ,int high)
{
	if(low>high)
		return -1;
	else 
	{
		int mid=partition(low,high);
		if(mid==k)	
			return mid;
		else if(mid>k)
			return findk(k,low,mid-1);
		else return findk(k,mid+1,high);
	}
}
int main()
{
	#ifdef dyr
		freopen("input.txt","r",stdin);
	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
	}
	scanf("%d",&k); 
	printf("%d\n",findk(k,1,n));
}
 
