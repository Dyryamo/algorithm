#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#define N 10050
#include<set>
using namespace std;
int l[N];
int r[N];
int board[N<<1];
int lazy[N<<1];
set<int>visit;
void pushdown(int root){
	printf("pushdown");
	lazy[root*2]=lazy[root*2+1]=lazy[root];
	lazy[root]=-1;
}
void update(int root ,int L,int R,int l,int r,int val){//L,R是当前节点的区间,l,r是查找到区间
	printf("update%d",root);
	if(l<=L&&r>=R)
	{
		lazy[root]=val;//如果修改的区间大于当前节点的区间，则直接将当前节点的只修改为val
		return;
	}
	if(L==R)
		return ;
	int mid= L + (R-L)/2;
	if(lazy[root]!=-1){//被修改了还没向下传递
		pushdown(root);
	
	}
	if(mid >=r){//全在左边
		update(root*2,L,mid,l,r,val);
	}
	else if(mid<=l){
		update(root*2+1,mid,R,l,r,val);
	}
	else{
		update(root*2,L,mid,l,r,val);
		update (root*2+1,mid+1,L,l,r,val);
	}
}
int query(int l,int r,int root){
	printf("query%d",root);
	int cnt=0;
	if(lazy[root]!=-1)
	{
		if(visit.find(lazy[root])!=visit.end()){
			visit.insert(lazy[root]);
			cnt++;
		}
	}
	if(l==r)
		return 0;
	int mid = l + (r-l)/2;
	cnt+=query(root*2,l,mid);
	cnt+=query(root*2+1,mid+1,root);
	return cnt;
}
int main(){
	int T;
	int n;
	scanf("%d",&T);
	while(T--){
		memset(board,-1,sizeof(board));
		scanf("%d",&n);
		int k=0;
		for(int i=0;i<n ;i++){
			scanf("%d%d",&l[i],&r[i]);
			board[k++]=l[i];
			board[k++]=r[i];
		}
		sort(board,board+k);
		k=unique(board,board+k)-board;
		//离散化
		int m  = k;
		for(int i=0;i<m-1;i++){
			if(board[i]+1!=board[i+1]){
				board[k++]=board[i+1]-1;
			}
		}
		sort(board,board+k);
		for(int i=0;i<n;i++){
			int ls = lower_bound(board,board+k,l[i])-board;
			int rs= lower_bound(board,board+k,r[i])-board;
			update(1,1,k,ls,rs,i);
		}
		printf("%d\n",query(1,k,1));
	}
	return 0;
}

