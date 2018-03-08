#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#define N 10050
using namespace std;
struct node 
{
	int start,end;
	void operator = (node& other)
	{
		this->start=other.start;
		this->end=other.end;
	}
}p[N];
int n;
void print()
{
	for(int i=0;i<n;i++)
	{
		printf("%d %d\n" ,p[i].start,p[i].end);
	}
}

bool cmp(const node x,const node y)
{
	return x.end<y.end;
}
int f()
{
	node M[N];
	sort(p,p+n,cmp);
	M[0]=p[0];
	int i=1,j=1;
	//print();
	while(i<n){//printf("i；%d j %d ",i,j);
		if(M[j-1].end<p[i].start)//不冲突
		{
			M[j++]=p[i];
		}
	i++;
	}
	return j;
}

int main()
{
	int T;
	freopen("input.txt","r",stdin);	
	scanf("%d",&T);
	while(T--)
	{
		//printf("%d",n);
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d%d",&p[i].start,&p[i].end);
		
		//print();
		printf("%d\n",f());
	}

}

