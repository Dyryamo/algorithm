#include<iostream>
#include<cstdio> 
#include<cstring>
#include<algorithm>
#define N 15
//m[i][j]是i-j段的乘积
//dp[i][j]表示长度为i，j个乘号的值
/*
f(m,k)表示m长的数字，插入k个乘号的最大结果
假设最后一段为p个数字
则f(m,k)=f(p,k-1)*l(p,m-p);
枚举p的长度，即枚举乘号的位置 
*/ 
using namespace std;
int num[N];
int m[N][N];
int dp[N][N];
int n,divs;
void init()
{
	for(int i=1;i<=n;i++)
	{
		m[i][i]=num[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			m[i][j]=m[i][j-1]*10+num[j];
		}
	}
}
int main()
{

	#ifdef dyr
		freopen("input.txt","r",stdin);
	#endif
	while(~scanf("%d%d\n",&n,&divs))
	{
	
		for(int i=1;i<=n;i++)
		{
			char c;
			scanf("%c",&c);
			num[i]=c-'0';	
		}
		init();
		for(int i=1;i<=n;i++)//枚举长度
		{
			for(int j=0;j<n;j++)//枚举乘号的位置，即枚举分段1-n段 
			{
				if(j==0)	
					dp[i][j]=m[1][i];
				else 
				{
					for(int k=1;k<n;k++)//枚举乘号的位置 
					{
						dp[i][j]=max(dp[i][j],dp[k][j-1]*m[k+1][i]); 
					}
				 } 
			 } 
		} 
	printf("%d\n",dp[n][divs-1]);
	}
	return 0;
}
