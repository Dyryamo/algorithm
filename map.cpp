#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int p[105][105];
int main()
{
	int n;
	scanf("%d",&n);
	memset(p,0,sizeof(p));
	for(int i=1;i<=n;i++)
		p[1][i]=1; 
	for(int i=2;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			p[i][j]=p[i-1][j]+p[i][j-1];	
		} 
	}
	printf("%d\n",p[n][n]);
	return 0;
}



