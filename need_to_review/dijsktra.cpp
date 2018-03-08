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
	visit[start]=1;//��startΪ�Ѿ��ҵ�����С·�� 
	//��start��ֱ��ĵ���Ϊ���
	int k=start;
	for(vector<int>::iterator it=p[start].begin();it!=p[start].end();it++ )
	{
		path[*it]=1;
	}
	//�����ҵ���vstart������̵ı���ӵ���̼����У�������
	for(int i=1;i<=vex;i++)
	{
		if(i!=start)//��ȥstart��
		{
			int min=INF;
			for(int j=1;j<=vex;j++)//�ӷ���̱���ѡ����start����ı� 
			{ 
				if(!visit[j]&&path[j]<min)
				{
					k=j;min=path[j];
				}
			}
			if(min==INF)
				return;
			visit[k]=true;//���Ϊ���·�� 
			for(vector<int>::iterator it=p[k].begin();it!=p[k].end();it++)
			{
				if(path[*it]>path[k])// �����·��,start
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
	 
	scanf("%d",&start);
	init();
	dijsktra();
	for(int i=1;i<=vex;i++)
		printf("%d ",path[i]);
	 return 0;
	 
 } 
