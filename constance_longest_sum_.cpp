#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 10050
using namespace std;
int p[N];
//·ÖÖÎ 
int solve(int start,int end,int &low,int &high)
{
	if(end-start==1)
		return 0; 
	int ans=0; 
	int fl=0,fr=0;
	int mid=(end-start)/2+start;
	int l=solve(start, mid,fl,fr);
	if(ans<l)
	{
		ans=l; low=fl; high=fr;
	}
	int r=solve(mid,end,fl,fr);
	if(ans<r)
	{
		ans=r; low=fl; high=fr;
	}
	
	int v=0,L=0,R=0;
	for(int i=mid-1;i>=start;i--)
		if(L<(v+p[i]))
		{
			L=(v+=p[i]);
			fl=i;
		}
	v=0;
	for(int i=mid;i<end;i++)
		if(R<(v+p[i]))
		{
			R=(v+=p[i]);
			fr=i;
		}
	if(ans<L+R)
		{
			ans=L+R;
			low=fl;
			high=fr;
		}
	return ans;
}
int main()
{
	#ifdef dyr
		freopen("input.txt","r",stdin);
	#endif
	int n;
	while(~scanf("%d",&n))
	{	
		int left,right;
		for(int i=1;i<=n;i++)
			scanf("%d",&p[i]);
 		int ans=solve(1,n+1,left,right);
 	//	printf("%d\n%d %d\n",ans,left,right);
 		for(int i=left;i<=right;i++)
		 	printf("%d ",p[i]); 
		 	printf("\n");
	}
	return 0;
 } 
 
 
