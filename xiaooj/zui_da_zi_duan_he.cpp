#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 10050 
using namespace std;
int n;
int p[N]; 
int maxsum(int low,int high)
{
	//printf("1");
	if(high-low==1)
		return p[low];
	int  m=low+(high-low)/2;
	int maxs=max(maxsum(low,m),maxsum(m,high));
	int v,l,r;
	v=0;l=p[m-1];
	for(int i=m-1;i>=low;i--)
		l=max(l,v+=p[i]);
	v=0;r=p[m];
	for(int i=m;i<high;i++)
		r=max(r,v+=p[i]);
	return max(maxs,l+r); 
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
	 printf("%d",maxsum(1,n+1));
	
	 return 0;
 } 
