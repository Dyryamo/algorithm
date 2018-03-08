#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int  f(string s){
	
	int ans=0;
	int len =s.length();
	if(len < 4)	{
		for(int i=0;i<len;i++)
			ans=ans*10+s[i]-'0';
			return ans;
	}
	int j=len-1-4;
	for(int i=j;i<len;i++)
		ans=ans*10+s[i]-'0';
	return ans;
}
int main(){
	int T;
	scanf("%d",&T);
	string s;
	int x,k;
	while(T--){
		cin>>s>>k;
		x=f(s);
		printf("x--------- %d\n",x);
		int n=1,i;
		for( i=x;i>=0;i-=2){
			if((n)%10==k){
				printf("%d\n",i);
				break;
			}
			n*=i;
		}
		if(i<0){
			printf("-1\n");
		}
	}
	return 0;
}
