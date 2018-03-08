//
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue> 
#include<algorithm>
#define N 10050
using namespace std;
vector<int>map[N];
int match[N];
	int vex,arc;
bool BFS(int i){
	queue<int>que;
	que.push(i);
	while(!que.empty()){
		int first=que.front(); que.pop();
	//	printf("%d-¡·",first);
		for(vector<int>::iterator it=map[first].begin();it!=map[first].end();it++){
			if(!match[(*it)])//Î´±»È¾É« 
			{
				que.push((*it));
				match[(*it)]=-match[first];
			//	printf("%d ",(*it));
			}	
			else if(match[(*it)]==match[first])
				return false; 
		}
	//	printf("\n");
	}
	return true;
}
bool judge(){
	for(int i=1;i<=vex;i++){
		if(!match[i]){
			match[i]=1;
			if(!BFS(i))
				return false;
		}
		//printf("1n");
	}
	return true;
}
int main()
{
	#ifdef	dyr
		freopen("input.txt","r",stdin);
	#endif
	int T;
	int head,tail; 
	scanf("%d",&T);
	while(T--){
		memset(match,0,sizeof(match));
		
		scanf("%d%d",&vex,&arc);	
		
		for(int i=1;i<=vex;i++){
			map[i].clear();
		}
		for(int i=0;i<arc;i++){
			scanf("%d%d",&head,&tail);
			map[head].push_back(tail);
			map[tail].push_back(head);
		}
	/*	for(int i=1;i<=vex;i++){
			printf("%d->",i);
			for(vector<int>::iterator it=map[i].begin();it!=map[i].end();it++)
				printf("%d ",*it);
			printf("\n");
		}*/
		if(!judge())
			printf("Wrong\n");
		else 
			printf("Correct\n");
	}
	return 0; 
}
