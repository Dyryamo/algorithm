#include <bits/stdc++.h>
#define N 100005
int main(){
	int n,m;
	int need[N],value[N];
	int dp[100005];
	memset(dp,0,sizeof(dp));
	scanf("%d%d",&n,&m);
	for(int i =0 ;i<n;i++){
		scanf("%d%d",&need[i],&value[i]);
	}
	for(int i = 0;i < n ;i++){
		for(int j = need[i];j<=m;j++){
			if(dp[j]<value[i]+dp[j-need[i]])
				dp[j] = value[i]+dp[j-need[i]];
		}
	}
	printf("%d\n",dp[m]);
	return 0;
}