#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 15
int p[N];
int f[15][15];
int db()
{
	int stop;
	p[0]=1;
	for(int i=1;i<=N;i++)
	{
		//printf("s");
		p[i]=p[i-1]*i;
		if(p[i]>=1000000)	
		{
			stop=i;
			break;
		}
	}
	return stop;

}		
bool judge(int n)
{
`
	for(int i=10;i>=1;i--)
	{
		judge(n-p[i]);
	}
}
int main()
{
	db();
	//db2();
	int n;
	int T;
	scanf("%d",&T);
	int flag;
	while(T--)
	{
		scanf("%d",&n);
		if(judge(n)==true)
			printf("Yes\n");
		else 	
			printf("No\n");
	}
	return 0;
}
