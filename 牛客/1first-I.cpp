#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
bool in[10];
void f(int x){
	while(x!=0){
		in[x%10]=true;
		x/=10;
	}
}
bool judge(int x){
	while(x!=0){
		if(in[x%10]==true){
			return false;
		}
		x/=10;
	}
	return true;
}
int main(){
	int T;
	int a,b;
	scanf("%d",&T);
	while(T--){
		int cnt=0;
		memset(in,0,sizeof(in));
		scanf("%d%d",&a,&b);
		f(a);
		f(b);/*
		for(int i=0;i<9;i++){
			printf("%d\n",in[i]);
		}*/
		for(int i=1;i<=1000;i++){
			if(i%a!=0&&i%b!=0&&judge(i)){
				//printf("i--------%d\n",i );
				cnt++;
			}
		}	
	//	printf("1");
		printf("%d\n",cnt);
	}
	
	return 0;
}