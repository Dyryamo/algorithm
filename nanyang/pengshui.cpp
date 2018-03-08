#include <iostream>
#include<cstdio>
#include<stdlib.h>
#include<algorithm>
#include<cmath>
#define N 1050
using namespace std;
double p[N];
int n,h,w;//喷水口的数量，草坪高，草坪宽
bool cmp(const double x,const double y)
{
	return x>y;
}
int f()
{
	int cnt=0;
	double x=20;
	sort(p,p+n,cmp);/*
	for(int i=0;i<n;i++)
		printf("%lf ",p[i]);*/
	for(int i=0;i<n;i++)
	{
		//printf("%lf ",x);
		if(p[i]>h)
		{
			x-=2*sqrt(p[i]*p[i]-1);
			cnt++;	
			if(x<=0)	break;
		}
		else return 0;
	}
	//printf("cnt %d\n",cnt);
	return cnt;
}
int main()
{
	int T;
	freopen("input.txt","r",stdin);
	scanf("%d",&T);
	
	while(T--)
	{
	//printf("case :%d    ",T);
	//
	scanf("%d%d",&w,&h);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%lf",&p[i]);
	printf("%d\n",f());	
	}
	return 0;
}
