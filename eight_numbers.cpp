#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
struct node
{
	int p[3][3];
	int circle;
	void operator=(node& other)
	{
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				p[i][j]=other.p[i][j];
				circle=other.circle;
	 } 
	 void locate0(int &m,int &n)
	 {
	 	for(int i=0;i<3;i++)
	 		for(int j=0;j<3;j++)
	 			if(p[i][j]==0)
	 			{
	 				m=i;n=j;
	 				break;
				 }
	 				
	} 
};
node start;
node end={1,2,3,8,0,4,7,6,5};
queue<node>status;
set<long long>estatus;
int dx[4]={-1,0,1,0}; 
int dy[4]={0,-1,0,1};
long long tran_num(node& n )
{
	long long  num=0;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
			num=num*10+n.p[i][j];
	}
	return num;
} 
bool judge(node &s)
{
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(s.p[i][j]!=end.p[i][j])
				 return false;
	return true;
}
int BFS()
{
	int front=0;
	node temp;
	while(!status.empty())
	{
		//printf("1");
		temp=status.front();
		status.pop();
		{
			int x1,y1;
			temp.locate0(x1,y1);
			for(int i=0;i<4;i++)
			{
				//printf("2");
				node s=temp;
				s.circle++;
				if(x1+dx[i]>=0&&x1+dx[i]<=2&&y1+dy[i]>=0&&y1+dy[i]<=2)
					swap(s.p[x1][y1],s.p[x1+dx[i]][y1+dy[i]]);
				if(judge(s))//ÊÇ·ñÕÒµ½ÖÕ½á×´Ì¬ 
					return s.circle;
				
				long long tr=tran_num(s);
				//printf("%lld ",tr); 
				if(estatus.find(tr)==estatus.end())
				{
					status.push(s);
					estatus.insert(tr);
				}
			}
		}	
	} 
	return -1;
}
int main()
{
	#ifdef dyr
		freopen("input.txt","r",stdin);
	#endif 
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
				scanf("%d",&start.p[i][j]);
		 } 
		 status.push(start);
		printf("%d",BFS()); 
}
