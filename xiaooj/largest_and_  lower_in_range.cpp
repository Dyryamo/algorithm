//poj 3264
//线段树求区间最大最小距离
 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 70000
using namespace std;
int a[N];
struct node
{
	int left,right,min,max;
 }tree[N*2];
void build(int left,int right,int root){
	//printf("%d\n",root);
	tree[root].left=left;
	tree[root].right=right;
	if(left==right){
		tree[root].min=tree[root].max=a[left];
	}
	else {
		int mid=(left+right)>>1;
		//printf("%d-%d-%d\n",left,mid,right);
		build(left,mid,root*2);
		build(mid+1,right,root*2+1);
		tree[root].min=min(tree[root*2].min,tree[root*2+1].min);
		tree[root].max=max(tree[root*2].max,tree[root*2+1].max);
	}            
	
}
void equry(int &maxn,int &minn,int left,int right,int root)
{
	if(right<tree[root].left||left>tree[root].right)
		return ; 
	if(tree[root].left>=left&&tree[root].right<=right)
	{
		maxn=max(tree[root].max,maxn);
		minn=min(tree[root].min,minn);
	}
	else{
		int mid=(tree[root].left+tree[root].right)>>1;
		if(left>=mid+1){
			equry(maxn,minn,left,right,root*2+1);
		}
		else if(mid>=right){ 
			equry(maxn,minn,left,right,root*2);
		}
		else {
			equry(maxn,minn,left,mid,2*root);
			equry(maxn,minn,mid+1,right,2*root+1);
		}
		
	}
}
int main()
{
	int n,m;
	int max,min;
	int l,r;
	#ifdef 	dyr
		//freopen("input.txt","r",stdin);
	#endif 
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	} 
	build(1,n,1);
	for(int i=0;i<m;i++)
	{
		max=0;min=1<<16;
		scanf("%d%d",&l,&r);
		equry(max,min,l,r,1);
	//	printf("%d-%d-",max,min);
		printf("%d\n",max-min);
	}
/*	for(int i=1;i<=2*n+1;i++)
		printf(" node	%d-%d-%d-%d\n",tree[i].left,tree[i].right,tree[i].max,tree[i].min);*/ 
	return 0;
}





