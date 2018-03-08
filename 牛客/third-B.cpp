#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define N  100050
#define LL long long
using namespace std;
LL M[N],a[N];
LL n ;
LL ex_gcd(LL a,LL b,LL &u,LL &v){
	if(b==0){
		u=1;v=0;
		return a;
	}
	else {
		LL tmp=ex_gcd(b,a%b,v,u);
		v=v-a/b*u;
		return tmp;
	}
}
LL inv(LL x,LL y){
	LL u, v; 
	LL t=ex_gcd(x,y,u,v);
	if(t!=1)
		return -1;
	return (u%y+y)%y;
} 
LL solve(){
	LL firsa=a[0],firsm=M[0];
	LL u,v;
	for(LL i=1;i<n;i++){
		LL tmp=ex_gcd(firsm,M[i],u,v);//u*m1-v*m2=a2-a1;
		if((a[i]-firsa)%tmp){//只有a2-a1|gcd()==0才有解  
			return -1;
		}
	
		LL c=a[i]-firsa;
		c=((c%M[i])+M[i])%M[i];
		c/=tmp;	
	
		LL in=inv(firsm/tmp,M[i]/tmp);
		if(in==-1)
			return false;
		c*=in;
		c=((c%(M[i]/tmp))+(M[i]/tmp))%(M[i]/tmp);
		c=c*firsm;
		c+=firsa;
	
		LL lcm=(firsm*M[i])/tmp;
		firsa=((c)%lcm+lcm)%(lcm);
		firsm=firsm*M[i]/tmp;
		
	} 
	return (firsa%firsm+firsm)%firsm; 
}
int main(){
	

		while(~scanf("%lld",&n)) {
		
		for(LL i=0;i<n;i++)
			scanf("%lld%lld",&M[i],&a[i]);		
		printf("%lld\n",solve());	
		}

	return 0;

}

