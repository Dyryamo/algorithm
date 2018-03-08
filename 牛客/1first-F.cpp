#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int a,b,c;
bool judge(int left,int dist,int leftc){
	if(dist >= b){
		return true;
	}
	else if(leftc<=0){
		return false;
	}
	else 
		if(80-6*a<=0){
			return judge(80,(80-7*a)/a,leftc-1);
		}
		else
			return judge(80,(80-6*a)/a,leftc-1);
}
int main(){
	int T;
	scanf("%d",&T);
	
	while(T--){
		scanf("%d%d%d",&a,&b,&c);
		if(judge(100,(100-6*a)/a,c-1)){
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
}