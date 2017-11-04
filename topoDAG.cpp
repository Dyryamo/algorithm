#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#define N 105
using namespace std;
int map[N][N];
int indegree[N];
int early[N];
int late[N];
int path[N];
int dist[N][N];
int vex, arc;
queue<int>q;
queue<int>topo;	
queue<int>rev_topo;
 int k=0;
void FindID()
{
	memset(indegree,0,sizeof(indegree));
	for(int i=1;i<=vex;i++){
		for(int j=1;j<=vex;j++){
			if(map[i][j]!=-1){//有边 
				indegree[j]++; 
			}
		 } 
	}
 } 
bool toposort()
{
	FindID();
	//memset(less,0,sizeof(less));
	memset(early,0,sizeof(early));
	int fr,count=0;
	for(int i=1;i<=vex;i++)
		if(!indegree[i])
			q.push(i);
	while(!q.empty()) 
	{
		fr=q.front();
		q.pop();
		topo.push(fr);
		//printf("%d--",fr); 
		count++;
		for(int i=1;i<=vex;i++)
		{
			if(map[fr][i]!=-1)
			{
				indegree[i]--;
				if(!indegree[i])
					q.push(i);
				if(early[fr]+map[fr][i]>early[i])
					early[i]=early[fr]+map[fr][i];
			}
		}
	}
	if(count<vex)
		return false;
	return true;
}
void criticalpath()//求关键路径，求最迟时间 
{
	int fr;
	stack<int>s;
	 while(!topo.empty()){//求得逆拓扑续 
		s.push(topo.front()); 
		topo.pop();
	}
	while(!s.empty()){
		rev_topo.push(s.top());
		s.pop();
	}
	for(int i=1;i<=vex;i++){
		late[i]=early[i];//初始为最早时间 
	} 
	while(!rev_topo.empty())
	{
		fr=rev_topo.front();
		rev_topo.pop();
		for(int i=2;i<=vex;i++)
		{
			if(map[i][fr]!=-1)
				if(late[i]<late[fr]-map[i][fr])
				{
					late[i]=late[fr]-map[i][fr];
					
				}
		 } 
	 } 
	
	 for(int i=1;i<=vex;i++)
	 {
	 	if(late[i]==early[i])
	 		path[k++]=i;
	  } 
}
void floyed()
{

	for(int i=1;i<=vex;i++){
		for(int j=1;j<=vex;j++)
			dist[i][j]=1<<15;
	}
	for(int i=1;i<=vex;i++){
		for(int j=1;j<=vex;j++)
			if(map[i][j]!=-1)
			{
				dist[i][j]=map[i][j];
			}
	}
	for(int k=1;k<=vex;k++){
		for(int i=1;i<=vex;i++){
			for(int j=1;j<=vex;j++){
				if(dist[i][k]+dist[k][j]<dist[i][j])
					dist[i][j]=dist[i][k]+dist[k][j];
			}
		}	
	}
	
	
	
	
	

	
		
	
	
}
int main()
{
	#ifdef dyr
		freopen("input.txt","r",stdin);
	#endif
	int ans; 
	int tail,head,weight;
	scanf("%d%d",&vex,&arc);
	memset(map,-1,sizeof(map));
	for(int i=1;i<=arc;i++)
	{
		scanf("%d%d%d",&tail,&head,&weight);
		map[tail][head]=weight;
	}
	floyed();
	if(toposort()){
		criticalpath();
		printf("%d\n",dist[1][vex]);
		printf("%d\n",early[vex]);
	}
	else {
		printf("%d\n",dist[1][vex]);
		printf("Never\n");
	}
	
}
