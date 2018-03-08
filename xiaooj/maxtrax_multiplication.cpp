#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 1<<8
#define N 105
using namespace std;
int D[N][N];
int n;
int d[N];
void print()
{
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(i<=j)
				printf("%d ",D[i][j]);
			else printf("  ");
		}
		printf("\n");
	 } 
}
int fill()
{
	for(int i=1;i<=n;i++)
		D[i][i]=0;
		
	for(int dis=1;dis<n;dis++)
	{
		for(int i=1,j=dis+1;j<=n;i++,j++)//ÕÒi-j¶Î×îÐ¡Öµ 
		{
			D[i][j]=INF;
	
			for(int k=i;k<j;k++)
			{
				 int dtmp=D[i][k]+D[k+1][j]+d[i-1]*d[k]*d[j];
				 if(dtmp<D[i][j])
				 {
				 	D[i][j]=dtmp;
				  } 
			}
		}
	 } 

}
int main()
{
	#ifdef dyr
	//	freopen("input.txt","r",stdin);
	#endif
	scanf("%d",&n);
	for(int i=0;i<=n;i++)
	{
		scanf("%d",&d[i]);
	}
	fill();
	///print();
	printf("%d\n",D[1][n]);
	return 0; 
	
	
}

