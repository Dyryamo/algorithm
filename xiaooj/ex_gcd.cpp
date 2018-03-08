#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef int ll;
ll ex_gcd(ll a,ll b,ll& u,ll& v){
	if(b==0){
		u=1;v=0;
		return a;
	}
	else{
		ll tmp=ex_gcd(b,a%b,v,u);
		v=v-a/b*u;
//		u=v;
		return tmp;
	}
	
}
int main(){
	
	ll a,b,c,k;
	//freopen("input.txt","r",stdin);
//	while(scanf("%d%d%d%d",&a,&b,&c,&k)!=EOF){
	{
		scanf("%d%d%d%d",&a,&b,&c,&k);
		ll u,v;
		ll  tmp=ex_gcd(1ll<<k,c,u,v);
	//		printf("%d\n",tmp);
		if(  (b-a)%tmp ==0){
	//		printf("%d\n",v);
			ll sn=1ll<<k;
			v=(v*((b-a)/tmp));
			v=(v%(sn/tmp)+(sn/tmp))%(sn/tmp);
			printf("%d\n",v);
		}
		else {
			printf("forever\n");
		}
	}
	return 0;
}
