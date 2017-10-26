#include<iostream>
#include<cstdio> 
#include<cstring>
#include<algorithm>
#define N 15
//m[i][j]��i-j�εĳ˻�
//dp[i][j]��ʾ����Ϊi��j���˺ŵ�ֵ
/*
f(m,k)��ʾm�������֣�����k���˺ŵ������
�������һ��Ϊp������
��f(m,k)=f(p,k-1)*l(p,m-p);
ö��p�ĳ��ȣ���ö�ٳ˺ŵ�λ�� 
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
		for(int i=1;i<=n;i++)//ö�ٳ���
		{
			for(int j=0;j<n;j++)//ö�ٳ˺ŵ�λ�ã���ö�ٷֶ�1-n�� 
			{
				if(j==0)	
					dp[i][j]=m[1][i];
				else 
				{
					for(int k=1;k<n;k++)//ö�ٳ˺ŵ�λ�� 
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
