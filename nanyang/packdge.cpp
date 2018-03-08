#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 10050
using namespace std;
struct node
{
	int weight,value;
	//double s;
}p[N];
bool cmp( const node& x,const node& y)
{
	return x.value>y.value;
}
int main()
{
	int T;
	int n,m;//n个物品，m的背包容积
	//freopen("input.txt","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&p[i].value,&p[i].weight);
			//p[i].s=(double)p[i].value/(double)p[i].weight;
		}
		sort(p,p+n,cmp);
		//printf("\n");
	/*	for(int i=0;i<n;i++)
		{
			printf("s %d %d\n",p[i].value,p[i].weight);
		}*/
		int vl=0,pr=m;
		for(int i=0;i<n&&pr>0;i++)
		{
			
			if(pr>=p[i].weight)
			{
				pr-=p[i].weight;
				vl+=p[i].value*p[i].weight;
			//printf("1");
			}
			else 
			{
				vl+=p[i].value*pr;
				pr=-1;
			//printf("2");

			}
			//printf("p[%d] %d %d \n",i,pr,vl);
		}
		printf("%d\n",vl);
	}
	return 0;
}

