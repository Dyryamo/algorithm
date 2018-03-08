#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define N 1050
using namespace std;
vector<int>map[N];
int color[N];
int vex,arc;
int head,tail;
int used[N];//标记 
int girl[N];
bool find(int x){
	for(vector<int>::iterator it=map[x].begin();it!=map[x].end();it++){
		if(!used[(*it)])
		{
			used[(*it)]=true;
			if(!girl[(*it)]||find(girl[(*it)])){
				girl[(*it)]=x;
				return true;
			}	 
		} 
	}
	return false;
}
bool BFS(int i){
	queue<int>qe;
	qe.push(i);
	while(!qe.empty()){
		int f=qe.front();
		qe.pop();
		for(vector<int>::iterator it = map[f].begin();it!=map[f].end();it++){
			if(!color[(*it)]){
				qe.push(*it);
				color[(*it)]=-color[f];
			} 
			else if(color[(*it)]==color[f])
				return false;
		}
	}
	return true;
}
bool isdiv(){//染色法判断是否是二分图
	for(int i=1;i<=vex;i++){
		if(!color[i]){
			color[i]=1;
			if(!BFS(i))
				return false;     
		}
	}
}
int main(){
	#ifdef dyr
		   freopen("input.txt","r",stdin);
	#endif
	int cnt;
	while(~scanf("%d%d",&vex,&arc)){
		cnt=0;
		memset(color,0,sizeof(color));
		memset(girl,0,sizeof(girl));//初始全部都没有女朋友 
		for(int i=1;i<=arc;i++){
			scanf("%d%d",&head,&tail);
			map[head].push_back(tail);
			map[tail].push_back(head);
		} 
		if(isdiv()){
			for(int i=1;i<=vex;i++)//为每一个人找女朋友 
			{
				memset(used,0,sizeof(used));
				if(color[i]==1&&find(i))
					cnt++;
					
			}
		}
		printf("%d\n",cnt);
		for(int i=1;i<=vex;i++){
			map[i].clear();
		}
	}
	return 0;
}

