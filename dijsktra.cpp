#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
const int N=10050;
const int INF=1<<9; 
using namespace std;

vector<int>p[N];
	int head,tail;
	int vex,arc;
	int start,end;
	int path[N];
	bool visit[N]; 
void dijsktra()
{
	path[start]=INF;
	visit[start]=1;//设start为已经找到了最小路径 
	//将start能直达的点设为最短
	int k=start;
	for(vector<int>::iterator it=p[start].begin();it!=p[start].end();it++ )
	{
		path[*it]=1;
	}
	//从中找到从vstart出发最短的边添加到最短集合中，修正；
	for(int i=1;i<=vex;i++)
	{
		if(i!=start)//出去start点
		{
			int min=INF;
			for(int j=1;j<=vex;j++)//从非最短边中选出离start最近的边 
			{ 
				if(!visit[j]&&path[j]<min)
				{
					k=j;min=path[j];
				}
			//	printf("%d ",k);
			}
			if(min==INF)
				return;
			visit[k]=true;//标记为最短路径 
			for(vector<int>::iterator it=p[k].begin();it!=p[k].end();it++)
			{
				if(path[*it]>path[k]+1)// 非最短路径,start
				{
				 	path[*it]=path[k]+1;
				}  
			} 
		} 
	
}
}
void init()
{
	for(int i=1;i<=vex;i++)
	{
		path[i]=INF;	
	}
	memset(visit,0,sizeof(visit));
}
int  main()
{
	#ifdef dyr
		freopen("input.txt","r",stdin);
	#endif
	scanf("%d%d",&vex,&arc);
	for(int i=1;i<=arc;i++)
	{
		scanf("%d%d",&tail,&head);
		p[tail].push_back(head);
		p[head].push_back(tail);
	 } 
	 scanf("%d%d",&start,&end);
	 init();
	 /*for(int i=1;i<=vex;i++)
	 {
	 	for(vector<int>::iterator it=p[i].begin();it!=p[i].end();it++)
	 		printf("%d:%d ",i,*it);
	 		printf("\n");
	 }*/
	 dijsktra();
	 /*for(int i=1;i<=end;i++)
	 {
	 	printf("%d ",path[i]);
	  } */
//	 printf("%d\n",path[end-1]);
	if(path[end]==INF)
		printf("0\n");
	else
		printf("%d\n",path[end]-1);
	 return 0;
	 
 } 
