#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 105
#define INF 1<<8 
using namespace std;
	int map[N][N];
	int path[N][N];
	int dp[N][N];
	int n,m;
void fdp()
{
	for(int j=m-1;j>=0;j--)
	{
		for(int i=0;i<n;i++)
		{
			dp[i][j]=INF;
			if(j==m-1)	
				dp[i][j]=map[i][j];
			else 
			{
				int s[3]={i-1,i+1,i};
				if((i-1)<0)
					s[0]=n-1;
				if(i+1>n-1)
					s[1]=0;
				sort(s,s+3);
				
				for(int z=0;z<3;z++)
				{
					int v=dp[s[z]][j+1]+map[i][j];
					if(v<dp[i][j])
					{
						dp[i][j]=v;
						path[i][j]=s[z];
					}
				}
				
				
			}
				
		}
	}	
}
void print()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			printf("%d ",dp[i][j]);
			printf("\n");
	}
	printf("\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			printf("%d ",path[i][j]);
			printf("\n");
	}
}
void printpath()
{
	int ans=1<<8;
	int first;
	for(int i=0;i<n;i++ )
	{
		if(ans>dp[i][0])
		{
			ans=dp[i][0];
			first=i;
		}
			
	}
	
	for(int j=0,i=first;j<m;i=path[i][j++])
	{
		if(j==m-1)
			printf("%d",i+1);
		else 
			printf("%d ",i+1);
	}
	printf("\n");
	printf("%d\n",ans);
}
int main()
{
	#ifdef dyr
		freopen("input.txt","r",stdin);
	#endif
	while(~scanf("%d%d",&n,&m))
	{
		for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&map[i][j]);
	fdp(); 
	//print();
 	printpath();
	}
	
 	return 0;
} 
