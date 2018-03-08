#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 105
using namespace std;
int max(int x,int y){
	return x>y?x:y;
}
int main(){
	int n,m,h;
	int w[N],v[N];
	int dp[N];
	while((scanf("%d",&n),n!=0)){
		scanf("%d%d",&m,&h);
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++){
			scanf("%d%d",&w[i],&v[i]);
		}
		if(h==0){
			for(int i=0;i<n;i++){
				for(int j=m;j>=w[i];j--){
					dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
				}
			}
			printf("%d\n",dp[m]);
		}
		else {
            int maxs=0;
			for(int k=0;k<n;k++){
            	for(int i=0;i<n;i++){
                    if(k==i)	continue;
                    for(int j=m+h-1;j>=w[i];j--){
                        dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
                    }
                }    
                maxs=max(maxs,dp[m+h-1]+v[k]);
            }
			
			printf("%d\n",maxs);
		}
	}
	return 0;
}