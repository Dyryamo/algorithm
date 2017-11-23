//二分图中，最大独立集的大小
                              =n-最小点覆盖
                              =n-最大匹配

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define N 10050
using namespace std;
int vex,arc;
vector<int>map[N];
int color[N];
int used[N];
int girl[N];
int cnt;
bool find(int x){
	for(vector<int>::iterator it=map[x].begin();it!=map[x].end();it++){
		if(!used[(*it)]){
			used[(*it)]=1;
			if(!girl[(*it)]||find(girl[(*it)])){
				girl[(*it)]=x;
				return true;
			}
		}
	}
	return false;
}
void match(){
	for(int i=1;i<=vex;i++){
		memset(used,0,sizeof(used));
		if(color[i]==1&&find(i)){
			cnt++;
		}
	}
}
bool BFS(int x){
	queue<int>q;
	q.push(x);
	while(!q.empty())
	{
		int f=q.front();q.pop();
		for(vector<int>::iterator it=map[f].begin();it!=map[f].end();it++){
			if(!color[(*it)]){
				q.push((*it));
				color[(*it)]=-color[f];
			}
			else if(color[(*it)]==color[f])
				return false;
		}
	}
	return true;
}
bool bycolor(){
	for(int i=1;i<=vex;i++) {
		if(!color[i])
		{
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
	int head,tail;
	while(~scanf("%d%d",&vex,&arc))
	{
		for(int i=0;i<arc;i++){
			scanf("%d%d",&head,&tail);
			map[head].push_back(tail);
			map[tail].push_back(head);
		}
		if(bycolor())
		{
			match();
			printf("%d\n",cnt);
			printf("%d\n",vex-cnt);
		}
		
	 } 
	return 0;
}

