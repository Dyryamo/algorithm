#include <bits/stdc++.h>
using namespace std;

long long dp[20][20];//dp[i][j] i representative length,j representative bit max


long long init(){
	dp[0][0]=1;
	for(int i = 1;i<=7;i++){
		for(int j=0;j<=9;j++){
			if(j == 4)
					continue;
			for(int k = 0;k<=9;k++){
				if((j==6&&k==2)||k==4)
						continue;
				dp[i][j]+=dp[i-1][k];
			}
		}
	}
	return 0; 
}
long long solve(long long m){
	int bit[20];
	int len = 1;
	while(m){
		bit[len++] = m%10;
		m/=10; 
	}
	long long ans = 0;
	for(int i = len ; i>=1 ; i--){
		for(int j=0;j<bit[i];j++){
			if(bit[i+1]==6&&bit[i]==2)
					continue;
			ans += dp[i][j];
		}
	}
	return ans;
}
int dug(){
	for(int i = 1; i<=7;i++ ){
		for(int j = 0;j<=9;j++){
			printf("%lld",dp[i][j]);
		}
		printf("\n");
	}
}
int main(){

	long long n , m;
	init();
	//dug();
	while(scanf("%lld%lld",&n,&m),n||m){
		printf("%lld\n",solve(m)-solve(n-1) );
	}
	return 0 ;
}