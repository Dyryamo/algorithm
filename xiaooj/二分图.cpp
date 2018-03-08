//染色法判断是否是二分图
#include<cstring>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#define N 10050
using namespace std;
vector<int>map[N];
bool used[N];
int colo[N];
int n , m;
int girl[N];
bool findgirlfriend(int x){
	for(vector<int>::iterator it = map[x].begin();it!=map[x].end();it++){
		if(!used[*it]){
			used[*it]=true;
			if(girl[*it]==-1||findgirlfriend(girl[*it])){//女生没有男朋友或者可以换一个男朋友
				
				girl[*it]=x;//成功上位
				return true;
			}
		}
	}
	return false;
}
int match(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		memset(used,0,sizeof(used));
		if(colo[i]==1&&findgirlfriend(i)){//是男的切能找到女朋友
			cnt++;
		}
	}
	return cnt;
}
bool BFS(int x){
	queue<int>q;
	q.push(x);
	while(!q.empty()){
		int f=q.front();
		q.pop();
		for(vector<int>::iterator it = map[f].begin();it!=map[f].end();it++){
			if(colo[*it]==colo[f])
				return false;
			else if(colo[*it]==0)
			{	
				colo[*it]=-colo[f];
				q.push(*it);
			}
		}
	}
	return true;
}
int color(){
	for(int i=1;i<=n;i++){
		if(colo[i]==0)//如果该节点还没染色则上1色
		{
			colo[i]=1;
			if(!BFS(i))
				return false;
		}
	}
	return true;
}
int main(){
	int head,tail;
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=0;i<m;i++){
			scanf("%d%d",&head,&tail);
			map[head].push_back(tail);
			map[tail].push_back(head);
		}
	//	if(color(){
	//	int tmp=color();
		if(color()){
			printf("%d",match());
		}
		else {
			printf("No");
		}
	}

}
