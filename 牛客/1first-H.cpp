#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 10050
using namespace std;
int main(){

	int n,T;
	int p[N];
	scanf("%d",&T);
	p[1]=1;p[2]=2;p[3]=3;
	for(int i=3;i<=80;i++){
		p[i]=p[i-1]+p[i-2];
	}
	while(T--){
		scanf("%d",&n);
		printf("%d\n",p[n]);
	}
	return 0;
}